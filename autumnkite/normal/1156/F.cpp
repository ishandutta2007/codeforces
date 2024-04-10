#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		--v;
		++a[v];
	}

	std::vector<int> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}

	std::vector<int> f(n + 1);
	f[0] = 1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			std::vector<int> g(n + 1);
			for (int j = 1; j <= n; ++j) {
				g[j] = 1ll * f[j - 1] * a[i] % P * inv[n - j + 1] % P;
			}
			for (int j = 1; j < n; ++j) {
				ans = (ans + 1ll * g[j] * (a[i] - 1) % P * inv[n - j]) % P;
			}
			for (int j = 0; j <= n; ++j) {
				g[j] = (g[j] + f[j]) % P;
			}
			f.swap(g);
		}
	}
	std::cout << ans << "\n";
}