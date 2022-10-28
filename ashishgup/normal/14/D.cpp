#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int n, node, diam=0;
pair<int, int> edges[N];
vector<int> g[N];

void clear()
{
	for(int i=1;i<=n;i++)
	{
		g[i].clear();
	}
}

void dfs(int k, int par, int dist)
{
	if(dist>=diam)
	{
		node=k;
		diam=dist;
	}
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k, dist+1);
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n-1;i++)
		cin>>edges[i].first>>edges[i].second;
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		clear();
		for(int j=1;j<=n-1;j++)
		{
			if(i==j)
				continue;
			int u=edges[j].first;
			int v=edges[j].second;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		diam=0;
		int u=edges[i].first;
		int v=edges[i].second;
		dfs(u, u, 0);
		dfs(node, node, 0);
		int left=diam;
		diam=0;
		dfs(v, v, 0);
		dfs(node, node, 0);
		int right=diam;
		ans=max(ans, left*right);
	}	
	cout<<ans;
	return 0;
}