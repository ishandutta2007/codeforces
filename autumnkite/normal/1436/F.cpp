#include <bits/stdc++.h>

const int P = 998244353;

int qpow(int a, long long b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int m;
	std::cin >> m;
	std::vector<std::pair<int, int>> v(m);
	int n = 0;
	for (int i = 0; i < m; ++i) {
		std::cin >> v[i].first >> v[i].second;
		n = std::max(n, v[i].first);
	}
	std::vector<int> a(n + 1), mu(n + 1);
	for (auto [x, c] : v) {
		a[x] = c;
	}
	for (int i = 1; i <= n; ++i) {
		mu[i] += (i == 1);
		for (int j = i + i; j <= n; j += i) {
			mu[j] -= mu[i];
		}
	}
	int ans = 0;
	for (int k = 1; k <= n; ++k) {
		if (!mu[k]) {
			continue;
		}
		long long cnt = 0;
		int sum1 = 0, sum2 = 0;
		for (int i = k; i <= n; i += k) {
			cnt += a[i];
			sum1 = (sum1 + 1ll * i * a[i]) % P;
			sum2 = (sum2 + 1ll * i * i % P * a[i]) % P;
		}
		int s = 0;
		if (cnt >= 3) {
			s = (s + (1ll * sum1 * sum1 - sum2) % P * (cnt % P - 2) % P * qpow(2, cnt - 3)) % P;
		}
		if (cnt >= 2) {
			s = (s + (1ll * sum1 * sum1 - sum2) % P * qpow(2, cnt - 2)) % P;
			s = (s + (cnt - 1) % P * sum2 % P * qpow(2, cnt - 2)) % P;
		}
		ans = (ans + mu[k] * s) % P;
	}
	std::cout << (ans + P) % P << "\n";
}