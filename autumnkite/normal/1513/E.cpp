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
	std::vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum += a[i];
	}
	if (sum % n) {
		std::cout << 0 << "\n";
		return 0;
	}
	sum /= n;
	int c0 = 0, c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < sum) {
			++c0;
		} else if (a[i] > sum) {
			++c1;
		} else {
			++c2;
		}
	}
	std::vector<int> fac(n + 1), inv(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[n] = qpow(fac[n], P - 2);
	for (int i = n; i; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}
	std::map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		++cnt[a[i]];
	}
	if (c0 <= 1 || c1 <= 1) {
		int ans = fac[n];
		for (auto p : cnt) {
			ans = 1ll * ans * inv[p.second] % P;
		}
		std::cout << ans << "\n";
	} else {
		int ans = 1ll * fac[c0] * fac[c1] % P * fac[c2] % P;
		for (auto p : cnt) {
			ans = 1ll * ans * inv[p.second] % P;
		}
		std::cout << 2ll * ans * fac[n] % P * inv[c2] % P * inv[n - c2] % P << "\n";
	}
}