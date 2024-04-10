#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (101*1000)
#define M (301*1000)

ll n,m,p,it[N];
vector <pair<ll,ll> > e[N],e2[N];
pair <ll,ll> ans[M];
bool e_mark[M],mark[N];

void dfs2(ll x)
{
	mark[x]=1,p++;
	for(int i=0;i<e2[x].size();i++)
		if(!mark[e2[x][i].first])
			dfs2(e2[x][i].first);
}

void dfs(ll x)
{
	while(it[x]<e[x].size())
	{
		ll i=it[x];
		if(!e_mark[e[x][i].second])
			e_mark[e[x][i].second]=1,dfs(e[x][i].first),e2[e[x][i].first].push_back({x,e[x][i].second}),ans[e[x][i].second]={x,e[x][i].first};
		it[x]++;
	}
		
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		e[v].push_back({u,i+1});
		e[u].push_back({v,i+1});
	}
	dfs(1);
	dfs2(1);
	if(p!=n)return cout<<0,0;
	for(int i=1;i<=m;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	return 0;
}