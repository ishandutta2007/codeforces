#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> used;

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (!used[u]) {
			dfs(u);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	g.clear();
	g.resize(n);
	used.assign(n, 0);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}
	for (int i = 0; i < n; i++) {
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			ans *= 2;
			if (ans >= MOD)
				ans -= MOD;
		}
	}
	cout << ans << endl;
}

signed main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}