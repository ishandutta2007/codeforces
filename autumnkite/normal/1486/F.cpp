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
	std::vector<int> c1, c2, c3;
	std::vector<std::map<std::pair<int, int>, int>> mp;

	void dfs(int u) {
		for (int i = 1; i < LG; ++i) {
			fa[i][u] = fa[i - 1][u] == -1 ? -1 : fa[i - 1][fa[i - 1][u]];
		}
		for (int v : E[u]) {
			if (v != fa[0][u]) {
				fa[0][v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
			}
		}
	}

	std::pair<int, std::pair<int, int>> LCA(int u, int v) {
		if (u == v) {
			return std::make_pair(u, std::make_pair(-1, -1));
		}
		if (dep[u] > dep[v]) {
			for (int i = LG - 1; i >= 0; --i) {
				if (fa[i][u] != -1 && dep[fa[i][u]] > dep[v]) {
					u = fa[i][u];
				}
			}
			if (fa[0][u] == v) {
				return std::make_pair(v, std::make_pair(u, -1));
			}
			u = fa[0][u];
		} else if (dep[v] > dep[u]) {
			for (int i = LG - 1; i >= 0; --i) {
				if (fa[i][v] != -1 && dep[fa[i][v]] > dep[u]) {
					v = fa[i][v];
				}
			}
			if (fa[0][v] == u) {
				return std::make_pair(u, std::make_pair(-1, v));
			}
			v = fa[0][v];
		}
		for (int i = LG - 1; i >= 0; --i) {
			if (fa[i][u] != fa[i][v]) {
				u = fa[i][u];
				v = fa[i][v];
			}
		}
		return std::make_pair(fa[0][u], std::make_pair(u, v));
	}

	void get_ans(int u, long long &ans) {
		int sum2 = 0;
		for (int v : E[u]) {
			if (v != fa[0][u]) {
				get_ans(v, ans);
				sum2 += c2[v];
			}
		}
		c2[u] += sum2;
		int sum3 = 0;
		for (auto [p, c] : mp[u]) {
			ans += 1ll * c * (sum2 + sum3);
			if (p.first != -1) {
				ans -= 1ll * c * (c2[p.first] + c3[p.first]);
				c3[p.first] += c;
			}
			if (p.second != -1) {
				ans -= 1ll * c * (c2[p.second] + c3[p.second]);
				c3[p.second] += c;
			}
			if (p.first == -1 && p.second == -1) {
				ans += 1ll * c * (c - 1) / 2;
			}
			ans += 1ll * c * c1[u];
			sum3 += c;
		}
	}

public:
	Tree(std::vector<std::vector<int>> _E) :
	  n(_E.size()), LG(calc_log(n)), E(_E), fa(LG, std::vector<int>(n, -1)), dep(n), c1(n), c2(n), c3(n), mp(n) {
		dfs(0);
	}

	void add_path(int u, int v) {
		auto [z, son] = LCA(u, v);
		if (son.first > son.second) {
			std::swap(son.first, son.second);
			std::swap(u, v);
		}
		++mp[z][son];
		if (son.first != -1) {
			++c1[u];
			++c2[u], --c2[son.first];
		}
		if (son.second != -1) {
			++c1[v];
			++c2[v], --c2[son.second];
		}
	}

	long long get_ans() {
		long long ans = 0;
		get_ans(0, ans);
		return ans;
	}
};

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
	Tree T(E);
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		T.add_path(u, v);
	}
	std::cout << T.get_ans() << "\n";
}