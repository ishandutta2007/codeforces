#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());

const int base = 998244353, P = 1000000007;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, d;
	std::cin >> n >> m >> d;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		E[u].emplace_back(w, v);
	}
	std::vector<int> pw(n);
	pw[0] = 1;
	for (int i = 1; i < n; ++i) {
		pw[i] = 1ll * pw[i - 1] * base % P;
	}
	for (int i = 0; i < n; ++i) {
		pw[i] = 1ll * rnd() % base * pw[i] % P;
	}
	int sum = std::accumulate(pw.begin(), pw.end(), 0ll) % P;
	std::vector<std::vector<int>> val(d + 1, std::vector<int>(d));
	for (int i = 0; i < n; ++i) {
		std::sort(E[i].begin(), E[i].end());
		for (int j = 0; j < (int)E[i].size(); ++j) {
			val[E[i].size()][j] = (val[E[i].size()][j] + pw[E[i][j].second]) % P;
		}
	}

	int ans = 0;
	std::function<void(int, int)> dfs = [&](int k, int now) {
		if (k == d + 1) {
			ans += now == sum;
			return;
		}
		for (int i = 0; i < k; ++i) {
			dfs(k + 1, (now + val[k][i]) % P);
		}
	};
	dfs(1, 0);
	std::cout << ans << "\n";
}