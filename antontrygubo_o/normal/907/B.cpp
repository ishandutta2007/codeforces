#include<iostream>
#include<cstdio>
using namespace std;




int main()
{
   // freopen("game.txt", "r", stdin);
    char a[9][9];
    for (int i =0; i<9; i++)
        for (int j = 0; j<9; j++) cin>>a[i][j];

int m, n;
cin>>m>>n;
m = (m-1)%3; n = (n-1)%3;
int c = 0;
    for (int i =3*m; i<3*m+3; i++)
        for (int j = 3*n; j<3*n+3; j++) {if(a[i][j]=='.') {a[i][j]='!'; c=1;}}

if (c==0)  for (int i =0; i<9; i++)
        for (int j = 0; j<9; j++) if(a[i][j]=='.') a[i][j]='!';

            for (int i =0; i<9; i++)
       {
          for (int j = 0; j<9; j++) {cout<<a[i][j]; if(j%3==2) cout<<' '; if (j==8) cout<<endl;}
          if (i%3==2) cout<<endl;
       }

}