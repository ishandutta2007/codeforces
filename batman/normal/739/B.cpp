#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)201*1000)
#define K ((ll)20)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)

ll n,a[N],prt[N],ans[N];
vector <pair<ll,ll> > e[N];

ll dis[N],par[K][N],dist[K][N];

void pre_dfs(ll x)
{
	for(int i=1;i<K;i++)
		par[i][x]=par[i-1][par[i-1][x]],
		dist[i][x]=dist[i-1][x]+dist[i-1][par[i-1][x]];
	for(auto u:e[x])
		par[0][u.first]=x,
		dis[u.first]=dis[x]+1,
		dist[0][u.first]=u.second,
		pre_dfs(u.first);
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

ll iSum(ll x,ll num)
{
	ll res=0;
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			res+=dist[i][x],x=par[i][x];
	return res;
}

void dfs(ll x)
{
	for(auto u:e[x])
		dfs(u.first),prt[x]+=prt[u.first];
	ans[x]=prt[x];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n;
   	for(int i=1;i<=n;i++)cin>>a[i];
   	for(int i=2;i<=n;i++)
   	{
   		ll x,w;
   		cin>>x>>w;
   		e[x].push_back({i,w});
	}
	pre_dfs(1);
	for(int i=1;i<=n;i++)
	{
		ll l=0,r=dis[i]+1;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(iSum(i,mid)<=a[i])l=mid;
			else r=mid;
		}
		prt[par[0][i]]++;
		prt[par[0][iPar(i,l)]]--;
	}
	dfs(1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}