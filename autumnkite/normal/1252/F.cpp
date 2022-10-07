#include <bits/stdc++.h>

const int P = 998244353, G = 3;

void inc(int &a, int b) {
	a + b >= P ? a += b - P : a += b;
}

void dec(int &a, int b) {
	a < b ? a += P - b : a -= b;
}

int plus(int a, int b) {
	return a + b >= P ? a + b - P : a + b;
}

int minus(int a, int b) {
	return a < b ? a + P - b : a - b;
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

namespace po {
	const int MAX_LEN = 1 << 20;
	const int EXP_BLOCKS = 16;

	typedef std::vector<int> poly;

	int omega[MAX_LEN], inv[MAX_LEN];

	void init_omega(int n = MAX_LEN) {
		for (int m = 1; m < n; m <<= 1) {
			int w = qpow(G, (P - 1) / (m << 1));
			omega[m] = 1;
			for (int i = 1; i < m; ++i) {
				omega[m + i] = 1ll * omega[m + i - 1] * w % P;
			}
		}
	}

	void init_inv(int n = MAX_LEN) {
		inv[1] = 1;
		for (int i = 2; i < n; ++i) {
			inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
		}
	}

	poly rev;

	int enlarge_to_pow2(int _n) {
		int n = 1;
		while (n < _n) {
			n <<= 1;
		}
		return n;
	}

	void init_rev(int n) {
		if (n == (int)rev.size()) {
			return;
		}
		int k = 0;
		while ((1 << k) < n) {
			++k;
		}
		rev.resize(n);
		rev[0] = 0;
		for (int i = 1; i < n; ++i) {
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		}
	}

	void DFT(poly &f, int n) {
		f.resize(n);
		static unsigned long long F[MAX_LEN];
		for (int i = 0; i < n; ++i) {
			F[rev[i]] = f[i];
		}
		for (int m = 1; m < n; m <<= 1) {
			if (m & (1 << 15)) {
				for (int i = 0; i < n; ++i) {
					F[i] %= P;
				}
			}
			for (int p = 0; p < n; p += m << 1) {
				int *W = omega + m;
				unsigned long long *F0 = F + p, *F1 = F + p + m;
				for (int i = 0; i < m; ++i, ++W, ++F0, ++F1) {
					int t = *F1 * *W % P;
					*F1 = *F0 + P - t, *F0 += t;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			f[i] = F[i] % P;
		}
	}

	void IDFT(poly &f, int n) {
		DFT(f, n);
		std::reverse(f.begin() + 1, f.end());
		int t = n == 1 ? 1 : 1ll * (P - P / n) * inv[P % n] % P;
		for (int i = 0; i < n; ++i) {
			f[i] = 1ll * f[i] * t % P;
		}
	}

	poly Plus(poly a, poly b) {
		if (a.size() < b.size()) {
			a.swap(b);
		}
		for (int i = 0; i < (int)b.size(); ++i) {
			inc(a[i], b[i]);
		}
		return a;
	}

	poly Minus(poly a, poly b) {
		a.resize(std::max(a.size(), b.size()));
		for (int i = 0; i < (int)b.size(); ++i) {
			dec(a[i], b[i]);
		}
		return a;
	}

	poly Mul(poly a, poly b, int _n = -1) {
		if (a.empty() || b.empty() || !_n) {
			return poly();
		}
		if (_n == -1) {
			_n = a.size() + b.size() - 1;
		}
		int n = enlarge_to_pow2(_n);
		init_rev(n);
		DFT(a, n), DFT(b, n);
		for (int i = 0; i < n; ++i) {
			a[i] = 1ll * a[i] * b[i] % P;
		}
		IDFT(a, n);
		a.resize(_n);
		return a;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	po::init_omega(), po::init_inv();

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n), b(m);
	int mx = 0;
	for (int &x : a) {
		std::cin >> x;
		mx = std::max(mx, x);
	}
	for (int &x : b) {
		std::cin >> x;
		mx = std::max(mx, x);
	}
	++mx;

	std::vector<int> c(mx);
	for (int x : a) {
		++c[x];
	}
	std::vector<int> sum1(mx + 1), sum2(mx + 1);
	for (int i = 0; i < mx; ++i) {
		sum1[i + 1] = sum1[i] + (c[i] == 1);
		sum2[i + 1] = sum2[i] + 2 * (c[i] >= 2);
	}

	std::vector<int> fac(2 * mx + 1), inv(2 * mx + 1);
	fac[0] = 1;
	for (int i = 1; i <= 2 * mx; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % P;
	}
	inv[2 * mx] = qpow(fac[2 * mx], P - 2);
	for (int i = 2 * mx; i >= 1; --i) {
		inv[i - 1] = 1ll * inv[i] * i % P;
	}

	std::vector<po::poly> ans(m);
	for (int i = 0; i < m; ++i) {
		po::poly f(sum2[b[i]] + 1);
		for (int j = 0; j <= sum2[b[i]]; ++j) {
			f[j] = 1ll * fac[sum2[b[i]]] * inv[j] % P * inv[sum2[b[i]] - j] % P;
		}
		po::poly g(sum1[b[i]] + 1);
		int pw = 1;
		for (int j = 0; j <= sum1[b[i]]; ++j) {
			g[j] = 1ll * fac[sum1[b[i]]] * inv[j] % P * inv[sum1[b[i]] - j] % P * pw % P;
			pw = 2 * pw % P;
		}
		ans[i] = po::Mul(f, g);
	}

	int q;
	std::cin >> q;
	while (q--) {
		int x;
		std::cin >> x;
		x /= 2;
		int res = 0;
		for (int i = 0; i < m; ++i) {
			int t = x - b[i] - 1;
			if (0 <= t && t < (int)ans[i].size()) {
				res = (res + ans[i][t]) % P;
			}
		}
		std::cout << res << "\n";
	}
}