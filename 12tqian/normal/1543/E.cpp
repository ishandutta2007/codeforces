#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<vector<int>> g(1 << n);
	for (int i = 0; i < n * (1 << (n - 1)); ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> label(1 << n);
	vector<bool> vis(1 << n);
	vis[0] = true;
	label[0] = 0;
	vector<int> lst;
	for (int i = 0; i < n; ++i) {
		int u = g[0][i];
		vis[u] = true;
		label[u] = (1 << i);
		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				lst.push_back(v);
			}
		}
	}
	for (int c = 2; c <= n; ++c) {
		vector<int> nxt;
		for (int u : lst) {
			for (int v : g[u]) {
				if (vis[v]) {
					label[u] = label[u] | label[v];
				} else {
					vis[v] = true;
					nxt.push_back(v);
				}
			}
		}
		nxt.swap(lst);
	}
	vector<int> color(1 << n);
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (label[i] & (1 << j)) {
				color[i] ^= j;
			}
		}
	}
	vector<int> ans(1 << n);
	for (int i = 0; i < (1 << n); ++i ){
		ans[label[i]] = i;
	}
	for (int i = 0; i < (1 << n); ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	if (__builtin_popcount(n) == 1) {
		for (int i = 0; i < (1 << n); ++i) {
			cout << color[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++ tc) {
		solve_case(tc);
	}
	return 0;
}