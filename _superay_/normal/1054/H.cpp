#include <bits/stdc++.h>
using namespace std;
const int mod = 490019;
const int N = 1100000;
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
namespace Poly_anymod {
	struct Complex {
		double re, im;
		inline Complex() {}
		inline Complex(double r, double i) : re(r), im(i) {}
	};
	inline Complex operator + (const Complex &a, const Complex &b) {
		return Complex(a.re + b.re, a.im + b.im);
	}
	inline Complex operator - (const Complex &a, const Complex &b) {
		return Complex(a.re - b.re, a.im - b.im);
	}
	inline Complex operator * (const Complex &a, const Complex &b) {
		return Complex(a.re * b.re - a.im * b.im, a.im * b.re + a.re * b.im);
	}
	inline Complex operator / (const Complex &a, const double &b) {
		return Complex(a.re / b, a.im / b);
	}
	inline Complex conj(const Complex &a) {
		return Complex(a.re, -a.im);
	}
	int rev[N];
	Complex W[N];
	inline void FFT(int n, Complex *a) {
		for (int i = 1; i < n; i++)
			if (rev[i] > i)
				swap(a[rev[i]], a[i]);
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
	Complex A[N], B[N], F[N], G[N];
	inline void poly_mult(int n, int *a, int m, int *b, int *c) {
		const int X = 15, S = 32767;
		int len, cnt;
		for (len = 1, cnt = 0; len < n + m; len <<= 1, cnt++);
		for (int i = 1; i < len; i++)
			rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1)));
		for (int i = 0; i < len; i++) {
			W[i] = Complex(cos(PI * 2 * i / len), sin(PI * 2 * i / len));
		}
		for (int i = 0; i < n; i++) A[i] = Complex(a[i] & S, a[i] >> X);
		for (int i = 0; i < m; i++) B[i] = Complex(b[i] & S, b[i] >> X);
		for (int i = n; i < len; i++) A[i] = Complex(0, 0);
		for (int i = m; i < len; i++) B[i] = Complex(0, 0);
		FFT(len, A); FFT(len, B);
		for (int i = 0; i < len; i++) {
			int j = (len - i) & (len - 1);
			F[i] = (conj(A[i]) + A[j]) * Complex(0.5, 0) * B[j];
			G[i] = (conj(A[i]) - A[j]) * Complex(0, 0.5) * B[j];
		}
		FFT(len, F); FFT(len, G);
		for (int i = 0; i < n + m - 1; i++) {
			int da = (long long)(F[i].re / len + 0.5) % mod;
			int db = (long long)(F[i].im / len + 0.5) % mod;
			int dc = (long long)(G[i].re / len + 0.5) % mod;
			int dd = (long long)(G[i].im / len + 0.5) % mod;
			c[i] = (da + ((long long)(db + dc) << X) + ((long long)dd << (X + X))) % mod;
			c[i] = (c[i] + mod) % mod;
		}
	}
}
using Poly_anymod::poly_mult;
int n, m, c, a[N], b[N], fa[N], fb[N], fc[N];
int main() {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) {
		int i2 = 1ll * i * i % (mod - 1);
		fa[i2] = (fa[i2] + 1ll * a[i] * qp(c, (mod - 1) - 1ll * i2 * (i2 - 1) / 2 % (mod - 1))) % mod;
	}
	for (int j = 0; j < m; j++) {
		int j3 = 1ll * j * j * j % (mod - 1);
		fb[j3] = (fb[j3] + 1ll * b[j] * qp(c, (mod - 1) - 1ll * j3 * (j3 - 1) / 2 % (mod - 1))) % mod;
	}
	poly_mult(mod - 1, fa, mod - 1, fb, fc);
	int ans = 0;
	for (int i = 0; i <= 2 * (mod - 2); i++) {
		ans = (ans + 1ll * fc[i] * qp(c, 1ll * i * (i - 1) / 2 % (mod - 1))) % mod;
	}
	printf("%d\n", ans);
	return 0;
}