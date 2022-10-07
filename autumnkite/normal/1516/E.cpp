#include <bits/stdc++.h>

const int P = 1000000007;

typedef std::vector<int> poly;

poly mul(poly a, poly b, int m) {
	m = std::min(m, (int)a.size() + (int)b.size() - 1);
	poly res(m);
	for (int i = 0; i < (int)a.size() && i < m; ++i) {
		for (int j = 0; j < (int)b.size() && i + j < m; ++j) {
			res[i + j] = (res[i + j] + 1ll * a[i] * b[j]) % P;
		}
	}
	return res;
}

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

	std::vector<int> fac(m + 1), inv(m + 1);
	fac[0] = 1;
	for (int i = 1; i <= m; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[m] = qpow(fac[m], P - 2);
	for (int i = m; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}

	auto work = [&](poly f, int n, int w) {
		poly g(f.size());
		for (int i = 0; i < (int)f.size(); ++i) {
			int s = 1;
			for (int j = 0; i + j < (int)f.size(); ++j) {
				g[i + j] = (g[i + j] + 1ll * f[i] * s % P * inv[j]) % P;
				s = 1ll * s * w % P * (n - i - j) % P;
			}
		}
		return g;
	};

	poly a(2), s(1);
	a[0] = 1, a[1] = 0;
	s[0] = 1;
	int now = 0;
	for (int i = 0; (1 << i) <= n; ++i) {
		if (n >> i & 1) {
			s = mul(a, work(s, now, 1 << i), m + 1);
			now += 1 << i;
		}
		a = mul(a, work(a, 1 << i, 1 << i), m + 1);
	}
	s.resize(m + 1);
	for (int i = 2; i <= m; ++i) {
		s[i] = (s[i] + s[i - 2]) % P;
	}
	for (int i = 1; i <= m; ++i) {
		std::cout << s[i] << " \n"[i == m];
	}
}