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
	const int MAX_LEN = 1 << 18;

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
		int t = 1ll * (P - P / n) * inv[P % n] % P;
		for (int i = 0; i < n; ++i) {
			f[i] = 1ll * f[i] * t % P;
		}
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

int n;
int c[26];

int f[2][3][405][405], g[2][405][405];
int s[405][405];

void init() {
	int u = 1;
	f[u][0][0][0] = g[u][0][0] = 24;
	f[u][1][1][0] = g[u][1][0] = f[u][2][0][1] = g[u][0][1] = 1;
	for (int i = 2; i <= (n + 1) / 2; ++i) {
		u ^= 1;
		for (int x = 0; x <= i; ++x) {
			for (int y = 0; y <= i - x; ++y) {
				f[u][0][x][y] = (24ll * g[u ^ 1][x][y] - f[u ^ 1][0][x][y]) % P;
				if (x) {
					f[u][1][x][y] = (g[u ^ 1][x - 1][y] - f[u ^ 1][1][x - 1][y]) % P;
				} else {
					f[u][1][x][y] = 0;
				}
				if (y) {
					f[u][2][x][y] = (g[u ^ 1][x][y - 1] - f[u ^ 1][2][x][y - 1]) % P;
				} else {
					f[u][2][x][y] = 0;
				}
				g[u][x][y] = (1ll * f[u][0][x][y] + f[u][1][x][y] + f[u][2][x][y]) % P;
			}
		}
	}

	int u1 = u, u2 = u ^ (n & 1);
	po::poly a((n + 1) * (n + 1)), b((n + 1) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			a[i * (n + 1) + j] = (g[u1][i][j] + P) % P;
			b[i * (n + 1) + j] = (g[u2][i][j] + P) % P;
		}
	}
	po::poly res(po::Mul(a, b, (n + 1) * (n + 1)));
	for (int i = n; i >= 0; --i) {
		for (int j = n; j >= 0; --j) {
			s[i][j] = (1ll * s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1] + res[i * (n + 1) + j]) % P;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	po::init_inv(), po::init_omega();

	std::cin >> n;
	init();

	for (int i = 0; i < 26; ++i) {
		std::cin >> c[i];
	}
	int ans = s[0][0];
	for (int i = 0; i < 26; ++i) {
		ans = (ans - s[c[i] + 1][0]) % P;
	}
	for (int i = 0; i < 26; ++i) {
		for (int j = i + 1; j < 26; ++j) {
			ans = (ans + s[c[i] + 1][c[j] + 1]) % P;
		}
	}
	std::cout << (ans + P) % P << "\n";
}