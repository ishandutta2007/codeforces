#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)301*1000)

ll n,m,d[N],ans,dd[N];
vector <pair<ll,ll> > e[N];
bool ed_in[N],mark[N];

void dfs(ll x,ll par=0,ll e_id=0)
{
	mark[x]=1;
	bool deg=0;
	for(auto u:e[x])
	{
		if(mark[u.first])continue;
		dfs(u.first,x,u.second);
		if(ed_in[u.second]==1)deg=!deg;
	}
	if(d[x]==-1 || deg==d[x])return ;
	if(par==0)
	{
		cout<<1/0;
	}
	ed_in[e_id]=1;
	ans++;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	ll id=-1,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		sum+=d[i];
		if(d[i]==-1)id=i;
	}
	for(int i=1;i<=m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back({u,i});
		e[u].push_back({v,i});
	}
	if(id!=-1)dfs(id);
	else if(sum%2==1)return cout<<"-1\n",0;
	else dfs(1);
	cout<<ans<<"\n";
	for(int i=1;i<=m;i++)
		if(ed_in[i])
			cout<<i<<" ";
	cout<<"\n";
	return 0;
}