#include <bits/stdc++.h>

int get_log(int n) {
	int res = 1;
	while ((1 << res) < n) {
		++res;
	}
	return res;
}

class tree {
	int n, A, B, LG;
	std::vector<std::vector<int>> E;
	int rt;
	int idx;
	std::vector<int> dfn, ed, dep, id;
	std::vector<std::vector<int>> fa;
	int lca;

	void dfs(int u) {
		for (int i = 1; i < LG && fa[u][i - 1] != -1; ++i) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		}
		dfn[u] = idx++;
		id[u] = u;
		for (int v : E[u]) {
			if (v != fa[u][0]) {
				fa[v][0] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
				if (dep[id[v]] > dep[id[u]]) {
					id[u] = id[v];
				}
			}
		}
		ed[u] = idx;
	}
	
	bool check(int x, int y) {
		return dfn[x] <= dfn[y] && dfn[y] < ed[x];
	}

public:
	tree(const std::vector<std::vector<int>> &_E, int _A, int _B) : 
	  n(_E.size()), A(_A), B(_B), LG(get_log(n)), E(_E), idx(0),
	  dfn(n), ed(n), dep(n), id(n), fa(n, std::vector<int>(LG, -1)) {
		std::vector<int> _fa(n), mx(n), cmx(n), g(n);

		std::function<void(int)> build_f = [&](int u) {
			mx[u] = cmx[u] = 0;
			for (int v : E[u]) {
				if (v != _fa[u]) {
					_fa[v] = u;
					build_f(v);
					if (mx[v] + 1 > mx[u]) {
						cmx[u] = mx[u];
						mx[u] = mx[v] + 1;
					} else if (mx[v] + 1 > cmx[u]) {
						cmx[u] = mx[v] + 1;
					}
				}
			}
		};

		std::function<void(int)> build_g = [&](int u) {
			for (int v : E[u]) {
				if (v != _fa[u]) {
					if (mx[v] + 1 == mx[u]) {
						g[v] = std::max(g[u] + 1, cmx[u] + 1);
					} else {
						g[v] = std::max(g[u] + 1, mx[u] + 1);
					}
					build_g(v);
				}
			}
		};

		_fa[A] = -1;
		build_f(A);
		g[A] = 0;
		build_g(A);
		int d = 0;
		for (int u = B; u != A; u = _fa[u]) {
			++d;
		}
		rt = -1;
		for (int u = 0; u < n; ++u) {
			int cnt = 0;
			if (_fa[u] != -1 && g[u] >= d) {
				++cnt;
			}
			for (int v : E[u]) {
				if (v != _fa[u] && mx[v] + 1 >= d) {
					++cnt;
				}
			}
			if (cnt >= 3) {
				rt = u;
			}
		}
		if (rt == -1) {
			return;
		}

		dfs(rt);
		lca = A;
		while (!check(lca, B)) {
			lca = fa[lca][0];
		}
	}

	int jump(int u, int k) {
		for (int i = 0; i < LG; ++i) {
			if (k >> i & 1) {
				u = fa[u][i];
			}
		}
		return u;
	}

	bool get_ans() {
		if (rt == -1) {
			return false;
		}
		int a = A, b = B, cnt = 0;
		while (cnt < n) {
			if (id[a] == a) {
				std::swap(a, b);
			}
			if (dep[b] - dep[lca] <= dep[id[a]] - dep[a]) {
				return true;
			}
			b = jump(b, dep[id[a]] - dep[a]);
			a = id[a];
			++cnt;
		}
		return false;
	}
};

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;
	--a, --b;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	tree T(E, a, b);
	if (T.get_ans()) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}