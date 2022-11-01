#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int inf=1000000000;
    char s[201],t[201];
    scanf("%s%s",s,t);
    int n=strlen(s);
    int m=strlen(t);
    int dp[n+1][m+1][201];
    tuple<int,int,int> p[n+1][m+1][201];
    char e[n+1][m+1][201];
    for(int o=0;o<=n;o++) for(int i=0;i<=m;i++) for(int j=0;j<=200;j++) dp[o][i][j]=inf;
    dp[0][0][0]=0;
    for(int o=0;o<=n;o++)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=200;j++)
            {
                if(dp[o][i][j]==inf) continue;
                if(dp[o][i][j]+1<dp[o+(s[o]=='(')][i+(t[i]=='(')][j+1])
                {
                    dp[o+(s[o]=='(')][i+(t[i]=='(')][j+1]=dp[o][i][j]+1;
                    p[o+(s[o]=='(')][i+(t[i]=='(')][j+1]=make_tuple(o,i,j);
                    e[o+(s[o]=='(')][i+(t[i]=='(')][j+1]='(';
                }
                if(j>0&&dp[o][i][j]+1<dp[o+(s[o]==')')][i+(t[i]==')')][j-1])
                {
                    dp[o+(s[o]==')')][i+(t[i]==')')][j-1]=dp[o][i][j]+1;
                    p[o+(s[o]==')')][i+(t[i]==')')][j-1]=make_tuple(o,i,j);
                    e[o+(s[o]==')')][i+(t[i]==')')][j-1]=')';
                }
            }
        }
    }
    for(int j=200;j>0;j--)
    {
        if(dp[n][m][j]+1<dp[n][m][j-1])
        {
            dp[n][m][j-1]=dp[n][m][j]+1;
            p[n][m][j-1]=make_tuple(n,m,j);
            e[n][m][j-1]=')';
        }
    }
    char res[dp[n][m][0]+1];
    res[dp[n][m][0]]='\0';
    int a=n,b=m,c=0;
    for(int i=dp[n][m][0]-1;i>=0;i--)
    {
        res[i]=e[a][b][c];
        tie(a,b,c)=p[a][b][c];
    }
    printf("%s\n",res);
    return 0;
}