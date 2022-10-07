#include <bits/stdc++.h>

const int P = 1000000007, Inv3 = (P + 1) / 3;

std::vector<int> fac, inv;

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

void init(int n) {
	fac.resize(n + 1), inv.resize(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
}

int C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	init(3 * (n + 1));
	std::vector<int> f(3 * (n + 1));
	for (int i = 0; i < 3 * (n + 1); ++i) {
		f[i] = C(3 * (n + 1), i + 1);
	}
	for (int i = 0; i < 3 * (n + 1); ++i) {
		if (i >= 2) {
			f[i] = (f[i] + P - f[i - 2]) % P;
		}
		if (i >= 1) {
			f[i] = (f[i] + 3ll * (P - f[i - 1])) % P;
		}
		f[i] = 1ll * f[i] * Inv3 % P;
	}
	while (q--) {
		int x;
		std::cin >> x;
		std::cout << f[x] << "\n";
	}
}