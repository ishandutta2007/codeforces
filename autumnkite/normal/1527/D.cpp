#include <bits/stdc++.h>

int calc_log(int n) {
	int t = 1;
	while ((1 << t) < n) {
		++t;
	}
	return t;
}

class Tree {
	int n, LG;
	std::vector<std::vector<int>> E;
	std::vector<std::vector<int>> fa;
	std::vector<int> dep;
	std::vector<int> sz;

	void dfs(int u) {
		for (int i = 1; i < LG; ++i) {
			fa[i][u] = fa[i - 1][u] == -1 ? -1 : fa[i - 1][fa[i - 1][u]];
		}
		sz[u] = 1;
		for (int v : E[u]) {
			if (v != fa[0][u]) {
				fa[0][v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
				sz[u] += sz[v];
			}
		}
	}

	int LCA(int u, int v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[i][u] != -1 && dep[fa[i][u]] >= dep[v]) {
				u = fa[i][u];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[i][u] != fa[i][v]) {
				u = fa[i][u];
				v = fa[i][v];
			}
		}
		return fa[0][u];
	}

	int jump(int u, int v) {
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[i][u] != -1 && dep[fa[i][u]] > dep[v]) {
				u = fa[i][u];
			}
		}
		return u;
	}

	int dis(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
	}

	int u, v;

public:
	Tree(std::vector<std::vector<int>> _E) :
	  n(_E.size()), LG(calc_log(n)), E(_E), fa(LG, std::vector<int>(n, -1)), dep(n), sz(n), u(-1), v(-1) {
		dfs(0);
	}

	bool add_node(int z) {
		if (u == -1 || v == -1) {
			u = v = z;
			return true;
		}
		int duv = dis(u, v), duz = dis(u, z), dvz = dis(v, z);
		if (duv == duz + dvz) {
			return true;
		} else if (duz == duv + dvz) {
			v = z;
			return true;
		} else if (dvz == duv + duz) {
			u = z;
			return true;
		}
		return false;
	}

	long long get_ans() {
		if (u == -1 || v == -1) {
			return 1ll * n * (n - 1) / 2;
		} else if (u == v) {
			long long res = 1ll * n * n;
			for (int v : E[u]) {
				if (v == fa[0][u]) {
					res -= 1ll * (n - sz[u]) * (n - sz[u]);
				} else {
					res -= 1ll * sz[v] * sz[v];
				}
			}
			return res / 2;
		} else {
			int t = LCA(u, v);
			if (u != t && v != t) {
				return 1ll * sz[u] * sz[v];
			} else if (u == t) {
				return 1ll * sz[v] * (n - sz[jump(v, u)]);
			} else {
				return 1ll * sz[u] * (n - sz[jump(u, v)]);
			}
		}
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	Tree T(E);
	std::vector<long long> ans(n + 1);
	for (int i = 0; i <= n; ++i) {
		ans[i] = T.get_ans();
		if (i == n || !T.add_node(i)) {
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		ans[i] -= ans[i + 1];
	}
	for (int i = 0; i <= n; ++i) {
		std::cout << ans[i] << " \n"[i == n];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}