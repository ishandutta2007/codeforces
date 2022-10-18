#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int n, k;
const int maxn = 2e5 + 42, maxk = 10;
vector<int> g[maxn];
int sz[maxn][maxk];
int up[maxn][maxk];
int ans = 0;
int penalty = 0;
void dfs1(int v = 0, int p = 0)
{
	sz[v][0] = 1;
	for(auto u: g[v])
	{
		if(u == p)
			continue;
		dfs1(u, v);
		for(int z = 0; z < k; z++)
			sz[v][(z + 1) % k] += sz[u][z];
	}
}

void dfs2(int v = 0, int p = 0)
{
	for(auto u: g[v])
	{
		if(u == p)
			continue;
		for(int z = 0; z < k; z++)
			up[u][(z + 1) % k] = up[v][z] + sz[v][z] - sz[u][(z + k - 1) % k];
		dfs2(u, v);
	}
	if(v != p)
	{
		int sm = accumulate(sz[v], sz[v] + k, 0);
		int smu = accumulate(up[v], up[v] + k, 0);
		ans += smu * sz[v][0] + sm * up[v][1 % k];
	}
}


signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1();
	dfs2();
	//assert(ans % 2 == 0);
	cout << ans / 2 << endl;
}
//89035321450