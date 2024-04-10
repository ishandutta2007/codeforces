#include <bits/stdc++.h>

const int P = 1000000007;
const int INF = 2000000001;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	std::vector<int> mx(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		E[u].emplace_back(v, w);
		E[v].emplace_back(u, w);
		mx[u] = std::max(mx[u], w);
		mx[v] = std::max(mx[v], w);
	}

	std::vector<int> f(n, -INF), b(n, -INF), wf(n, -INF);
	f[0] = 0;
	for (int i = 0; i < n; ++i) {
		std::vector<int> g(n, -INF), wg(n, -INF);
		for (int u = 0; u < n; ++u) {
			if (f[u] != -INF) {
				if (wf[u] < mx[u]) {
					b[u] = std::max(b[u], f[u] - mx[u] * i);
				}
				for (auto [v, w] : E[u]) {
					if (f[u] + w > g[v]) {
						g[v] = f[u] + w;
						wg[v] = std::max(wf[u], w);
					}
				}
			}
		}
		f.swap(g);
		wf.swap(wg);
	}

	std::vector<int> id(n);
	std::iota(id.begin(), id.end(), 0);
	std::sort(id.begin(), id.end(), [&](int x, int y) {
		return mx[x] < mx[y] || (mx[x] == mx[y] && b[x] > b[y]);
	});

	auto check = [&](int x, int y, int z) {
		return 1ll * (b[x] - b[y]) * (mx[z] - mx[y]) < 1ll * (b[y] - b[z]) * (mx[y] - mx[x]);
	};

	std::vector<int> sta;
	for (int i : id) {
		if (!sta.empty() && mx[sta.back()] == mx[i]) {
			continue;
		}
		while ((int)sta.size() > 1 && !check(sta[sta.size() - 2], sta.back(), i)) {
			sta.pop_back();
		}
		sta.push_back(i);
	}

	int ans = 0;
	int lst = 0;
	for (int i = 0; i < (int)sta.size(); ++i) {
		if (i + 1 < (int)sta.size() && b[sta[i + 1]] > b[sta[i]]) {
			continue;
		}
		int now = i + 1 < (int)sta.size() ? (b[sta[i]] - b[sta[i + 1]]) / (mx[sta[i + 1]] - mx[sta[i]]) + 1 : q + 1;
		now = std::min(now, q + 1);
		ans = (ans + 1ll * (lst + now - 1) * (now - lst) / 2 % P * mx[sta[i]]) % P;
		ans = (ans + 1ll * (now - lst) * b[sta[i]]) % P;
		lst = now;
	}
	std::cout << (ans + P) % P << "\n";
}