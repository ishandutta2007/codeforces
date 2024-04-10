#include"bits/stdc++.h"
using namespace std;
char s[1005],t[1005];
int dp[1005][1005][13];
int save[1005][1005];
int main()
{
    int n,m,kk;
    cin>>n>>m>>kk;
    cin>>s>>t;
    for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--)
    {
        if(s[i]==t[j])save[i][j]=save[i+1][j+1]+1;
        else save[i][j]=0;
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)for(int k=0;k<=kk;k++)
    {
        if(i>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
        if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
        int q=save[i][j];
        if(q)
        {
            dp[i+q][j+q][k+1]=max(dp[i+q][j+q][k+1],dp[i][j][k]+q);
        }
    }
    int ans=0;
    for(int i=0;i<=kk;i++)ans=max(dp[n][m][i],ans);
    cout<<ans<<endl;
    return 0;
}