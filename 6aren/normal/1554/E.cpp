#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int k;
int _count[100005];
vector<vector<int>> g;

bool dfs(int u, int p) {
	for (int e : g[u]) {
		if (e == p) continue;
		if (!dfs(e, u)) return false;
		if (_count[e] % k == 0) _count[u]++;
		else _count[e]++;
	}
	if (p == -1 && _count[u] % k) return false;
	return (_count[u] % k == 0 || (_count[u] + 1) % k == 0);
};

void solve() {
	int n;
	cin >> n;
	g.resize(n);
	for (auto &e : g) e.clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> f(n);
	f[1] = 1;
	for (int i = 1; i < n; i++) {
		f[1] = (f[1] << 1) % MOD;
	}
	for (int i = 2; i < n; i++) {
		if ((n - 1) % i == 0) {
			k = i;
			f[i] = dfs(0, -1);
			fill(_count, _count + n, 0);
		}
	}
	vector<int> res(n + 1);
	for (int i = n - 1; i >= 1; i--) {
		res[i] = f[i];
		for (int j = i + i; j < n; j += i) {
			res[i] = (res[i] - res[j] + MOD) % MOD;
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) solve();
}