#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define int long long
const int N=50,INF=INT_MAX;

int n,k,m;
int t[N];

int dp[N][N*N];
int32_t main()
{
    //freopen("input.txt","r",stdin);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n>>k>>m;
    for(int i=1;i<=k;++i)
        cin>>t[i];
    sort(t,t+k+1);
    for(int i=0;i<=n;++i)
        for(int p=0;p<=n*k+n;++p)
            dp[i][p]=INF;
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int p=0;p<=n*k+n;++p)
        {
            int tt=0;
            for(int j=0;j<=k;++j)
            {
                tt+=t[j];
                dp[i+1][p+j+(j==k)]=min(dp[i+1][p+j+(j==k)],dp[i][p]+tt);
            }
        }
    }
    int ans=0;
    for(int p=0;p<=n*k+n;++p)
    {
        if(dp[n][p]<=m)
            ans=max(ans,p);
    }
    cout<<ans<<endl;
    return 0;
}