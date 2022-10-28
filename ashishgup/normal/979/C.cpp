#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, x, y;
int parent[N], subtree[N];
vector<int> g[N];

void dfs(int k, int par)
{
	subtree[k]=1;
	if(k!=par)
		parent[k]=par;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		subtree[k]+=subtree[it];
	}
}

int32_t main()
{
	IOS;
	cin>>n>>x>>y;
	for(int i=1;i<=n-1;i++)
	{
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(x, x);
	int a=subtree[y];
	int b=n;
	int cur=y;
	while(parent[cur]!=x)
	{
		cur=parent[cur];
	}
	b=n - subtree[cur];
	int ans=n*(n-1) - a*b;
	cout<<ans;
	return 0;
}