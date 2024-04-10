#include <bits/stdc++.h>

const int P = 998244353;

int qpow(int a, int b) {
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

	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n), rk(n + 1);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
		rk[p[i]] = i;
	}
	rk[n] = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (rk[p[i] + 1] > rk[p[i + 1] + 1]) {
			--m;
		}
	}
	if (m <= 0) {
		std::cout << 0 << "\n";
		return 0;
	}

	int ans = 1;
	for (int i = n + 1; i < n + m; ++i) {
		ans = 1ll * ans * i % P;
	}
	for (int i = 1; i < m; ++i) {
		ans = 1ll * ans * qpow(i, P - 2) % P;
	}
	std::cout << ans << "\n";
}