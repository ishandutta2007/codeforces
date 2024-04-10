#include <bits/stdc++.h>

const int P = 998244353;

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

typedef std::array<int, 2> poly;

poly operator+(const poly &A, const poly &B) {
	return poly{(A[0] + B[0]) % P, (A[1] + B[1]) % P};
}

poly operator+(const poly &A, int B) {
	return poly{(A[0] + B) % P, A[1]};
}

poly operator-(const poly &A, const poly &B) {
	return poly{(A[0] + P - B[0]) % P, (A[1] + P - B[1]) % P};
}

poly operator-(const poly &A, int B) {
	return poly{(A[0] + P - B) % P, A[1]};
}

poly operator*(const poly &A, int B) {
	return poly{(int)(1ll * A[0] * B % P), (int)(1ll * A[1] * B % P)};
}

poly operator/(const poly &A, int B) {
	int t = qpow(B, P - 2);
	return poly{(int)(1ll * A[0] * t % P), (int)(1ll * A[1] * t % P)};
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	int m = std::accumulate(a.begin(), a.end(), 0);

	int invn = qpow(n - 1, P - 2), invm = qpow(m, P - 2);

	std::vector<poly> p(m + 1);
	p[0] = poly{0, 1};
	for (int i = 0; i < m; ++i) {
		int a = 1ll * (m - i) * invm % P * invn % P;
		int b = 1ll * i * invm % P;
		p[i + 1] = p[i] * (a + b) - 1;
		if (i > 0) {
			p[i + 1] = p[i + 1] - p[i - 1] * b;
		}
		p[i + 1] = p[i + 1] / a;
	}
	int x = 1ll * (P - p[m][0]) * qpow(p[m][1], P - 2) % P;
	std::vector<int> f(m + 1);
	for (int i = 0; i <= m; ++i) {
		f[i] = (1ll * p[i][1] * x + p[i][0]) % P;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = (ans + f[a[i]]) % P;
	}
	ans = (ans + 1ll * (P - f[0]) * (n - 1)) % P * qpow(n, P - 2) % P;
	std::cout << ans << "\n";
}