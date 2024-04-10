#include"bits/stdc++.h"
using namespace std;
int dp[1005][2005];
int a[1005];
int b[2005];
int main()
{
    int n,k,p;
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+k);
    for(int i=0;i<1005;i++)for(int j=0;j<2005;j++)dp[i][j]=-1;
    dp[0][0]=0;
    for(int j=0;j<=k;j++)for(int i=0;i<=n;i++)if(dp[i][j]!=-1)
    {
        if(dp[i][j+1]==-1)dp[i][j+1]=dp[i][j];
        else dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
        if(dp[i+1][j+1]==-1)dp[i+1][j+1]=max(dp[i][j],abs(b[j+1]-a[i+1])+abs(b[j+1]-p));
        else dp[i+1][j+1]=min(dp[i+1][j+1],max(dp[i][j],abs(b[j+1]-a[i+1])+abs(b[j+1]-p)));
    }
    cout<<dp[n][k]<<endl;
    return 0;
}