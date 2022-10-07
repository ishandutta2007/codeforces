#include <bits/stdc++.h>

class tree {
	int n, rt;
	std::vector<std::vector<int>> E;
	std::vector<int> dep;
	std::vector<std::vector<int>> lca;
	std::vector<std::vector<int>> S;

	void dfs(int u) {
		S[u].push_back(u);
		for (int v : E[u]) {
			dep[v] = dep[u] + 1;
			dfs(v);
			for (int p : S[u]) {
				for (int q : S[v]) {
					lca[p][q] = lca[q][p] = u;
				}
			}
			for (int q : S[v]) {
				S[u].push_back(q);
			}
		}
	}

public:
	tree(std::vector<int> fa) : n(fa.size()), rt(0), E(n), dep(n), lca(n, std::vector<int>(n)), S(n) {
		for (int i = 0; i < n; ++i) {
			if (fa[i] == -1) {
				rt = i;
			} else {
				E[fa[i]].push_back(i);
			}
		}
		dep[rt] = 0;
		dfs(rt);
	}

	int dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca[u][v]];
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	int na;
	std::cin >> na;
	std::vector<int> fa(na, -1);
	for (int i = 1; i < na; ++i) {
		std::cin >> fa[i];
		--fa[i];
	}
	std::vector<int> pa(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> pa[i];
		--pa[i];
	}

	int nb;
	std::cin >> nb;
	std::vector<int> fb(nb, -1);
	for (int i = 1; i < nb; ++i) {
		std::cin >> fb[i];
		--fb[i];
	}
	std::vector<int> pb(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> pb[i];
		--pb[i];
	}

	tree A(fa), B(fb);

	int tot = 2 * (na + nb - 2);
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, tot));
	f[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			f[i][j] = f[i - 1][j] + A.dist(pa[i - 2], pa[i - 1]);
		}
		for (int j = 0; j <= i - 1; ++j) {
			f[i][i - 1] = std::min(f[i][i - 1], f[j][i - 1] + A.dist(j == 0 ? 0 : pa[j - 1], pa[i - 1]));
		}
		if (i < n) {
			for (int j = 0; j <= i; ++j) {
				f[i][i + 1] = std::min(f[i][i + 1], f[i][j] + B.dist(j == 0 ? 0 : pb[j - 1], pb[i]));
			}
		}
		for (int j = i + 2; j <= n; ++j) {
			f[i][j] = f[i][j - 1] + B.dist(pb[j - 2], pb[j - 1]);
		}
	}
	int ans = tot;
	for (int i = 0; i <= n; ++i) {
		ans = std::min(ans, f[n][i] + A.dist(0, pa[n - 1]) + B.dist(0, i == 0 ? 0 : pb[i - 1]));
		ans = std::min(ans, f[i][n] + A.dist(0, i == 0 ? 0 : pa[i - 1]) + B.dist(0, pb[n - 1]));
	}
	std::cout << (tot - ans) / 2 << "\n";
}