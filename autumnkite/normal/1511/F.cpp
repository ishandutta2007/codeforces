#include <bits/stdc++.h>

const int P = 998244353;

typedef std::vector<std::vector<int>> matrix;

matrix operator*(const matrix &a, const matrix &b) {
	matrix s(a.size(), std::vector<int>(b[0].size()));
	for (int i = 0; i < (int)a.size(); ++i) {
		for (int k = 0; k < (int)b.size(); ++k) {
			for (int j = 0; j < (int)b[0].size(); ++j) {
				s[i][j] = (s[i][j] + 1ll * a[i][k] * b[k][j]) % P;
			}
		}
	}
	return s;
}

matrix qpow(matrix a, int b) {
	matrix s(a.size(), std::vector<int>(a.size()));
	for (int i = 0; i < (int)a.size(); ++i) {
		s[i][i] = 1;
	}
	for (; b; b >>= 1) {
		if (b & 1) {
			s = s * a;
		}
		a = a * a;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		mx = std::max(mx, (int)a[i].size());
	}
	
	auto id = [&](int i, int j, int k) {
		return i * (mx * n + 1) + (j - 1) * n + k;
	};
	matrix A(mx * (mx * n + 1), std::vector<int>(mx * (mx * n + 1)));
	for (int i = 0; i < mx; ++i) {
		for (int j = 1; j <= mx; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i) {
					++A[id(i, j, k)][id(i - 1, j, k)];
				}
				for (int t = 0; t < n; ++t) {
					int lk = a[k].size(), lt = a[t].size();
					bool flag = true;
					for (int p = 0; p < j && p < lt; ++p) {
						flag &= a[k][lk - j + p] == a[t][p];
					}
					if (flag && i + std::min(j, lt) == mx) {
						if (lt < j) {
							++A[id(i, j, k)][id(mx - 1, j - lt, k)];
						} else if (lt > j) {
							++A[id(i, j, k)][id(mx - 1, lt - j, t)];
						} else {
							++A[id(i, j, k)][id(mx - 1, mx + 1, 0)];
						}
					}
				}
			}
		}
		if (i) {
			++A[id(i, mx + 1, 0)][id(i - 1, mx + 1, 0)];
		}
	}
	matrix B(mx * (mx * n + 1), std::vector<int>(mx * (mx * n + 1)));
	for (int i = 0; i < mx * (mx * n + 1); ++i) {
		B[i][i] = 1;
	}
	for (int t = 0; t < n; ++t) {
		++B[id(mx - 1, mx + 1, 0)][id(mx - 1, a[t].size(), t)];
	}
	matrix st(1, std::vector<int>(mx * (mx * n + 1)));
	st[0][id(mx - 1, mx + 1, 0)] = 1;
	st = st * qpow(B * A, m);
	std::cout << st[0][id(mx - 1, mx + 1, 0)] << "\n";
}