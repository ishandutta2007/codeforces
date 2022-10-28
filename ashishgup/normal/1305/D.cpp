#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 1005;

int n, dist = -1, node;
bool mark[N];
set<int> g[N];

int getSz(int u, int par)
{
	if(mark[u])
		return 0;
	int sz = 1;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		sz += getSz(it, u);
	}
	return sz;
}

void dfs(int u, int par, int d)
{
	if(d > dist)
	{
		dist = d;
		node = u;
	}
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		if(!mark[it])
			dfs(it, u, d + 1);
	}
}

vector<int> path;

bool get(int u, int par)
{
	if(u == node)
	{
		path.push_back(u);
		return 1;
	}
	bool check = 0;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		if(!mark[it])
		{
			if(get(it, u))
			{
				check = 1;
			}
		}
	}
	if(check)
		path.push_back(u);
	return check;
}

int query(int u, int v)
{
	cout << "? " << u << " " << v << endl;
	int x;
	cin >> x;
	assert(x != -1);
	return x;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	int sz = n;
	int u = 1;
	while(sz > 1)
	{
		path.clear();
		dist = -1;
		dfs(u, u, 0);
		int node1 = node;
		dist = -1;
		dfs(node1, node1, 0);
		int node2 = node;
		get(node1, node1);
		int x = query(node1, node2);
		for(auto &it:path)
		{
			if(it != x)
			{
				if(!mark[it])
					mark[it] = 1;
			}
		}
		sz = getSz(x, x);
		if(sz == 1)
		{
			cout << "! " << x << endl;
			exit(0);
		}
		u = x;
	}
	return 0;
}