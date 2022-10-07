#include <bits/stdc++.h>

const int N = 105, P = 1000000007;

int n, k, m, st, S, a[N];

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

struct matrix {
	int a[N][N];
	
	matrix() {
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= m; ++j) {
				a[i][j] = 0;
			}
		}
	}
	
	int *operator [] (int x) {
		return a[x];
	}
	
	const int *operator [] (int x) const {
		return a[x];
	}
} A;

matrix operator * (const matrix &A, const matrix &B) {
	matrix res;
	for (int i = 0; i <= m; ++i) {
		for (int k = 0; k <= m; ++k) {
			for (int j = 0; j <= m; ++j) {
				res[i][j] = (res[i][j] + 1ll * A[i][k] * B[k][j]) % P;
			}
		}
	}
	return res;
}

matrix qpow(matrix a, int b) {
	matrix s;
	for (int i = 0; i <= m; ++i) {
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
	
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		m += !a[i];
	}
	S = qpow(n * (n - 1) / 2, P - 2);
	for (int i = 1; i <= m; ++i) {
		st += a[i];
	}
	for (int i = 0; i <= m; ++i) {
		A[i][i] = 1;
		if (i > 0) {
			A[i][i - 1] = 1ll * i * i * S % P;
			A[i][i] = (A[i][i] + P - A[i][i - 1]) % P;
		}
		if (i < m) {
			A[i][i + 1] = 1ll * (m - i) * (n - m - i) * S % P;
			A[i][i] = (A[i][i] + P - A[i][i + 1]) % P;
		}
	}
	std::cout << qpow(A, k)[st][0] << std::endl;
}