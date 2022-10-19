#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

int my_pop_cnt(int x) {
	if (x == -1)
		return 0;
	int s = 0;
	while (x > 0) {
		s += x & 1;
		x >>= 1;
	}
	return s % 2;
}

struct edge {
	int a, b, val, p;
};

vector<edge> edges;
vector<vector<edge>> G;
vector<int> node_to_edge;
vector<vector<edge>> G2;
vector<int> color;

void dfs1(int v, int x, int p = -1) {
	color[v] = x;
	for (edge e : G[v]) {
		int to = e.b;
		// cout << e.a << ' ' << e.b << ' ' << v << ' ' << to << endl;
		if (to == p)
			continue;
		if (e.val == -1)
			continue;
		dfs1(to, x ^ e.p, v);
	}
}

void dfs2(int v, int c, int p = -1) {
	// cout << v << ' ' << c << endl;
	color[v] = c;
	for (edge e : G2[v]) {
		int to = v ^ e.a ^ e.b;
		if (color[to] != -1)
			continue;
		dfs2(to, c ^ e.p, v);
	}
}

void dfs3(int v, int p = -1) {
	for (edge e : G[v]) {
		int to = e.b;
		if (to == p)
			continue;
		if (e.val == -1)
			cout << v + 1 << ' ' << to + 1 << ' ' << (color[v] ^ color[to]) << '\n';
		else
			cout << v + 1 << ' ' << to + 1 << ' ' << e.val << '\n';
		dfs3(to, v);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	G = vector<vector<edge>>(n);
	G2 = vector<vector<edge>>(n);
	color = vector<int> (n, -1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, x;
		cin >> u >> v >> x;
		u--;
		v--;
		int p = my_pop_cnt(x);
		G[u].push_back({u, v, x, p});
		G[v].push_back({v, u, x, p});

		if (x != -1) {
			G2[u].push_back({u, v, x, p});
			G2[v].push_back({v, u, x, p});
		}
	}
	for (int i = 0; i < m; ++i) {
		int u, v, x;
		cin >> u >> v >> x;
		u--;
		v--;
		int p = my_pop_cnt(x);

		G2[u].push_back({u, v, x, p});
		G2[v].push_back({v, u, x, p});
	}
	dfs1(0, 0);
	// for (int i = 0; i < n; ++i)
		// cout << color[i] << ' ';
	// cout << endl;
	for (int i = 0; i < n; ++i) {
		if (color[i] != -1)
			dfs2(i, color[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (color[i] == -1)
			dfs2(i, 0);
	}
	bool flag = false;
	for (int v = 0; v < n; ++v) {
		for (edge e : G2[v]) {
			int to = v ^ e.a ^ e.b;
			if (color[v] ^ color[to] != e.p) {
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	if (flag) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	dfs3(0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}