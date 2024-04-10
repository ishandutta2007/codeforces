#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m, check, nodes, ans=0;
int d[N], vis[N];
vector<int> g[N];

void dfs(int k)
{
	if(vis[k])
		return;
	vis[k]=1;
	nodes++;
	check&=(d[k]==2);
	for(auto it:g[k])
		dfs(it);
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++, d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		check=1;
		nodes=0;
		dfs(i);
		if(check&&nodes>=3)
			ans++;
	}
	cout<<ans;
	return 0;
}