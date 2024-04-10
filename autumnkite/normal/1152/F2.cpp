#include <bits/stdc++.h>

const int P = 1000000007;

typedef std::vector<std::vector<int>> matrix;

matrix operator*(const matrix &a, const matrix &b) {
	matrix res(a.size(), std::vector<int>(b[0].size()));
	for (int i = 0; i < (int)a.size(); ++i) {
		for (int k = 0; k < (int)b.size(); ++k) {
			for (int j = 0; j < (int)b[0].size(); ++j) {
				res[i][j] = (res[i][j] + 1ll * a[i][k] * b[k][j]) % P;
			}
		}
	}
	return res;
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

	int n, k, m;
	std::cin >> n >> k >> m;

	std::vector<int> bitcnt(1 << m);
	for (int i = 1; i < (1 << m); ++i) {
		bitcnt[i] = bitcnt[i >> 1] + (i & 1);
	}
	int all = (1 << m) - 1;

	matrix A((k + 1) << m, std::vector<int>((k + 1) << m));
	for (int i = 0; i <= k; ++i) {
		for (int S = 0; S < (1 << m); ++S) {
			int T = S << 1 & all;
			if (i < k) {
				A[i << m | S][(i + 1) << m | T | 1] += bitcnt[S] + 1;
			}
			++A[i << m | S][i << m | T];
		}
	}

	matrix st(1, std::vector<int>((k + 1) << m));
	++st[0][0];
	std::vector<int> res((st * qpow(A, n))[0]);
	int ans = 0;
	for (int i = 0; i < (1 << m); ++i) {
		ans = (ans + res[k << m | i]) % P;
	}
	std::cout << ans << "\n";
}