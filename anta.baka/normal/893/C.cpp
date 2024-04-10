#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5;

int n, m, a[maxn];
vector<int> g[maxn];
vector<bool> was(maxn, false);
ll ans;

int dfs(int v) {
	was[v] = true;
	int ret = a[v];
	for(int to : g[v])
		if(!was[to])
			ret = min(ret, dfs(to));
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
		if(!was[i])
			ans += dfs(i);
	cout << ans;
}