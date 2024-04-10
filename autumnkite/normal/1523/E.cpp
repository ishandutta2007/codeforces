#include <bits/stdc++.h>

const int P = 1000000007;

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

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> fac(2 * n + 1), inv(2 * n + 1);
	fac[0] = 1;
	for (int i = 1; i <= 2 * n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[2 * n] = qpow(fac[2 * n], P - 2);
	for (int i = 2 * n; i; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
	auto C = [&](int n, int m) -> int {
		if (m < 0 || m > n) {
			return 0;
		}
		return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
	};
	int ans = fac[n];
	for (int i = 1; i <= n && 1ll * (i - 1) * k + 1 <= n; ++i) {
		ans = (ans + 1ll * C(n - 1 - (i - 1) * k + i, i) * fac[i] % P * fac[n - i]) % P;
	}
	std::cout << 1ll * ans * inv[n] % P << "\n";
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