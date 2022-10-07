#include <bits/stdc++.h>

const int P = 998244353, Inv2 = (P + 1) / 2;

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
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += a[i] != a[(i + 1) % n];
	}

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

	auto calc = [&](int n) -> int {
		if (n & 1) {
			return qpow(2, n - 1);
		} else if (n == 0) {
			return 0;
		} else {
			return (qpow(2, n - 1) + 1ll * (P - Inv2) * C(n, n / 2)) % P;
		}
	};

	int ans = 0;
	int pw = 1;
	for (int i = cnt; i >= 0; --i) {
		ans = (ans + 1ll * pw * calc(i) % P * C(cnt, i)) % P;
		pw = 1ll * pw * (m - 2) % P;
	}
	for (int i = 0; i < n - cnt; ++i) {
		ans = 1ll * ans * m % P;
	}
	std::cout << ans << "\n";
}