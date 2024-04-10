#include <bits/stdc++.h>

const int R = 998244353, P = 998244352, G = 3, PP = 402653184;

typedef std::vector<std::vector<int>> matrix;

matrix operator*(const matrix &A, const matrix &B) {
	matrix res(A.size(), std::vector<int>(B[0].size()));
	for (int i = 0; i < (int)A.size(); ++i) {
		for (int k = 0; k < (int)B.size(); ++k) {
			for (int j = 0; j < (int)B[0].size(); ++j) {
				res[i][j] = (res[i][j] + 1ll * A[i][k] * B[k][j]) % P;
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

int qpow(int a, int b, int P) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int BSGS(int a, int x) {
	static const int B = sqrt(P) + 1;
	std::map<int, int> map;
	int pw = 1;
	for (int i = 0; i < B; ++i) {
		map[1ll * pw * x % R] = i;
		pw = 1ll * pw * a % R;
	}
	int Pw = 1;
	for (int i = 0; i < B; ++i) {
		if (map.count(Pw)) {
			return i * B - map[Pw];
		}
		Pw = 1ll * Pw * pw % R;
	}
	return -1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		a[i] %= P;
	}
	int N, F;
	std::cin >> N >> F;
	--N;

	matrix st(1, std::vector<int>(n)), A(n, std::vector<int>(n));
	st[0][n - 1] = 1;
	for (int i = 1; i < n; ++i) {
		A[i][i - 1] = 1;
	}
	for (int i = 0; i < n; ++i) {
		A[n - i - 1][n - 1] = a[i];
	}
	st = st * qpow(A, N);
	int t = BSGS(G, F);
	int g = std::__gcd(st[0][0], P);
	if (t % g == 0) {
		std::cout << qpow(G, 1ll * (t / g) * qpow(st[0][0] / g, PP - 1, P) % P, R) << "\n";
	} else {
		std::cout << -1 << "\n";
	}
}