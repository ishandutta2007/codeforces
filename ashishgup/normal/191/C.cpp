#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;
const int LG=19;
 
int n, q;
vector<pair<int, int> > g[N];
int ans[N], mark[N], store[N], par[LG][N], level[N];

void dfs(int k, int parent, int lvl, int idx)
{
	mark[k]=idx;
	par[0][k]=parent;
	level[k]=lvl;
	for(auto it:g[k])
	{
		if(it.first==parent)
			continue;
		dfs(it.first, k, lvl+1, it.second);
	}
}

void precompute()
{
	for(int i=1;i<LG;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(par[i-1][j])
				par[i][j]=par[i-1][par[i-1][j]];
		}
	}
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=par[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(par[i][u] && par[i][u]!=par[i][v])
		{
			u=par[i][u];
			v=par[i][v];
		}
	}
	return par[0][u];
}

int solve(int k, int par)
{
	int cur=0;
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		cur+=solve(it.first, k);
	}
	cur+=store[k];
	ans[mark[k]]=cur;
	return cur;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back({v, i});
		g[v].push_back({u, i});
	}
	dfs(1, 0, 1, 0);
	precompute();
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int u, v;
		cin>>u>>v;
		int lca=LCA(u, v);
		store[u]++;
		store[v]++;
		store[lca]-=2;
	}
	solve(1, 0);
	for(int i=1;i<=n-1;i++)
		cout<<ans[i]<<" ";
	return 0;    
}