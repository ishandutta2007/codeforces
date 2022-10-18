#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n,m;
    
    cin>>n>>m;
    
    bool**pol=new bool*[n+4];
    
    for(int i=0;i<n+4;i++)
    {
    pol[i]=new bool[n+4];
    for(int j=0;j<n+4;j++)
    pol[i][j]=false;
    }
    
    for(int i=0;i<m;i++)
    {
            int x,y;
            
            cin>>x>>y;
            
            pol[x+1][y+1]=true;
            
            bool UpLeft= pol[x+1][y+1] && pol[x+1][y+2] && pol[x+1][y+3] && pol[x+2][y+1] && pol[x+2][y+2] && pol[x+2][y+3] && pol[x+3][y+1] && pol[x+3][y+2] && pol[x+3][y+3];
            bool Up= pol[x+1][y] && pol[x+1][y+1] && pol[x+1][y+2] && pol[x+2][y] && pol[x+2][y+1] && pol[x+2][y+2] && pol[x+3][y] && pol[x+3][y+1] && pol[x+3][y+2] ;
            bool UpRight= pol[x+1][y-1] && pol[x+1][y] && pol[x+1][y+1] && pol[x+2][y-1] && pol[x+2][y] && pol[x+2][y+1] && pol[x+3][y-1] && pol[x+3][y] && pol[x+3][y+1] ;
            bool Left= pol[x][y+1] && pol[x][y+2] && pol[x][y+3] && pol[x+1][y+1] && pol[x+1][y+2] && pol[x+1][y+3] && pol[x+2][y+1] && pol[x+2][y+2] && pol[x+2][y+3] ;
            bool Middle= pol[x][y] && pol[x][y+1] && pol[x][y+2] && pol[x+1][y] && pol[x+1][y+1] && pol[x+1][y+2] && pol[x+2][y] && pol[x+2][y+1] && pol[x+2][y+2] ;
            bool Right= pol[x][y-1] && pol[x][y] && pol[x][y+1] && pol[x+1][y-1] && pol[x+1][y] && pol[x+1][y+1] && pol[x+2][y-1] && pol[x+2][y] && pol[x+2][y+1] ;
            bool BottomLeft= pol[x-1][y+1] && pol[x-1][y+2] && pol[x-1][y+3] && pol[x][y+1] && pol[x][y+2] && pol[x][y+3] && pol[x+1][y+1] && pol[x+1][y+2] && pol[x+1][y+3] ;
            bool Bottom= pol[x-1][y] && pol[x-1][y+1] && pol[x-1][y+2] && pol[x][y] && pol[x][y+1] && pol[x][y+2] && pol[x+1][y] && pol[x+1][y+1] && pol[x+1][y+2] ;
            bool BottomRight= pol[x-1][y-1] && pol[x-1][y] && pol[x-1][y+1] && pol[x][y-1] && pol[x][y] && pol[x][y+1] && pol[x+1][y-1] && pol[x+1][y] && pol[x+1][y+1] ;
            
            if(UpLeft || Up || UpRight || Right || Middle || Left || BottomLeft || Bottom || BottomRight)
            {
                      cout<<i+1<<endl;
                      return 0;
            }
            
    }
    
    cout<<-1<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}