#include <bits/stdc++.h>
using namespace std;

const int N = 17;
const int mod = 1e9 + 7;
int n, ans, s[1 << N];
void FWT_or(int *f, int op) {
	for(int k = 1; k < 1 << N; k <<= 1)
		for(int i = 0; i < 1 << N; i += k << 1)
			for(int j = 0; j < k; j++)
				f[i | j | k] = (f[i | j | k] + 1ll * op * f[i | j]) % mod; 
}
void FWT_and(int *f, int op) {
	for(int k = 1; k < 1 << N; k <<= 1)
		for(int i = 0; i < 1 << N; i += k << 1)
			for(int j = 0; j < k; j++)
				f[i | j] = (f[i | j] + 1ll * op * f[i | j | k]) % mod;
}
void FWT_xor(int *f, int op) {
	for(int k = 1; k < 1 << N; k <<= 1)
		for(int i = 0; i < 1 << N; i += k << 1)
			for(int j = 0, x, y; j < k; j++)
				x = f[i | j], y = f[i | j | k], f[i | j] = 1ll * (x + y) * op % mod, f[i | j | k] = 1ll * (x + mod - y) * op % mod; 
}
void subset_convolution(int *a, int *b, int *c) {
	static int f[N + 1][1 << N], g[N + 1][1 << N], h[N + 1][1 << N];
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(h, 0, sizeof(h));
	for(int i = 0; i < 1 << N; i++) f[__builtin_popcount(i)][i] = a[i], g[__builtin_popcount(i)][i] = b[i];
	for(int i = 0; i <= N; i++) FWT_or(f[i], 1), FWT_or(g[i], 1);
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= i; j++)
			for(int p = 0; p < 1 << N; p++)
				h[i][p] = (h[i][p] + 1ll * f[j][p] * g[i - j][p]) % mod;
	for(int i = 0; i <= N; i++) FWT_or(h[i], mod - 1);
	for(int i = 0; i < 1 << N; i++) c[i] = h[__builtin_popcount(i)][i];
}
int main() {
	cin >> n;
	for(int i = 1, v; i <= n; i++) scanf("%d", &v), s[v]++;
	static int a[1 << N], b[1 << N], c[1 << N], d[1 << N], f[1 << N];
	memcpy(a, s, sizeof(a));
	memcpy(b, s, sizeof(b));
	memset(c, 0, sizeof(c));
	subset_convolution(a, b, c);
	memcpy(a, s, sizeof(a)), memcpy(b, s, sizeof(b));
	FWT_xor(a, 1), FWT_xor(b, 1);
	for(int i = 0; i < 1 << N; i++) d[i] = 1ll * a[i] * b[i] % mod;
	FWT_xor(d, mod + 1 >> 1);
	f[0] = 0, f[1] = 1;
	for(int i = 2; i < 1 << N; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
	for(int i = 0; i < 1 << N; i++) a[i] = 1ll * c[i] * f[i] % mod, b[i] = 1ll * d[i] * f[i] % mod, s[i] = 1ll * s[i] * f[i] % mod;
	FWT_and(a, 1), FWT_and(b, 1), FWT_and(s, 1);
	for(int i = 0; i < 1 << N; i++) s[i] = 1ll * a[i] * b[i] % mod * s[i] % mod;
	FWT_and(s, mod - 1);
	for(int i = 0; i < N; i++) ans = (ans + s[1 << i]) % mod;
	cout << ans << endl;
	return 0;
}