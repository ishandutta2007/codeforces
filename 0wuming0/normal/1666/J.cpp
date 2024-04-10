#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[205][205];
ll dp[205][205];
int use[205][205];
ll sum[205][205];
int ans[205];
void solve(int l,int r,int fa)
{
    if(l>r)return;
    int &k=use[l][r];
    ans[k]=fa;
    solve(l,k-1,k);
    solve(k+1,r,k);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        use[i][i]=i;
        for(int j=1;j<=n;j++)sum[i][i]+=a[i][j];
    }
    for(int dis=1;dis<n;dis++)for(int i=1;i+dis<=n;i++)
    {
        int j=i+dis;
        sum[i][j]=sum[i][j-1];
        for(int k=1;k<=i-1;k++)sum[i][j]+=a[j][k];
        for(int k=i;k<=j;k++)sum[i][j]-=a[j][k];
        for(int k=j+1;k<=n;k++)sum[i][j]+=a[j][k];
    }
    for(int dis=1;dis<n;dis++)for(int i=1;i+dis<=n;i++)
    {
        int j=i+dis;
        dp[i][j]=1e18;
        for(int k=i;k<=j;k++)
        {
            if(dp[i][j]>dp[i][k-1]+dp[k+1][j]+sum[i][k-1]+sum[k+1][j])
            {
                dp[i][j]=dp[i][k-1]+dp[k+1][j]+sum[i][k-1]+sum[k+1][j];
                use[i][j]=k;
            }
        }
    }
    solve(1,n,0);
    for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}