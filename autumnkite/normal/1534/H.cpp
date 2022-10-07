#include <bits/stdc++.h>

int query(int x) {
	static std::map<int, int> res;
	if (res.count(x)) {
		return res[x];
	}
	std::cout << "? " << x + 1 << std::endl;
	int u;
	std::cin >> u;
	return res[x] = --u;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<int> fa(n), f(n), g(n);
	std::function<void(int)> build_f = [&](int u) {
		std::vector<int> tmp;
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u;
				build_f(v);
				tmp.push_back(f[v]);
			}
		}
		std::sort(tmp.begin(), tmp.end(), std::greater<int>());
		f[u] = 0;
		for (int i = 0; i < (int)tmp.size(); ++i) {
			f[u] = std::max(f[u], tmp[i] + i);
		}
	};
	std::function<void(int)> build_g = [&](int u) {
		std::vector<std::pair<int, int>> tmp;
		if (fa[u] != -1) {
			tmp.emplace_back(g[u], -1);
		}
		for (int v : E[u]) {
			if (v != fa[u]) {
				tmp.emplace_back(f[v], v);
			}
		}
		std::sort(tmp.begin(), tmp.end(), std::greater<std::pair<int, int>>());
		std::vector<int> pre(tmp.size() + 1), suf(tmp.size() + 1);
		for (int i = 0; i < (int)tmp.size(); ++i) {
			pre[i + 1] = std::max(pre[i], tmp[i].first + i);
		}
		for (int i = (int)tmp.size() - 1; i >= 0; --i) {
			suf[i] = std::max(suf[i + 1], tmp[i].first + i - 1);
		}
		for (int i = 0; i < (int)tmp.size(); ++i) {
			if (tmp[i].second != -1) {
				int v = tmp[i].second;
				g[v] = std::max(pre[i], suf[i + 1]);
				build_g(v);
			}
		}
	};
	fa[0] = -1;
	build_f(0);
	build_g(0);

	int lim = 0;
	for (int u = 0; u < n; ++u) {
		std::vector<int> tmp;
		if (fa[u] != -1) {
			tmp.push_back(g[u]);
		}
		for (int v : E[u]) {
			if (v != fa[u]) {
				tmp.push_back(f[v]);
			}
		}
		std::sort(tmp.begin(), tmp.end(), std::greater<int>());
		int s = 0;
		int mx = 0;
		for (int i = 0; i < (int)tmp.size(); ++i) {
			s = std::max(s, mx + tmp[i] + i + 1);
			mx = std::max(mx, tmp[i]);
		}
		lim = std::max(lim, s);
	}

	std::cout << lim << std::endl;

	int rt;
	std::cin >> rt;
	--rt;
	fa[rt] = -1;
	build_f(rt);

	std::vector<int> leaf(n);
	std::function<void(int)> dfs = [&](int u) {
		if (fa[u] != -1) {
			E[u].erase(std::find(E[u].begin(), E[u].end(), fa[u]));
		}
		std::sort(E[u].begin(), E[u].end(), [&](int x, int y) {
			return f[x] > f[y];
		});
		leaf[u] = u;
		for (int v : E[u]) {
			dfs(v);
			if (leaf[u] == u) {
				leaf[u] = leaf[v];
			}
		}
	};
	dfs(rt);

	std::function<int(int)> get_node = [&](int u) {
		for (int v : E[u]) {
			int t = query(leaf[v]);
			if (t != u) {
				return get_node(v);
			}
		}
		return u;
	};

	int a = rt, b = rt;
	for (int u : E[rt]) {
		if (b != rt) {
			break;
		}
		int t = query(leaf[u]);
		if (t != rt) {
			int p = get_node(u);
			if (a == rt) {
				a = p;
			} else {
				b = p;
			}
		}
	}
	std::cout << "! " << a + 1 << " " << b + 1 << std::endl;
}