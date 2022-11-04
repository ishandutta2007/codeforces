#include <bits/stdc++.h>
using namespace std;
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
	const int N = 1 << 17;
	int W[2][N + 5], rev[N + 5], stk[N + 5];
	struct Temp {
		inline Temp() {
			int x = qp(3, (mod - 1) / N), y = qp(x, mod - 2);
			for (int i = W[0][0] = W[1][0] = 1; i < N; i++) {
				W[0][i] = 1ll * W[0][i - 1] * x % mod;
				W[1][i] = 1ll * W[1][i - 1] * y % mod;
			}
		}
	} temp;
	inline void NTT(int n, int *a, int flag) {
		for (int i = 0; i < n; i++) if (rev[i] > i) swap(a[rev[i]], a[i]);
		for (int i = 2; i <= n; i <<= 1) {
			int i2 = i >> 1;
			for (int j = 0; j < i2; j++) stk[j] = W[flag][N / i * j];
			for (int j = 0; j < n; j += i) {
				int *p1 = a + j, *p2 = a + j + i2, *p3 = stk;
				for (int k = 0; k < i2; k++, ++p1, ++p2, ++p3) {
					int x = *p1, y = 1ll * *p2 * *p3 % mod;
					*p1 = (x + y >= mod ? x + y - mod : x + y);
					*p2 = (x - y < 0 ? x - y + mod : x - y);
				}
			}
		}
		if (flag) {
			int t = qp(n, mod - 2);
			for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * t % mod;
		}
	}
	int ta[N + 5], tb[N + 5];
	inline void mult(int n, int *a, int m, int *b, int L, int R, int *c) {
		if (n * m <= 5000) {
			for (int i = 0; i < n + m - 1; i++) ta[i] = 0;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ta[i + j] = (ta[i + j] + 1ll * a[i] * b[j]) % mod;
		} else {
			int len, cnt;
			for (len = 1, cnt = 0; len < n + m - 1; len <<= 1, cnt++);
			rev[0] = 0;
			for (int i = 1; i < len; i++) rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1)));
			for (int i = 0; i < n; i++) ta[i] = a[i];
			for (int i = n; i < len; i++) ta[i] = 0;
			for (int i = 0; i < m; i++) tb[i] = b[i];
			for (int i = m; i < len; i++) tb[i] = 0;
			NTT(len, ta, 0);
			NTT(len, tb, 0);
			for (int i = 0; i < len; i++) ta[i] = 1ll * ta[i] * tb[i] % mod;
			NTT(len, ta, 1);
		}
		for (int i = L; i <= R; i++) c[i] = (c[i] + ta[i]) % mod;
	}
}
const int N = 50005;
int n, ans, f[2][N], a[N], c00[N], c10[N], c01[N], c11[N];
void solve(int l, int r, int ty) {
	if (l == r) {
		int cur = n - l;
		if (!ty) {
			if (cur % 2 == 0) {
				ans = (ans + 1ll * f[0][l] * a[cur / 2] % mod * cur % mod * cur % mod * (n - l + 1)) % mod;
			} else {
				ans = (ans + 1ll * f[1][l] * a[cur / 2] % mod * cur % mod * cur % mod * (n - l + 1)) % mod;
			}
		} else {
			if (cur % 2 == 0) {
				ans = (ans + 1ll * f[1][l] * a[cur / 2 - 1] % mod * cur % mod * cur % mod * (n - l + 1)) % mod;
			} else {
				ans = (ans + 1ll * f[0][l] * a[cur / 2] % mod * cur % mod * cur % mod * (n - l + 1)) % mod;
			}
		}
		return;
	}
	int mid = (l + r) >> 1;
	solve(l, mid, ty);
	Poly::mult(mid - l + 1, f[0] + l, r - l + 1, c00, mid - l + 1, r - l, f[0] + l);
	Poly::mult(mid - l + 1, f[1] + l, r - l + 1, c10, mid - l + 1, r - l, f[0] + l);
	Poly::mult(mid - l + 1, f[0] + l, r - l + 1, c01, mid - l + 1, r - l, f[1] + l);
	Poly::mult(mid - l + 1, f[1] + l, r - l + 1, c11, mid - l + 1, r - l, f[1] + l);
	solve(mid + 1, r, ty);
}
int main() {
	scanf("%d", &n);
	a[0] = a[1] = 1;
	for (int i = 2; i <= n; i++) a[i] = (a[i - 1] + a[i - 2]) % mod;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 1) {
			c00[i] = 1ll * a[i / 2] * (i - 1) % mod * (i - 1) % mod;
			c11[i] = 1ll * a[i / 2 - 1] * (i - 1) % mod * (i - 1) % mod;
		} else {
			c10[i] = 1ll * a[i / 2 - 1] * (i - 1) % mod * (i - 1) % mod;
			c01[i] = 1ll * a[i / 2 - 1] * (i - 1) % mod * (i - 1) % mod;
		}
	}
	f[0][1] = 1;
	solve(1, n - 1, 0);
	memset(f, 0, sizeof(f));
	f[1][1] = 1;
	solve(1, n - 1, 1);
	printf("%d\n", ans);
	return 0;
}