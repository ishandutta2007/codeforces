#include"bits/stdc++.h"
using namespace std;
char s[505][505];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=n;i++)s[i][1]='X';
        int j=1;
        for(j=4;j<=m;j+=3)
        {
            for(int i=1;i<=n;i++)s[i][j]='X';
            for(int i=1;i<=n;i++)
            {
                if(s[i][j-1]=='X')
                {
                    s[i][j-2]='X';
                    break;
                }
                if(s[i][j-2]=='X')
                {
                    s[i][j-1]='X';
                    break;
                }
                if(i==n)
                {
                    s[1][j-1]=s[1][j-2]='X';
                }
            }
        }
        if(j!=m+3)
        {
            j--;
            for(int i=1;i<=n;i++)if(s[i][j]=='X')s[i][j-1]='X';
        }
        for(int i=1;i<=n;i++)printf("%s\n",s[i]+1);
    }
    return 0;
}