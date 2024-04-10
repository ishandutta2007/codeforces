#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll color[200],n,m,k,p[200][200],dp[200][200][200];
ll mxll=1000000000000000000;
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        cin>>color[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        cin>>p[i][j];
    for (int i=1;i<=n;i++)
        for (int col=1;col<=m;col++)
        for (int t=0;t<=k;t++)
        dp[i][col][t]=mxll;
    if (color[1]!=0)
    {
        dp[1][color[1]][1]=0;
    } else
    {
        for (int col=1;col<=m;col++)
            dp[1][col][1]=p[1][col];
    }
    for (int i=2;i<=n;i++)
        for (int t=0;t<=k;t++)
        for (int colp=1;colp<=m;colp++)
    {
        if (color[i]!=0)
        {
            if (color[i]==colp) dp[i][color[i]][t]=min(dp[i][color[i]][t],dp[i-1][colp][t]); else
                dp[i][color[i]][t+1]=min(dp[i][color[i]][t+1],dp[i-1][colp][t]);
        } else
        for (int colt=1;colt<=m;colt++)
            if (colt==colp)
        {
            dp[i][colt][t]=min(dp[i][colt][t],dp[i-1][colp][t]+p[i][colt]);
        } else
        {
            dp[i][colt][t+1]=min(dp[i][colt][t+1],dp[i-1][colp][t]+p[i][colt]);
        }
    }
    ll ans=mxll;
    for (int colt=1;colt<=m;colt++)
    {
        ans=min(ans,dp[n][colt][k]);
    }
    if (ans==mxll) cout<<-1; else
    cout<<ans;
}