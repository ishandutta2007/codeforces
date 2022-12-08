#include <bits/stdc++.h>
using namespace :: std;

#define ll int
#define N ((ll)201*1000)

ll n,m;
vector <ll> e[N];
vector <pair<ll,pair<ll,ll> > > res;
ll mark[N];
bool used[N];

void dfs(ll x,ll par=0)
{
	ll now=0;
	mark[x]=1;
	for(auto u:e[x])
	{
		if(mark[u]==2 || u==par)continue;
		if(!mark[u])
		{
			dfs(u,x);
			if(used[u])continue;
		}
		if(now==0)now=u;
		else res.push_back({now,{x,u}}),now=0;
	}
	if(now && par!=0)res.push_back({now,{x,par}}),used[x]=1;
	mark[x]=2;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs(i);
	cout<<res.size()<<"\n";
	for(auto u:res)cout<<u.first<<" "<<u.second.first<<" "<<u.second.second<<"\n";
}