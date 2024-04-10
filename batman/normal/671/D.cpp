#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n,m,dis[N],lazy[N],ans;
vector <ll> e[N];
vector <pair<ll,ll> > qu[N];
set <pair<ll,ll> > s[N];

void update(ll x)
{
	while(s[x].size() && dis[s[x].begin()->second]>dis[x]-1)s[x].erase(s[x].begin());
	if(!s[x].size())
	{
		cout<<-1;
		exit(0);
	}
	ans+=s[x].begin()->first-lazy[x];
	lazy[x]=s[x].begin()->first;
}

void pre_dfs(ll x,ll par=0)
{
	for(auto u:e[x])
		if(u!=par)
			dis[u]=dis[x]+1,pre_dfs(u,x);
}

void dfs(ll x,ll par=0)
{
	ll id=0;
	for(auto u:e[x])
		if(u!=par)
		{
			dfs(u,x);
			if((ll)s[u].size()>(ll)s[id].size())id=u;
		}
	if(!id)
	{
		for(auto u:qu[x])
			s[x].insert(u);
		if(qu[x].size()==0)
		{
			cout<<-1;
			exit(0);
		}
		return ;
	}
	update(id);
	s[x].swap(s[id]);
	lazy[x]=lazy[id];
	for(auto u:e[x])
		if(u!=par && u!=id)
		{
			update(u);
			for(auto it:s[u])
				if(dis[it.second]<=dis[x])
					s[x].insert({it.first-lazy[u]+lazy[x],it.second});
		}
	for(auto u:qu[x])
		s[x].insert({u.first+lazy[x],u.second});
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=0;i<m;i++)
	{
		ll v,u,w;
		cin>>u>>v>>w;
		qu[u].push_back({w,v});
	}
	pre_dfs(1);
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}