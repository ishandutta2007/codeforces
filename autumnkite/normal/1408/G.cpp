#include <bits/stdc++.h>

const int P = 998244353;

class tree {
	int n;
	std::vector<int> fa, cntn, cnte;
	std::vector<std::vector<int>> E;
	std::vector<std::vector<int>> l;
	
	int idx;

	void dfs(int u) {
		int dfn = idx;
		if (E[u].empty()) {
			++idx;
		} else {
			for (int v : E[u]) {
				dfs(v);
			}
		}
		if (1ll * cntn[u] * (cntn[u] - 1) / 2 == cnte[u]) {
			l[idx].push_back(dfn);
		}
	}

public:
	tree(int _n) : n(_n), fa(n), cntn(n, 1), cnte(n), E(n), l(n + 1) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			++cnte[x];
			return false;
		}
		E.push_back({x, y});
		fa.push_back(n);
		cntn.push_back(cntn[x] + cntn[y]);
		cnte.push_back(cnte[x] + cnte[y] + 1);
		fa[x] = fa[y] = n++;
		return true;
	}

	std::vector<int> get_ans() {
		idx = 0;
		for (int i = 0; i < n; ++i) {
			if (find(i) == i) {
				dfs(i);
			}
		}
		std::vector<std::vector<int>> f(l.size(), std::vector<int>(l.size()));
		f[0][0] = 1;
		for (int i = 1; i < (int)l.size(); ++i) {
			for (int j = 1; j < (int)l.size(); ++j) {
				for (int k : l[i]) {
					f[i][j] = (f[i][j] + f[k][j - 1]) % P;
				}
			}
		}
		return f.back();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> E(n * (n - 1) / 2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int v;
			std::cin >> v;
			--v;
			if (i < j) {
				E[v] = std::make_pair(i, j);
			}
		}
	}

	tree T(n);
	for (auto [u, v] : E) {
		T.merge(u, v);
	}

	std::vector<int> ans(T.get_ans());
	for (int i = 1; i <= n; ++i) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}