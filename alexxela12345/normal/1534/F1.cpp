#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

vector<vector<int>> g;
vector<vector<int>> g_rev;
vector<int> used;
vector<int> order, component;

void dfs1(int v) {
	used[v] = 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs1(u);
		}
	}
	order.push_back(v);
}
void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : g_rev[v])
        if (!used[u])
            dfs2(u);
}


vector<int> bad;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	int sumN = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (char c : arr[i])
			if (c == '#')
				sumN++;
	}
	vector<int> last(m, -1);
	int cur = 0;
	g.resize(sumN);
	for (int i = 0; i < n; i++) {
		vector<int> ind(m);
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				ind[j] = cur++;
				if (last[j] != -1) {
					if (arr[i - 1][j] == '#') {
						g[ind[j]].push_back(last[j]);
					}
					g[last[j]].push_back(ind[j]);
				}
				last[j] = ind[j];
			}
		}
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') {
				if (j != 0 && last[j - 1] != -1) {
					g[last[j - 1]].push_back(ind[j]);
				}
				if (j != m - 1 && last[j + 1] != -1) {
					g[last[j + 1]].push_back(ind[j]);
				}
			}
		}
	}
	assert(sumN == cur);
	used.assign(cur, 0);
	for (int i = 0; i < cur; i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	n = cur;
	used.assign(cur, 0);
    reverse(order.begin(), order.end());
	g_rev.resize(n);
	for (int i = 0; i < cur; i++) {
		for (int j : g[i]) {
			g_rev[j].push_back(i);
		}
	}
	bad.resize(n);
	int ans = 0;
	for (auto v : order) {
        if (!used[v]) {
            dfs2 (v);
			bool was = 0;
			for (int u : component) {
				if (bad[u]) {
					was = 1;
				}
			}
			if (!was) {
				ans++;
			}
			for (int u : component) {
				for (int u2 : g[u]) {
					bad[u2] = 1;
				}
			}
			component.clear();
		}
	}
	cout << ans << endl;
}

signed main() {
	int t = 1;
	while (t--) {
		solve();
	}
}