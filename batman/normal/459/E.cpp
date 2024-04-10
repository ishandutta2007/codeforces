#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (301*1000)
#define INF ((ll)1e9)

ll n,m,a[N],b[N];
pair <ll,ll> p[N],dp[N][2];

int main()
{
	ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>a[i]>>b[i]>>p[i].first,p[i].second=i;
    sort(p,p+m);
    for(int i=0;i<m;i++)
    {
    	ll in=p[i].second;
    	if(dp[a[in]][1].first<p[i].first)
    	{
    		if(dp[a[in]][1].second+1>dp[b[in]][1].second)
    			dp[b[in]][0]=dp[b[in]][1],dp[b[in]][1]={p[i].first,dp[a[in]][1].second+1};
		}	
		else if(dp[a[in]][0].second+1>dp[b[in]][1].second)	
				dp[b[in]][0]=dp[b[in]][1],dp[b[in]][1]={p[i].first,dp[a[in]][0].second+1};
	}
    ll ans=0;
    for(int i=0;i<N;i++)ans=max(ans,dp[i][1].second);
    cout<<ans;
    return 0;
}