#include <bits/stdc++.h>

class graph {
	int n;
	std::vector<std::vector<int>> E;

	int idx;
	std::vector<int> dfn, low;
	std::vector<int> sta;
	std::vector<bool> vis;
	int cnt;
	std::vector<int> col;

	void tarjan(int u) {
		dfn[u] = low[u] = idx++;
		sta.push_back(u);
		vis[u] = true;
		for (int v : E[u]) {
			if (dfn[v] == -1) {
				tarjan(v);
				low[u] = std::min(low[u], low[v]);
			} else if (vis[v]) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			int v;
			do {
				v = sta.back();
				col[v] = cnt;
				vis[v] = false;
				sta.pop_back();
			} while (v != u);
			++cnt;
		}
	}

public:
	graph(int _n) : n(_n), E(n) {}

	void add_edge(int u, int v) {
		E[u].push_back(v);
	}

	int get_ans(std::vector<int> nd) {
		idx = 0, dfn.resize(n), low.resize(n);
		sta.clear(), vis.resize(n);
		std::fill(dfn.begin(), dfn.end(), -1);
		std::fill(vis.begin(), vis.end(), false);
		cnt = 0, col.resize(n);
		for (int i = 0; i < n; ++i) {
			if (dfn[i] == -1) {
				tarjan(i);
			}
		}

		std::vector<std::vector<int>> G(cnt);
		std::vector<int> deg(cnt);
		for (int u = 0; u < n; ++u) {
			for (int v : E[u]) {
				if (col[u] != col[v]) {
					G[col[u]].push_back(col[v]);
					++deg[col[v]];
				}
			}
		}
		std::vector<int> key(cnt, -1);
		std::vector<bool> ok(cnt);
		for (int i = 0; i < (int)nd.size(); ++i) {
			key[col[nd[i]]] = i;
		}
		std::vector<int> Q;
		for (int i = 0; i < cnt; ++i) {
			if (!deg[i]) {
				Q.push_back(i);
			}
		}
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			if (ok[u]) {
				key[u] = -1;
			}
			if (key[u] != -1) {
				ok[u] = true;
			}
			for (int v : G[u]) {
				--deg[v];
				ok[v] = ok[v] | ok[u];
				if (!deg[v]) {
					Q.push_back(v);
				}
			}
		}

		int idx = 0;
		for (int i = 0; i < cnt; ++i) {
			if (key[i] != -1) {
				key[i] = idx++;
			}
		}
		
		std::vector<int> l(cnt, idx), r(cnt, -1);
		for (int i = (int)Q.size() - 1; i >= 0; --i) {
			int u = Q[i];
			if (key[u] != -1) {
				l[u] = r[u] = key[u];
			}
			for (int v : G[u]) {
				l[u] = std::min(l[u], l[v]);
				r[u] = std::max(r[u], r[v]);
			}
		}

		std::vector<int> id;
		for (int i = 0; i < cnt; ++i) {
			if (l[i] <= r[i]) {
				id.push_back(i);
			}
		}
		std::sort(id.begin(), id.end(), [&](int i, int j) {
			return l[i] < l[j];
		});
		int mx = 0, now = 0, ans = 0;
		for (int i : id) {
			if (l[i] > mx) {
				mx = now;
				++ans;
			}
			now = std::max(now, r[i] + 1);
		}
		if (mx < now) {
			++ans;
		}
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> c(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> c[i];
	}

	int idx = 0;
	std::vector<std::vector<int>> pos(m), id(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[j][i] == '#') {
				pos[i].push_back(j);
				id[i].push_back(idx++);
			}
		}
	}
	
	graph G(idx);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j + 1 < (int)id[i].size(); ++j) {
			G.add_edge(id[i][j], id[i][j + 1]);
			if (pos[i][j + 1] - pos[i][j] == 1) {
				G.add_edge(id[i][j + 1], id[i][j]);
			}
		}
		for (int j = 0; j < (int)id[i].size(); ++j) {
			int l = pos[i][j], r = j + 1 < (int)id[i].size() ? pos[i][j + 1] : n;
			for (int k = l; k < r; ++k) {
				if (i > 0 && a[k][i - 1] == '#') {
					G.add_edge(id[i][j], id[i - 1][std::lower_bound(pos[i - 1].begin(), pos[i - 1].end(), k) - pos[i - 1].begin()]);
				}
				if (i + 1 < m && a[k][i + 1] == '#') {
					G.add_edge(id[i][j], id[i + 1][std::lower_bound(pos[i + 1].begin(), pos[i + 1].end(), k) - pos[i + 1].begin()]);
				}
			}
		}
	}

	std::vector<int> key;
	for (int i = 0; i < m; ++i) {
		if (c[i]) {
			key.push_back(id[i][(int)id[i].size() - c[i]]);
		}
	}
	std::cout << G.get_ans(key) << "\n";
}