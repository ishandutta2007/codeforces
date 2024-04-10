#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)401*1000)
#define INF ((ll)1e9+10)

ll n,m,a[N],dp[N],maxi[N],lis,res[N];
vector <pair<ll,ll> > vec[N];
vector <ll> gp[N];
bool one[N],only[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
	{
		ll x,y;
		scanf("%d%d",&x,&y);
		vec[x-1].push_back({y,i});
	}
	dp[0]=0;
	for(int i=1;i<N;i++)dp[i]=INF;
	for(int i=0;i<n;i++)
	{
		ll id=lower_bound(dp,dp+n+1,a[i])-dp;
		gp[id].push_back(i);
		maxi[i]=id;
		lis=max(lis,id);
		for(auto u:vec[i])
			res[u.second]+=lower_bound(dp,dp+n+1,u.first)-dp;
		dp[id]=min(dp[id],a[i]);
	}
	dp[0]=-INF;
	for(int i=1;i<N;i++)dp[i]=INF;
	for(int i=n-1;i>=0;i--)
	{
		ll id=lower_bound(dp,dp+n+1,-a[i])-dp;
		if(id+maxi[i]-1==lis)one[i]=1;
		for(auto u:vec[i])
			res[u.second]+=lower_bound(dp,dp+n+1,-u.first)-dp;
		dp[id]=min(dp[id],-a[i]);
	}
	for(int i=1;i<=lis;i++)
	{
		ll cnt=0,id=-1;
		for(auto u:gp[i])
			if(one[u])
				cnt++,id=u;
		if(cnt==1)only[id]=1;
	}
	for(int i=0;i<n;i++)
		for(auto u:vec[i])
			res[u.second]=max(res[u.second]-1,lis-only[i]);
	for(int i=0;i<m;i++)printf("%d\n",res[i]);
	return 0;
}