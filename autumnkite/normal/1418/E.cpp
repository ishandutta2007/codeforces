#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	std::vector<int> inv(n + 1);
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}

	std::vector<int> sum(n + 1);
	sum[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		sum[i] = (sum[i + 1] + a[i]) % P;
	}

	while (m--) {
		int c, b;
		std::cin >> c >> b;
		int p = std::lower_bound(a.begin(), a.end(), b) - a.begin();
		if (n - p < c || c == n) {
			std::cout << 0 << "\n";
		} else {
			int ans = 1ll * sum[p] * (n - p - c) % P * inv[n - p] % P;
			if (p > 0) {
				ans = (ans + 1ll * (sum[0] - sum[p] + P) * (n - p + 1 - c) % P * inv[n - p + 1]) % P;
			}
			std::cout << ans << "\n";
		}
	}
}