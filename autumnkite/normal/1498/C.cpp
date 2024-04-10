#include <bits/stdc++.h>

const int P = 1000000007;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> f(n + 1);
	for (int i = 0; i < m; ++i) {
		std::vector<int> g(n + 1);
		g[0] = 1;
		for (int j = 1; j <= n; ++j) {
			g[j] = (g[j - 1] + f[n - j]) % P;
		}
		f.swap(g);
	}
	std::cout << f[n] << "\n";
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