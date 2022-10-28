#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5005;

int n, m;
int vis[N], col[N], uu[N], vv[N], tim[N];
vector<pair<int, int> > g[N];

bool findLoop(int v) 
{
	if(vis[v]==1)
		return 1;
	if(vis[v]==2)
		return 0;
	vis[v]=1;
	for(auto &it:g[v])
	{
		if(findLoop(it.first))
			return 1;
	}
	vis[v]=2;
	return 0;
}

bool checkLoop()
{
	fill(vis+1, vis+n+1, 0);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && findLoop(i))
			return 1;
	}
	return 0;
}

void dfs(int u, int t)
{
	if(tim[u] == -1)
		tim[u] = t;
	else
		return;
	for(auto &it:g[u])
		dfs(it.first, t + 1);
}

int32_t main()
{
	IOS;
	memset(tim, -1, sizeof(tim));
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		uu[i] = u;
		vv[i] = v;
		g[u].push_back({v, i});
	}
	if(!checkLoop())
	{
		cout << 1 << endl;
		for(int i = 1; i <= m; i++)
			cout << 1 << " ";
		return 0;
	}
	for(int i = 1; i <= n; i++)
		dfs(i, 0);
	cout << 2 << endl;
	for(int i = 1; i <= m; i++)
		cout << 1 + (tim[vv[i]] > tim[uu[i]]) << " ";
	return 0;
}