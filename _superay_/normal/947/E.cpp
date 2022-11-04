#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int mod = 998244353;
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
const int N = 1 << 18;
int rev[N + 5];
inline void NTT(int n, int *a, int flag) {
	for (int i = 0; i < n; i++) if (rev[i] > i) swap(a[rev[i]], a[i]);
	for (int i = 2; i <= n; i <<= 1) {
		int w = qp(3, (mod - 1) / i);
		if (flag) w = qp(w, mod - 2);
		for (int j = 0; j < n; j += i) {
			int t = 1;
			for (int k = j; k < j + (i >> 1); k++) {
				int x = a[k], y = 1ll * a[k + (i >> 1)] * t % mod;
				a[k] = (x + y) % mod;
				a[k + (i >> 1)] = (x - y + mod) % mod;
				t = 1ll * t * w % mod;
			}
		}
	}
	if (flag) {
		int t = qp(n, mod - 2);
		for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * t % mod;
	}
}
int mult_ta[N + 5], mult_tb[N + 5];
inline void mult(int n, int *a, int m, int *b, int *c) {
	int len, cnt;
	for (len = 1, cnt = 0; len < n + m - 1; len <<= 1, cnt++);
	rev[0] = 0;
	for (int i = 1; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
	for (int i = 0; i < n; i++) mult_ta[i] = a[i];
	for (int i = 0; i < m; i++) mult_tb[i] = b[i];
	for (int i = n; i < len; i++) mult_ta[i] = 0;
	for (int i = m; i < len; i++) mult_tb[i] = 0;
	NTT(len, mult_ta, 0);
	NTT(len, mult_tb, 0);
	for (int i = 0; i < len; i++) mult_ta[i] = 1ll * mult_ta[i] * mult_tb[i] % mod;
	NTT(len, mult_ta, 1);
	for (int i = 0; i < n + m - 1; i++) c[i] = mult_ta[i];
}
}
int n, a[N], b[N], c[N * 2], fact[N], ifact[N], inv[N];
long long m;
int main() {
	scanf("%d%lld", &n, &m);
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	fact[0] = ifact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % mod;
		ifact[i] = 1ll * ifact[i - 1] * inv[i] % mod;
	}
	for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++) {
		a[i] = 1ll * a[i] * fact[i] % mod;
		b[i] = ifact[n - i];
	}
	Poly::mult(n + 1, a, n + 1, b, c);
	m %= (mod - 1);
	for (int i = 0; i <= n; i++) {
		a[i] = 1ll * c[i + n] * qp(qp(i + 1, m), mod - 2) % mod;
		if (i & 1) a[i] = (mod - a[i]) % mod;
	}
	Poly::mult(n + 1, a, n + 1, b, c);
	for (int i = 0; i <= n; i++) {
		a[i] = 1ll * c[i + n] * ifact[i] % mod;
		if (i & 1) a[i] = (mod - a[i]) % mod;
		printf("%d%c", a[i], " \n"[i == n]);
	}
	return 0;
}