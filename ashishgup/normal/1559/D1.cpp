#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1005;

struct DSU
{
	int connected;
	vector<int> par, sz;

	void init(int n) 
	{
		par = sz = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
			par[i] = i, sz[i] = 1;
		connected = n;
	}

	int getPar(int u)
	{
		while(u != par[u])
		{
			par[u] = par[par[u]];
			u = par[u];
		}
		return u;
	}

	int getSize(int u)
	{
		return sz[getPar(u)];
	}

	void unite(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if(par1 == par2)
			return;

		connected--;

		if(sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};

int n, m1, m2;
set<int> g1[N], g2[N];

int32_t main()
{
	IOS;
	cin >> n >> m1 >> m2;
	DSU dsu1, dsu2;
	dsu1.init(n);
	dsu2.init(n);
	for(int i = 1; i <= m1; i++)
	{
		int u, v;
		cin >> u >> v;
		g1[u].insert(v);
		g1[v].insert(u);
		dsu1.unite(u, v);
	}
	for(int i = 1; i <= m2; i++)
	{
		int u, v;
		cin >> u >> v;
		g2[u].insert(v);
		g2[v].insert(u);
		dsu2.unite(u, v);
	}
	vector<pair<int, int> > ans;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if((dsu1.getPar(i) != dsu1.getPar(j)) && (dsu2.getPar(i) != dsu2.getPar(j)))
			{
				ans.push_back({i, j});
				dsu1.unite(i, j);
				dsu2.unite(i, j);
			}
		}
	}
	cout << ans.size() << endl;
	for(auto &it:ans)
		cout << it.first << " " << it.second << endl;
	return 0;
}