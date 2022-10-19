#include <bits/stdc++.h>
using namespace std;
const int N=20003,M=55,P=102,INF=999999999;

int n,m,p;
int a[N];

int dp[N][M][P];
int main()
{
    //freopen("dp.in","r",stdin);
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)for(int k=0;k<p;++k)dp[i][j][k]=-INF;
    dp[0][0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            for(int k=0;k<p;++k)
            {
                if(dp[i][j][k]>=0)
                {
                    dp[i+1][j][(k+a[i+1])%p]=max(dp[i+1][j][(k+a[i+1])%p],dp[i][j][k]);
                    dp[i+1][j+1][a[i+1]%p]=max(dp[i+1][j+1][a[i+1]%p],dp[i][j][k]+k);
                }
            }
        }
    }
    int ans=0;
    for(int k=0;k<p;++k)
        ans=max(ans,dp[n][m-1][k]+k);
    cout<<ans<<endl;
    return 0;
}