#include <iostream>
#include <stdio.h>
using namespace std;
char a[501][501];
int n;
int main()
{
    cin>>n;
    char c;
    for (int i=1;i<=n;i++)
    {
        c=getchar();
        for (int j=1;j<=n;j++) a[i][j]=getchar();
    }
    int d=0;
    for (int i=2;i<=n-1;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]=='X' && a[i-1][j-1]=='X' && a[i-1][j+1]=='X' && a[i+1][j-1]=='X' && a[i+1][j+1]=='X') d++;
    cout<<d;
    return 0;
}