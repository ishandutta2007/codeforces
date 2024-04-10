#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<int> l;
vector<int> r;
vector<vector<int>> G;

vector<int> dpl;
vector<int> dpr;

void dfs(int v, int p = -1) {
	for (int to : G[v])
		if (to != p) {
			dfs(to, v);
			dpl[v] += max(abs(l[v] - l[to]) + dpl[to], abs(l[v] - r[to]) + dpr[to]);
			dpr[v] += max(abs(r[v] - l[to]) + dpl[to], abs(r[v] - r[to]) + dpr[to]);
		}
}

void solve() {
	r.clear();
	l.clear();
	dpr.clear();
	dpl.clear();
	G.clear();

	cin >> n;
	l.resize(n);
	r.resize(n);
	G.resize(n);
	dpl.resize(n);
	dpr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0);
	cout << max(dpl[0], dpr[0]) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();
}