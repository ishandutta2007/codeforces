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

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> fac(n + 1), inv(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}

	auto C = [&](int n, int m) -> int {
		if (m < 0 || m > n) {
			return 0;
		}
		return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
	};

	int ans = 0;
	for (int i = 0; i <= n; i += 2) {
		ans = (ans + 2ll * fac[i] * (C(i - 1, n - i - 1) + C(i, n - i))) % P;
	}
	std::cout << ans << "\n";
}