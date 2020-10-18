#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentmarker;
int currentplayer;
void drawboard()
{
cout<<" "<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<endl;
cout<<" -----\n";
cout<<" "<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<endl;
cout<<" -----\n";
cout<<" "<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<endl;
cout<<" -----\n";
}
bool placemarker(int slot)
{
    int row,col;
    row=(slot/3);
    if(slot%3==0)
    {
        row=row-1;
        col=2;
    }
    else
    {
        col=(slot%3)-1;

    }
    if(board[row][col]!='x'&&board[row][col]!='o')
    {
       board[row][col] =currentmarker;
       return true;
    }
    else
    {
        return false;
    }
}
int winner()
{
    for(int i=0;i<3;i++)
    {
    if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]) return currentplayer;
    if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]) return currentplayer;
    }

    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]) return currentplayer;
    if (board[0][2]==board[1][1]&&board[1][1]==board[2][0]) return currentplayer;
    return 0;
}
void swap_player_and_marker()
{
    if (currentmarker=='x') currentmarker='o' ;
    else currentmarker='x';
    if (currentplayer==1) currentplayer=2;
    else currentplayer=1;
}
void game()
{
    cout<<"player one choose ur marker";
    char marker_p1;
    cin>>marker_p1;
    currentplayer=1;
    currentmarker=marker_p1;

     drawboard();
     int playerwon;
     for(int i=0;i<9/2;i++)
     {
         cout<<"its player"<<currentplayer;
         cout<<"its turn enter your slot";
         int slot;
         cin>>slot;
         if(slot<1&&slot>9)
         {
             cout<<"invalid slot";
             i--;
             continue;
         }
         if(!placemarker(slot))
         {
             cout<<"place is occupied try another";
             i--;
             continue;
         }
         drawboard();
         playerwon=winner();
         swap_player_and_marker();
     if (playerwon==1) {cout<<"player one won! congratulation";break;}
     if (playerwon==2) {cout<<"player two won! congratulation";break;}




     }
     if (playerwon==0) cout<<"its a tie game";
}
int main()
{
    game();
    srand(time(NULL));
    cout<<(rand()%(10-1+1))+1;

return 0;
}
