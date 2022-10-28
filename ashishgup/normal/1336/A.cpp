#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k, ans = 0;
int level[N], sub[N], val[N];
vector<int> g[N];

void dfs(int u, int par, int lvl)
{
	level[u] = lvl;
	sub[u] = 1;
	val[u] = lvl;
	for(auto &it:g[u])
	{
		if(it == par)
			continue;
		dfs(it, u, lvl + 1);
		sub[u] += sub[it];
	}
	val[u] -= sub[u] - 1;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1, 0);
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; i++)
		v.push_back({val[i], i});
	sort(v.rbegin(), v.rend());
	int ans = 0;
	for(int i = 0; i < k; i++)
		ans += v[i].first;
	cout << ans;
	return 0;
}