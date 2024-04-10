#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int tin[N], tout[N];
vector<int> g[N];
int parent[N], lvl[N];
int t = 0;

void dfs(int u, int par, int level)
{
	++t;
	int i = t;
	tin[u] = t;
	parent[u] = par;
	lvl[u] = level;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u, level + 1);
	}
	tout[u] = t;
}

int isAncestor(int u, int v)
{	
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

bool comp(int u, int v)
{
	return lvl[u] < lvl[v];
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	g[0].push_back(1);
	dfs(0, 0, 0);
	while(m--)
	{
		int k;
		cin >> k;
		vector<int> v;
		for(int i = 0; i < k; i++)
		{
			int u;
			cin >> u;
			v.push_back(parent[u]);
		}
		int flag = 1;
		sort(v.begin(), v.end(), comp);
		for(int i = 0; i + 1 < v.size(); i++)
			flag &= isAncestor(v[i], v[i + 1]);
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}