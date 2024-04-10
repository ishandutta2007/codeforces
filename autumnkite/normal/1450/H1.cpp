#include <bits/stdc++.h>

const int P = 998244353;

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

	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	std::vector<int> a(n);
	int sum = 0, cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			a[i] = 0;
		} else if (s[i] == 'b') {
			a[i] = i & 1 ? 1 : -1;
		} else {
			a[i] = i & 1 ? -1 : 1;
		}
		sum += a[i];
		cnt += !a[i];
	}

	init(cnt);
	int ans = 0;
	for (int i = 0; i <= cnt; ++i) {
		int now = abs(sum + 2 * i - cnt);
		if (now % 4 == 0) {
			ans = (ans + 1ll * (now / 4) * C(cnt, i)) % P;
		}
	}
	std::cout << 1ll * ans * qpow(2, P - cnt) % P << "\n";
}