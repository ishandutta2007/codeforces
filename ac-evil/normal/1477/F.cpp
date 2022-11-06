#include <bits/stdc++.h>
#define pb push_back
using std::vector;
typedef vector<int> poly;
typedef vector<poly> poly2;
const int N = 55, M = 2005, P = 998244353;
int n, K, L, l[N], len;
int inc(int a, int b) { return (a += b) >= P ? a - P : a; }
int qpow(int a, int b) {
	int t = 1;
	for (; b; b >>= 1, a = 1LL * a * a % P)
		if (b & 1) t = 1LL * t * a % P;
	return t;
}
int W[M * 2], inv[M], fac[M], ifac[M];
void prework(int n) {
	for (int i = 1; i < n; i <<= 1)
		for (int j = W[i] = 1, Wn = qpow(3, (P - 1) / i >> 1); j < i; j++)
			W[i + j] = 1LL * W[i + j - 1] * Wn % P;
	inv[1] = fac[0] = ifac[0] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
	for (int i = 1; i <= n; i++)
		fac[i] = 1LL * fac[i - 1] * i % P, ifac[i] = 1LL * ifac[i - 1] * inv[i] % P;
}
void fft(poly &a, int n, int op) {
	a.resize(n);
	static int rev[M * 4] = {0};
	for (int i = 1; i < n; i++)
		if ((rev[i] = rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0)) > i) std::swap(a[i], a[rev[i]]);
	for (int q = 1; q < n; q <<= 1)
		for (int p = 0; p < n; p += q << 1)
			for (int i = 0, t; i < q; i++)
				t = 1LL * W[q+i] * a[p+q+i] % P, a[p+q+i] = inc(a[p+i], P - t), a[p+i] = inc(a[p+i], t);
	if (op) return;
	for (int i = 0, inv = qpow(n, P - 2); i < n; i++) a[i] = 1LL * a[i] * inv % P;
	std::reverse(a.begin() + 1, a.end());
}
int getsz(int n) { int x = 1; while (x < n) x <<= 1; return x; }
struct Poly {
	poly2 a; int n, m;
	poly &operator [] (int i) { return a[i]; }
	Poly(poly2 &po, int nn, int mm) : a(po), n(nn), m(mm) {}
};
vector<Poly> F;
Poly operator * (Poly a, Poly b) {
	poly2 res;
	int n = a.n + b.n - 1, m = a.m + b.m - 1, ln = getsz(n), lm = getsz(m);
	for (int i = 0; i < a.n; i++) fft(a[i], lm, 1);
	for (int i = 0; i < b.n; i++) fft(b[i], lm, 1);
	res.resize(n);
	for (int i = 0; i < lm; i++) {
		poly l, r;
		for (int j = 0; j < a.n; j++) l.pb(a[j][i]);
		for (int j = 0; j < b.n; j++) r.pb(b[j][i]);
		fft(l, ln, 1), fft(r, ln, 1);
		for (int j = 0; j < ln; j++) l[j] = 1LL * l[j] * r[j] % P;
		fft(l, ln, 0);
		for (int j = 0; j < n; j++) res[j].pb(l[j]);
	}
	for (int i = 0; i < n; i++) fft(res[i], lm, 0), res[i].resize(m);
	return Poly(res, n, m);
}
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++)
		scanf("%d", &l[i]), L += l[i];
	len = L + 1; prework(len);
	for (int i = 1; i <= n; i++) {
		poly tmp0, tmp1; poly2 tmp;
		for (int j = 0; j <= l[i] / K; j++) {
			int t0, t1;
			t0 = 1LL * (j & 1 ? P - 1 : 1) * ifac[j] % P * qpow(1LL * (l[i] - j * K) * inv[L] % P, j) % P;
			if (j) t1 = 1LL * (j & 1 ? P - 1 : 1) * ifac[j - 1] % P * qpow(1LL * (l[i] - j * K) * inv[L] % P, j - 1) % P; else t1 = 0;
			tmp0.pb(t0), tmp1.pb(t1);
		}
		if (l[i] == K) tmp1[1] = inc(tmp1[1], 1);
		F.pb(Poly(tmp = {tmp0, tmp1}, 2, l[i] / K + 1));
	}
	for (int i = 1; i < n; i <<= 1)
		for (int j = 0; j < n - i; j += i * 2)
			F[j] = F[j] * F[j + i];
	int ans = 0;
	for (int i = 0; i < F[0].n; i++)
		for (int j = 0; j < F[0].m; j++) {
			if (j < i) continue;
			ans = (ans + 1LL * fac[j - i] * qpow(L, j - i + 1) % P * qpow(qpow(1LL * j * K % P, P - 2), j - i + 1) % P * F[0][i][j]) % P;
		}
	printf("%d\n", ans ? P - ans : 0);
	return 0;
}