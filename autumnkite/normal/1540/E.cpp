#include <bits/stdc++.h>

const int P = 1000000007;
const int LIM = 1000;

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

class BIT {
	int n;
	std::vector<int> c;

public:
	BIT(int _n) : n(_n), c(n + 1) {}

	void clear() {
		std::fill(c.begin(), c.end(), 0);
	}

	void add(int x, int v) {
		v = (v % P + P) % P;
		for (++x; x <= n; x += x & -x) {
			c[x] = (c[x] + v) % P;
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s = (s + c[x]) % P;
		}
		return s;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n; ++i) {
		int c;
		std::cin >> c;
		E[i].resize(c);
		for (int j = 0; j < c; ++j) {
			std::cin >> E[i][j];
			--E[i][j];
		}
	}

	std::vector<std::vector<int>> A(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		A[i][i] = i + 1;
		for (int j : E[i]) {
			A[i][j] = j + 1;
		}
	}
	std::vector<std::vector<int>> V(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		V[i][i] = 1;
		for (int j = i; j >= 0; --j) {
			if (j != i) {
				V[i][j] = 1ll * (P - V[i][j]) * qpow(i - j, P - 2) % P;
			}
			for (int k = j - 1; k >= 0; --k) {
				V[i][k] = (V[i][k] + 1ll * (P - V[i][j]) * A[k][j]) % P;
			}
		}
	}
	std::vector<std::vector<int>> C(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		C[i][i] = 1;
		for (int j = i; j >= 0; --j) {
			for (int k = j - 1; k >= 0; --k) {
				C[i][k] = (C[i][k] + 1ll * (P - C[i][j]) * V[j][k]) % P;
			}
		}
	}
	std::vector<std::vector<int>> pw(n, std::vector<int>(2 * LIM + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = -LIM; j <= LIM; ++j) {
			pw[i][j + LIM] = qpow(i + 1, (j + P - 1) % (P - 1));
		}
	}
	std::vector<std::vector<int>> S(n, std::vector<int>(n + 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			S[i][j + 1] = (S[i][j] + V[i][j]) % P;
		}
	}
	std::vector<BIT> T(n, n);

	std::vector<int> d(n), id(n), pos(n);
	auto build = [&]() {
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] > 0) {
				d[i] = 0;
				continue;
			}
			d[i] = LIM + 1;
			for (int j : E[i]) {
				d[i] = std::min(d[i], d[j] + 1);
			}
		}
		std::iota(id.begin(), id.end(), 0);
		std::sort(id.begin(), id.end(), [&](int x, int y) {
			return d[x] < d[y];
		});
		for (int i = 0; i < n; ++i) {
			pos[id[i]] = i;
		}
		for (int i = 0; i < n; ++i) {
			T[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				T[j].add(pos[i], 1ll * a[i] * C[i][j] % P * pw[j][LIM - d[i]] % P);
			}
		}
	};

	build();

	int q;
	std::cin >> q;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int k, l, r;
			std::cin >> k >> l >> r;
			--l;
			int p = std::upper_bound(id.begin(), id.end(), k, [&](int v, int i) {
				return v < d[i];
			}) - id.begin();
			int ans = 0;
			for (int j = 0; j < n; ++j) {
				ans = (ans + 1ll * T[j].query(p) * pw[j][LIM + k] % P * (S[j][r] - S[j][l] + P)) % P;
			}
			for (int i = p; i < n; ++i) {
				if (l <= id[i] && id[i] < r) {
					ans = (ans + (a[id[i]] % P + P) % P) % P;
				}
			}
			std::cout << ans << "\n";
		} else {
			int x, v;
			std::cin >> x >> v;
			--x;
			bool t = a[x] <= 0 && a[x] + v > 0;
			a[x] += v;
			if (t) {
				build();
			} else {
				for (int j = 0; j < n; ++j) {
					T[j].add(pos[x], 1ll * v * C[x][j] % P * pw[j][LIM - d[x]] % P);
				}
			}
		}
	}
}