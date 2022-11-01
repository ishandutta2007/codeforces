#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)201*1000)

ll n,c[N],sz[N];
vector <pair<ll,ll> > e[N];
ld val[N],val_now,val_best;
ll best=-1;
bool mark[N];

void pre_dfs(ll x,ll par=0)
{
	sz[x]=1;
	for(auto u:e[x])
	{
		if(u.first==par || mark[u.first])continue;
		pre_dfs(u.first,x);
		sz[x]+=sz[u.first];
	}
}

ll search_roid(ll x,ll all,ll par=0)
{
	for(auto u:e[x])
	{
		if(u.first==par || mark[u.first])continue;
		if(sz[u.first]>all/2)return search_roid(u.first,all,x);
	}
	return x;
}

void dfs(ll x,ll par,ll root,ll edge,ll dis=0)
{
	val_now+=(ld)c[x]*(dis+edge)*sqrt((ld)dis+edge);
	val[root]+=(ld)c[x]*sqrt((ld)dis+edge);
	for(auto u:e[x])
	{
		if(u.first==par)continue;
		dfs(u.first,x,root,edge,dis+u.second);
	}
}

void solve(ll x)
{
	val_now=0;
	memset(val,0,sizeof val);
	pre_dfs(x);
	ll v=search_roid(x,sz[x]),max_id=e[v][0].first;
	ld sum=0;
	for(auto u:e[v])
	{
		dfs(u.first,v,u.first,u.second);
		sum+=val[u.first];
		if(val[max_id]<val[u.first])max_id=u.first;
	}
	if(best==-1 || val_best>val_now)best=v,val_best=val_now;
	mark[v]=1;
	if(sum-val[max_id]<val[max_id] && !mark[max_id])solve(max_id);
	if(val_best<val_now)v=best,val_now=val_best;
	cout<<v<<" "<<fixed<<setprecision(16)<<val_now<<"\n";
	exit(0);
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n==1)return cout<<"1 0.000000000\n",0;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n-1;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	solve(1);
    return 0;
}