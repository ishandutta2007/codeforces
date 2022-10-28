#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, d, dist=-1, node=1, node2=1, ans=0;
int mark[N], vis[N];
vector<int> g[N];

void dfs(int k, int par, int lvl)
{
	if(lvl>=dist && mark[k])
	{
		node=k;
		dist=lvl;
	}
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, lvl+1);
	}
}

void dfs2(int k, int par, int lvl)
{
	if(lvl<=d)
		vis[k]++;
	for(auto &it:g[k])
	{
		if(it==par)
			continue;
		dfs2(it, k, lvl+1);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		mark[x]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 0);
	node2=node;
	dfs(node, node, 0);
	dfs2(node, node, 0);
	dfs2(node2, node2, 0);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==2)
			ans++;
	}
	cout<<ans;
	return 0;
}