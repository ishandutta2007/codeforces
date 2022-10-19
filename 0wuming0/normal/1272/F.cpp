#include"bits/stdc++.h"
using namespace std;
#define ll long long
int dp[205][205][205];
char last[205][205][205];
char s[204],t[205];
int n,m;
void pr(int k,int i,int j)
{//cout<<k<<" "<<i<<" "<<j<<" "<<dp[k][i][j]<<endl;
    if(i==0&&j==0&&k==0)return;
    int now=dp[k][i][j]-1;
    if(k)
    {
        if(dp[k-1][i][j]==now)
        {
            pr(k-1,i,j);
            putchar('(');
            return;
        }
        if(i>0&&s[i]=='('&&dp[k-1][i-1][j]==now)
        {
            pr(k-1,i-1,j);
            putchar('(');
            return;
        }
        if(j>0&&t[j]=='('&&dp[k-1][i][j-1]==now)
        {
            pr(k-1,i,j-1);
            putchar('(');
            return;
        }
        if(i>0&&j>0&&s[i]=='('&&t[j]=='('&&dp[k-1][i-1][j-1]==now)
        {
            pr(k-1,i-1,j-1);
            putchar('(');
            return;
        }
    }
    {
        if(i>0&&s[i]==')'&&dp[k+1][i-1][j]==now)
        {
            pr(k+1,i-1,j);
            putchar(')');
            return;
        }
        if(j>0&&t[j]==')'&&dp[k+1][i][j-1]==now)
        {
            pr(k+1,i,j-1);
            putchar(')');
            return;
        }
        if(i>0&&j>0&&s[i]==')'&&t[j]==')'&&dp[k+1][i-1][j-1]==now)
        {
            pr(k+1,i-1,j-1);
            putchar(')');
            return;
        }
        exit(1);
    }
}
void solve(int k)
{
    pr(k,n,m);
    for(int i=0;i<k;i++)putchar(')');
}
int main()
{
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<205;k++)dp[k][i][j]=100000000;
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)
    {
        if(i==n&&j==m)break;
        for(int k=0;k<=202;k++)
        {
            if(k)
            {
                if(s[i+1]==')')dp[k-1][i+1][j]=min(dp[k-1][i+1][j],dp[k][i][j]+1);
                if(t[j+1]==')')dp[k-1][i][j+1]=min(dp[k-1][i][j+1],dp[k][i][j]+1);
                if(s[i+1]==')'&&t[j+1]==')')dp[k-1][i+1][j+1]=min(dp[k-1][i+1][j+1],dp[k][i][j]+1);
            }
            if(s[i+1]=='(')dp[k+1][i+1][j]=min(dp[k+1][i+1][j],dp[k][i][j]+1);
            if(t[j+1]=='(')dp[k+1][i][j+1]=min(dp[k+1][i][j+1],dp[k][i][j]+1);
            if(s[i+1]=='('&&t[j+1]=='(')dp[k+1][i+1][j+1]=min(dp[k+1][i+1][j+1],dp[k][i][j]+1);
            dp[k+1][i][j]=min(dp[k+1][i][j],dp[k][i][j]+1);
        }
    }
    int ans=1e9,sk;
    for(int k=0;k<=202;k++)if(dp[k][n][m]+k<ans)
    {
        ans=dp[k][n][m]+k;
        sk=k;
    }
    solve(sk);
    cout<<endl;
    return 0;
}