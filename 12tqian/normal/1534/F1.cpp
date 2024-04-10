#include <bits/stdc++.h>

using namespace std;

struct SCC {
	int n, time, num_comps;
	vector<vector<int>> adj;
	vector<int> disc, id, stk;
	vector<vector<int>> comps;

	void init(int n_) {
		n = n_;
		time = 0;
		num_comps = 0;
		adj.assign(n, vector<int>());
		id.assign(n, -1);
		disc.assign(n, 0);
		comps.clear();
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
	}

	int dfs(int src) {
		int low = disc[src] = ++time;
		stk.push_back(src);
		for (int nxt : adj[src]) {
			if (id[nxt] == -1) {
				low = min(low, disc[nxt] ? : dfs(nxt));
			}
		}
		if (low == disc[src]) {
			for (int nxt = -1; nxt != src;) {
				id[nxt = stk.back()] = num_comps;
				stk.pop_back();
			}
			num_comps++;
		}
		return low;
	}
	
	void build() {
		// builds in topological order
		for (int i = 0; i < n; i++) {
			if (!disc[i]) {
				dfs(i);
			}
		}
		for (auto& x : id) {
			x = num_comps - 1 - x;
		}
		comps.resize(num_comps);
		for (int i = 0; i < n; i++) {
			comps[id[i]].push_back(i);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < m; ++j) {
			if (line[j] == '.') {
				g[i][j] = 0;
			} else {
				g[i][j] = 1;
			}
		}
	}
	vector<int> a(m);
	for (int j = 0; j < m; ++j) {
		cin >> a[j];
	}
	SCC S; 
	S.init(n * m);
	vector<array<int, 2>> edges;
	auto valid = [&](int i, int j) -> bool {
		return i >= 0 && j >= 0 && i < n && j < m;
	};
	auto bind = [&](int i, int j) -> int {
		return i * m + j;
	};
	auto ae = [&](int a, int b, int c, int d) -> bool {
		if (!valid(a, b) || !valid(c, d)) {
			return false;
		}
		if (g[a][b] == 0 || g[c][d] == 0) {
			return false;
		}
		int u = bind(a, b);
		int v = bind(c, d);
		S.ae(u, v);
		edges.push_back({u, v});
		return true;
	};
	vector<int> cur(m, -1);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 1) {
				ae(i, j, cur[j], j);
				cur[j] = i;
			}
		}
		for (int j = 0; j < m; ++j) {
			if (g[i][j] == 0) {
				continue;
			}
			ae(i, j, i - 1, j);
			if (j != 0) {
				ae(i, j, cur[j - 1], j - 1);
			}
			if (j != m - 1) {
				ae(i, j, cur[j + 1], j + 1);
			}
		}
	}
	S.build();
	int sz = S.num_comps;
	vector<int> in(sz);
	for (auto [u, v] : edges) {
		u = S.id[u];
		v = S.id[v];
		if (u == v) {
			continue;
		}
		++in[v];
	}
	int ans = 0;
	for (int i = 0; i < sz; ++i) {
		int u = S.comps[i][0];
		if (g[u / m][u % m] == 0) {
			continue;
		}
		ans += (in[i] == 0);
	}
	cout << ans << '\n';
	return 0;
}