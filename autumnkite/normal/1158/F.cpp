#include <bits/stdc++.h>

const int P = 998244353;
const long long P2 = 1ll * P * P;

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

	std::vector<int> pw(n + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; ++i) {
		pw[i] = 2 * pw[i - 1] % P;
	}

	auto inc = [&](int &a, int b) {
		a + b >= P ? a += b - P : a += b;
	};

	if (m > 9) {
		std::vector<int> inv(n + 1);
		for (int i = 1; i <= n; ++i) {
			inv[i] = qpow(pw[i] - 1, P - 2);
		}
		std::vector<std::vector<int>> w(n + 1, std::vector<int>(n + 1));
		for (int i = 1; i <= n; ++i) {
			std::vector<int> c(m);
			int prod = 1;
			int cnt = m;
			for (int j = i - 1; j >= 0; --j) {
				if (!c[a[j]]) {
					--cnt;
				} else {
					prod = 1ll * prod * inv[c[a[j]]] % P;
				}
				++c[a[j]];
				w[i][j] = cnt ? 0 : prod;
				prod = 1ll * prod * (pw[c[a[j]]] - 1) % P;
			}
		}
		std::vector<int> ans(n + 1);
		ans[0] = pw[n] - 1;
		std::vector<int> f(pw);
		for (int k = 1; k <= n / m; ++k) {
			std::vector<int> g(n + 1);
			for (int i = 1; i <= n; ++i) {
				long long s = 0;
				for (int j = i - 1; j >= 0; --j) {
					s += 1ll * f[j] * w[i][j];
					if (s >= P2) {
						s -= P2;
					}
				}
				g[i] = s % P;
			}
			f.swap(g);
			ans[k] = f[n];
		}
		for (int i = 0; i < n; ++i) {
			ans[i] = (ans[i] + P - ans[i + 1]) % P;
		}
		for (int i = 0; i <= n; ++i) {
			std::cout << ans[i] << " \n"[i == n];
		}
	} else {
		std::vector<std::vector<int>> f(n / m + 1, std::vector<int>(1 << m));
		f[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			std::vector<std::vector<int>> g(n / m + 1, std::vector<int>(1 << m));
			for (int k = 0; k <= n / m; ++k) {
				for (int S = 0; S < (1 << m); ++S) {
					if (f[k][S]) {
						inc(g[k][S], f[k][S]);
						if ((S | (1 << a[i])) == (1 << m) - 1) {
							inc(g[k + 1][0], f[k][S]);
						} else {
							inc(g[k][S | (1 << a[i])], f[k][S]);
						}
					}
				}
			}
			f.swap(g);
		}
		std::vector<int> ans(n + 1);
		for (int i = 0; i <= n / m; ++i) {
			ans[i] = std::accumulate(f[i].begin(), f[i].end(), 0ll) % P;
		}
		ans[0] = (ans[0] + P - 1) % P;
		for (int i = 0; i <= n; ++i) {
			std::cout << ans[i] << " \n"[i == n];
		}
	}
}