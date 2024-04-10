#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

bool chmax(long long &a, long long b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, p;
	std::cin >> n >> m >> p;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
	}
	std::vector<int> x(p), y(p);
	for (int i = 0; i < p; ++i) {
		std::cin >> x[i] >> y[i];
	}

	std::vector<bool> vis(n);
	std::vector<int> match(n, -1);

	std::function<bool(int)> find = [&](int u) {
		for (int v : E[u]) {
			if (!vis[v]) {
				vis[v] = true;
				if (match[v] == -1 || find(match[v])) {
					match[v] = u;
					return true;
				}
			}
		}
		return false;
	};

	for (int i = 0; i < n; ++i) {
		std::fill(vis.begin(), vis.end(), false);
		find(i);
	}
	std::vector<bool> matched(n);
	for (int i = 0; i < n; ++i) {
		if (match[i] != -1) {
			matched[match[i]] = true;
		}
	}

	std::vector<bool> visa(n), visb(n);
	std::function<void(int)> dfs = [&](int u) {
		if (visa[u]) {
			return;
		}
		visa[u] = true;
		for (int v : E[u]) {
			if (!visb[v]) {
				visb[v] = true;
				dfs(match[v]);
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		if (!matched[i]) {
			dfs(i);
		}
	}

	std::vector<int> ans;
	for (int u = 0; u < n; ++u) {
		if (!visa[u]) {
			ans.push_back(u + 1);
		}
	}
	for (int u = 0; u < n; ++u) {
		if (visb[u]) {
			ans.push_back(-u - 1);
		}
	}

	std::vector<std::vector<long long>> f(p + 1, std::vector<long long>(ans.size() + 1, -INF));
	std::vector<std::vector<int>> g(p + 1, std::vector<int>(ans.size() + 1));
	f[0][ans.size()] = 0;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j <= (int)ans.size(); ++j) {
			for (int k = 0; k <= j; ++k) {
				if (i + 1 < n - j + k) {
					if (chmax(f[i + 1][j - k], f[i][j] + std::max(0ll, x[i] - 1ll * y[i] * k))) {
						g[i + 1][j - k] = k;
					}
				}
			}
		}
	}

	long long mx = -INF;
	int v = 0;
	for (int i = 0; i <= (int)ans.size(); ++i) {
		if (chmax(mx, f[p][i])) {
			v = i;
		}
	}

	std::vector<int> sol;
	for (int i = p; i >= 1; --i) {
		sol.push_back(0);
		for (int j = 0; j < g[i][v]; ++j) {
			sol.push_back(ans.back());
			ans.pop_back();
		}
		v += g[i][v];
	}
	std::reverse(sol.begin(), sol.end());
	std::cout << sol.size() << "\n";
	for (int x : sol) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}