#include <bits/stdc++.h>
using namespace std;
char A[100][100];
int N, gasu=0, jogun=1;
int comp(int a, int b)
{
    if(A[a][b]=='.'&&A[a+1][b]=='.'&&A[a+1][b-1]=='.'&&A[a+1][b+1]=='.'&&A[a+2][b]=='.')
        return 1;
    return 0;
}
int main()
{
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf(" %c", &A[i][j]);
            if(A[i][j]=='.')
                gasu++;
        }
    }
    for(int i=0;i<=N+1;i++)
    {
        A[0][i]='#';
        A[i][0]='#';
        A[N+1][i]='#';
        A[i][N+1]='#';
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(A[i][j]=='.')
            {
                if(comp(i, j)==1)
                {
                    A[i][j]=A[i+1][j]=A[i+1][j-1]=A[i+1][j+1]=A[i+2][j]='#';
                    gasu-=5;
                }
                else
                {
                    jogun=0;
                }
            }
        }
    }
    if(jogun==0)
        printf("NO");
    if(jogun==1)
        printf("YES");
}