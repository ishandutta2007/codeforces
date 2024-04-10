#include <bits/stdc++.h>

const int P = 1000000007;

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

	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
		--p[i];
	}
	init(n);

	std::vector<bool> vis(n);
	std::vector<int> st(n + 1);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			int len = 0;
			for (int j = i; !vis[j]; j = p[j]) {
				vis[j] = true;
				++len;
			}
			++st[len];
		}
	}

	std::map<std::vector<int>, int> f;

	std::vector<std::vector<int>> g(n, std::vector<int>(n + 1));
	for (int i = 0; i < n; ++i) {
		int t = 1ll * fac[n] * fac[n - i - 1] % P * inv[n - i] % P;
		g[i][0] = 1;
		for (int j = 0; j < n; ++j) {
			g[i][j + 1] = 1ll * g[i][j] * t % P;
		}
	}

	std::function<int(std::vector<int>)> DP = [&](std::vector<int> S) {
		if (std::accumulate(S.begin(), S.end(), 0) == 0) {
			return 1;
		}
		if (f.count(S)) {
			return f[S];
		}
		int ans = 0;
		std::function<void(int, int, int, int, int)> dfs = [&](int k, int sgn, int A, int B, int coef) {
			if (k == (int)S.size()) {
				if (A > 0) {
					ans = (ans + (sgn ? 1ll : -1ll) * g[B][A] * coef % P * DP(S)) % P;
				}
				return;
			}
			for (int i = 0; i <= S[k]; ++i) {
				S[k] -= i;
				dfs(k + 1, sgn ^ (i & 1), A + i * k, B + S[k] * k, 1ll * coef * C(S[k] + i, i) % P);
				S[k] += i;
			}
		};
		dfs(0, 0, 0, 0, 1);
		return f[S] = (ans + P) % P;
	};
	std::cout << DP(st) << "\n";
}