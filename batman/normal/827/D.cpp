#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define K ((ll)20)
#define INF ((ll)2e9)

ll n,m,dad[N],par[K][N],max_dp[K][N],dis[N],ans[N];
vector <pair<pair<ll,ll>,pair<ll,ll> > > ed;
vector <pair<ll,ll> > e[N],e2[N];
vector <ll> vec[N];
bool mark[N];
multiset <ll> st[N];

ll root(ll x){if(dad[x]<0)return x;return dad[x]=root(dad[x]);}

void dfs(ll x)
{
	for(auto u:e2[x])
	{
		if(u.first==par[0][x])continue;
		dfs(u.first);
		if(!st[u.first].size())ans[u.second]=-1;
		else ans[u.second]=(*st[u.first].begin())-1;
		if(st[u.first].size()>st[x].size())st[u.first].swap(st[x]);
		while(st[u.first].size())st[x].insert(*st[u.first].begin()),st[u.first].erase(st[u.first].begin());
	}
	for(auto u:vec[x])
	{
		if(u>0)
		{
			st[x].insert(u);
			continue;
		}
		st[x].erase(st[x].find(-u));
	}
}

void pre_dfs(ll x)
{
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]],max_dp[i][x]=max(max_dp[i-1][x],max_dp[i-1][par[i-1][x]]);
	for(auto u:e[x])
		if(u.first!=par[0][x])
			par[0][u.first]=x,
			max_dp[0][u.first]=u.second,
			dis[u.first]=dis[x]+1,
			pre_dfs(u.first);
}

ll iPar(ll x,ll num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

ll iMax(ll x,ll num)
{
	ll res=0;
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			res=max(res,max_dp[i][x]),x=par[i][x];
	return res;
}

ll lca(ll x,ll y)
{
	if(dis[x]<dis[y])swap(x,y);
	x=iPar(x,dis[x]-dis[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(par[i][x]!=par[i][y])
			x=par[i][x],y=par[i][y];
	return par[0][x];
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)dad[i]=-1;
	for(int i=1;i<=m;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		ed.push_back({{w,i},{u,v}});
	}
	sort(ed.begin(),ed.end());
	for(auto u:ed)
	{
		ll x=root(u.second.first),y=root(u.second.second);
		if(x==y)continue;
		dad[x]=y;
		mark[u.first.second]=1;
		e[u.second.first].push_back({u.second.second,u.first.first});
		e[u.second.second].push_back({u.second.first,u.first.first});
		e2[u.second.first].push_back({u.second.second,u.first.second});
		e2[u.second.second].push_back({u.second.first,u.first.second});
	}
	pre_dfs(1);
	for(auto u:ed)
	{
		ll w=u.first.first,x=u.second.first,y=u.second.second,id=u.first.second;
		if(mark[id])continue;
		ll p=lca(x,y);
		ans[id]=max(iMax(x,dis[x]-dis[p]),iMax(y,dis[y]-dis[p]))-1;
		vec[x].push_back(w);
		vec[y].push_back(w);
		vec[p].push_back(-w);vec[p].push_back(-w);
	}
	dfs(1);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}