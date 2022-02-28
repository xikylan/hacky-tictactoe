#include <iostream>
#include <cctype>

#define SIZE 3

void print_board(char (&board)[SIZE][SIZE]);
int mark_board(int turn, int choice, char (&board)[SIZE][SIZE]);
bool is_board_filled(char (&board)[SIZE][SIZE]);
char has_winner(char (&board)[SIZE][SIZE]);
bool is_available(int choice, char (&board)[SIZE][SIZE]);

int main()
{
    char board[SIZE][SIZE] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };
    
    int turn = 0;

    while (1)
    {
        print_board(board);
        if (is_board_filled(board)) 
        {
            std::cout << "Board filled! The end" << std::endl;
            return 0;
        }

        // check victories
        char winner = has_winner(board);
        if (winner != '0')
        {
            std::cout << winner << " victory!" << std::endl;
            return 0;
        }
        
        int choice;
        std::cin >> choice;


        // check if spot is available
        while (!is_available(choice, board) || choice < 0 && choice > 10)
        {
            std::cout << "Not valid" << '\n';
            print_board(board);
            std::cin >> choice;
        }

        // traverse to nth position
        turn = mark_board(turn, choice, board);
    }
}

bool is_available(int choice, char (&board)[SIZE][SIZE])
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            count++;
            if (count == choice && !std::isdigit(board[i][j])) 
            {
                return false;
            }
        }
    }
    return true;
}

char has_winner(char (&board)[SIZE][SIZE])
{
    // check horizontal victory
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // check vertical victory
    for (int j = 0; j < SIZE; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            return board[0][j];
        }
    }

    // check diagonal victory
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return '0';
}

bool is_board_filled(char (&board)[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (std::isdigit(board[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

int mark_board(int turn, int choice, char (&board)[SIZE][SIZE])
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            count++;
            if (count == choice)
            {
                if (turn == 0) 
                {
                    board[i][j] = 'x';
                    turn = 1;
                }
                else if (turn == 1)
                {
                    board[i][j] = 'o';
                    turn = 0;
                }
            }
        }
    }
    return turn;
}

void print_board(char (&board)[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << ' '<< board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


