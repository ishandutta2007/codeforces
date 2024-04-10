#include <bits/stdc++.h>
using namespace std;
const int N = 66000;
const int mod = 1000000007;
const double PI = acos(-1.0);
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
namespace Poly {
	struct Complex {
		double re, im;
		inline Complex() {}
		inline Complex(double r, double i): re(r), im(i) {}
		inline Complex operator + (const Complex &oth) const { return Complex(re + oth.re, im + oth.im); }
		inline Complex operator - (const Complex &oth) const { return Complex(re - oth.re, im - oth.im); }
		inline Complex operator * (const Complex &oth) const {
			return Complex(re * oth.re - im * oth.im, im * oth.re + re * oth.im);
		}
		inline Complex operator / (const double &oth) const { return Complex(re / oth, im / oth); }
		inline Complex conj() const { return Complex(re, -im); }
	};
	int rev[N];
	Complex W[N];
	inline void FFT(int n, Complex *a) {
		for (int i = 0; i < n; i++) if (rev[i] > i) swap(a[rev[i]], a[i]);
		for (int i = 2; i <= n; i <<= 1) {
			for (int j = 0; j < n; j += i) {
				for (int k = j; k < j + (i >> 1); k++) {
					Complex x = a[k], y = a[k + (i >> 1)] * W[n / i * (k - j)];
					a[k] = x + y;
					a[k + (i >> 1)] = x - y;
				}
			}
		}
	}
	int n, len;
	inline void Init(int _n) {
		n = _n;
		int cnt = 0;
		for (len = 1; len < n * 2; len <<= 1, cnt++);
		rev[0] = 0;
		for (int i = 1; i < len; i++) rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1)));
		for (int i = 0; i < len; i++) W[i] = Complex(cos(PI * 2 * i / len), sin(PI * 2 * i / len));
	}
	Complex A[N], B[N], F[N], G[N];
	inline void mult(int *a, int *b, int *c) {
		const int X = 15, S = 32767;
		for (int i = 0; i < n; i++) A[i] = Complex(a[i] & S, a[i] >> X);
		for (int i = 0; i < n; i++) B[i] = Complex(b[i] & S, b[i] >> X);
		for (int i = n; i < len; i++) A[i] = Complex(0, 0);
		for (int i = n; i < len; i++) B[i] = Complex(0, 0);
		FFT(len, A); FFT(len, B);
		for (int i = 0; i < len; i++) {
			int j = (len - i) & (len - 1);
			F[i] = (A[i].conj() + A[j]) * Complex(0.5, 0) * B[j];
			G[i] = (A[i].conj() - A[j]) * Complex(0, 0.5) * B[j];
		}
		FFT(len, F); FFT(len, G);
		for (int i = 0; i < n * 2 - 1; i++) {
			int da = (long long)(F[i].re / len + 0.5) % mod;
			int db = (long long)(F[i].im / len + 0.5) % mod;
			int dc = (long long)(G[i].re / len + 0.5) % mod;
			int dd = (long long)(G[i].im / len + 0.5) % mod;
			c[i] = (da + ((long long)(db + dc) << X) + ((long long)dd << (X + X))) % mod;
			c[i] = (c[i] + mod) % mod;
		}
	}
}
int m, fact[N], ifact[N], inv[N], f[N], A[N], B[N], C[N];
void solve(int n) {
	if (n == 1) {
		f[0] = 0;
		for (int i = 1; i <= m; i++) f[i] = 1;
		return;
	}
	int mid = n >> 1;
	solve(mid);
	A[0] = B[0] = 0;
	for (int i = 1, pw = 1, bs = qp(2, mid); i <= m; i++) {
		pw = 1ll * pw * bs % mod;
		A[i] = 1ll * f[i] * ifact[i] % mod * pw % mod;
		B[i] = 1ll * f[i] * ifact[i] % mod;
	}
	Poly::mult(A, B, C);
	for (int i = 1; i <= m; i++) f[i] = 1ll * C[i] * fact[i] % mod;
	if (n & 1) {
		A[0] = B[0] = 0;
		for (int i = 1, pw = 1; i <= m; i++) {
			pw = 2 * pw % mod;
			A[i] = 1ll * f[i] * ifact[i] % mod * pw % mod;
			B[i] = ifact[i];
		}
		Poly::mult(A, B, C);
		for (int i = 1; i <= m; i++) f[i] = 1ll * C[i] * fact[i] % mod;
	}
}
int main() {
	inv[1] = 1;
	for (int i = 2; i < N; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = fact[0] = ifact[0] = 1; i < N; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
		ifact[i] = 1ll * ifact[i - 1] * inv[i] % mod;
	}
	long long tttn;
	scanf("%lld%d", &tttn, &m);
	if (tttn > m) {
		puts("0");
		return 0;
	}
	int n = tttn;
	Poly::Init(m + 1);
	solve(n);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans = (ans + 1ll * f[i] * fact[m] % mod * ifact[i] % mod * ifact[m - i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}