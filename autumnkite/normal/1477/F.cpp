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

typedef std::vector<std::vector<int>> poly;

poly mul(const poly &f, const poly &g) {
	int nf = f.size(), mf = f[0].size();
	int ng = g.size(), mg = g[0].size();
	poly res(nf + ng - 1, std::vector<int>(mf + mg - 1));
	for (int fi = 0; fi < nf; ++fi) {
		for (int fj = 0; fj < mf; ++fj) {
			for (int gi = 0; gi < ng; ++gi) {
				for (int gj = 0; gj < mg; ++gj) {
					res[fi + gi][fj + gj] = (res[fi + gi][fj + gj] + 1ll * f[fi][fj] * g[gi][gj]) % P;
				}
			}
		}
	}
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, K;
	std::cin >> n >> K;
	std::vector<int> a(n);
	int L = 0;
	for (int &x : a) {
		std::cin >> x;
		L += x;
	}
	init(L);
	int invL = qpow(L, P - 2);
	poly f{{1}};
	for (int x : a) {
		int t = (x - 1) / K;
		poly g(2, std::vector<int>(t + 1));
		for (int j = 0; j <= t; ++j) {
			g[0][j] = (j & 1 ? -1ll : 1ll) * inv[j] * qpow(1ll * (x - j * K) * invL % P, j) % P;
		}
		for (int j = 1; j <= t; ++j) {
			g[1][j] = (j & 1 ? -1ll : 1ll) * inv[j - 1] * qpow(1ll * (x - j * K) * invL % P, j - 1) % P;
		}
		f = mul(f, g);
	}
	
	int ans = 0;
	for (int i = 0; i < (int)f.size(); ++i) {
		for (int j = 0; j < (int)f[i].size(); ++j) {
			if (i <= j && j) {
				ans = (ans + 1ll * f[i][j] * qpow(1ll * invL * j % P * K % P, P - 1 - (j - i + 1)) % P * fac[j - i]) % P;
			}
		}
	}
	std::cout << (P - ans) % P << "\n";
}