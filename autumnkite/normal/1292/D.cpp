#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	int m = *std::max_element(a.begin(), a.end());
	std::vector<int> c(m + 1);
	for (int x : a) {
		++c[x];
	}

	std::vector<int> minp(m + 1, -1), prime;
	for (int i = 2; i <= m; ++i) {
		if (minp[i] == -1) {
			minp[i] = prime.size();
			prime.push_back(i);
			for (int j = i + i; j <= m; j += i) {
				if (minp[j] == -1) {
					minp[j] = minp[i];
				}
			}
		}
	}
	
	std::vector<std::vector<int>> pf(m + 1, std::vector<int>(prime.size()));
	for (int i = 1; i <= m; ++i) {
		pf[i] = pf[i - 1];
		int x = i;
		while (x != 1) {
			++pf[i][minp[x]];
			x /= prime[minp[x]];
		}
	}

	int idx = m + 1;
	std::vector<std::vector<int>> E(idx);
	std::vector<int> w(c);
	std::vector<int> sta;

	auto LCA = [&](int u, int v) {
		std::vector<int> res(prime.size());
		for (int i = (int)prime.size() - 1; i >= 0; --i) {
			if (pf[u][i] == pf[v][i]) {
				res[i] = pf[u][i];
			} else {
				res[i] = std::min(pf[u][i], pf[v][i]);
				return res;
			}
		}
		return res;
	};

	auto dep = [&](int u) {
		int res = 0;
		for (int c : pf[u]) {
			res += c;
		}
		return res;
	};

	auto add_edge = [&](int u, int v) {
		E[u].push_back(v);
	};
	
	auto insert = [&](int u) {
		if (sta.empty()) {
			sta.push_back(u);
			return;
		}
		int x = sta.back(), lca = idx++, y = -1;
		pf.emplace_back();
		pf[lca] = LCA(x, u);
		while ((int)sta.size() > 1 && dep(y = sta[sta.size() - 2]) > dep(lca)) {
			add_edge(y, x);
			x = y;
			sta.pop_back();
		}
		if (y != -1 && pf[y] == pf[lca]) {
			--idx;
			pf.pop_back();
			add_edge(y, x);
			sta.pop_back();
		} else {
			E.emplace_back();
			w.push_back(0);
			add_edge(lca, x);
			sta.pop_back();
			sta.push_back(lca);
		}
		sta.push_back(u);
	};

	for (int i = 0; i <= m; ++i) {
		insert(i);
	}
	while ((int)sta.size() > 1) {
		add_edge(sta[sta.size() - 2], sta.back());
		sta.pop_back();
	}

	std::vector<int> sum(idx), mx(idx);
	std::function<void(int)> dfs = [&](int u) {
		sum[u] = w[u];
		mx[u] = 0;
		for (int v : E[u]) {
			dfs(v);
			sum[u] += sum[v];
			mx[u] = std::max(mx[u], sum[v]);
		}
	};
	dfs(sta[0]);
	for (int i = 0; i < idx; ++i) {
		mx[i] = std::max(mx[i], sum[sta[0]] - sum[i]);
	}
	int rt = std::min_element(mx.begin(), mx.end()) - mx.begin();

	int tmp = dep(rt);
	long long ans = 0;
	for (int i = 0; i <= m; ++i) {
		auto lca = LCA(i, rt);
		ans += 1ll * (dep(i) + tmp - 2 * std::accumulate(lca.begin(), lca.end(), 0)) * w[i];
	}
	std::cout << ans << "\n";
}