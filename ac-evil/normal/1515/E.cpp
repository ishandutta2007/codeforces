#include <bits/stdc++.h>
const int N = 405;
int n, P, f[N][N], g[N], fac[N], ifac[N];
int qpow(int a, int b) {
	int t = 1;
	for (; b; b >>= 1, a = 1LL * a * a % P)
		if (b & 1) t = 1LL * t * a % P;
	return t;
}
int main() {
	scanf("%d%d", &n, &P);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n + 1; i++)
		fac[i] = 1LL * fac[i - 1] * i % P, ifac[i] = 1LL * ifac[i - 1] * qpow(i, P - 2) % P;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= i; j++)
			g[i] = (g[i] + 1LL * fac[i - 1] * ifac[j - 1] % P * ifac[i - j]) % P;
	}
	f[0][0] = 1;
	for (int i = 2; i <= n + 1; i++)
		for (int j = 1; j <= n + 1; j++)
			for (int k = 0; k <= i - 2; k++)
				f[i][j] = (f[i][j] + 1LL * f[k][j - 1] * g[i - k - 1] % P * ifac[i - k - 1]) % P;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + 1LL * f[n + 1][i] * fac[n + 1 - i]) % P;
	printf("%d\n", ans);
	return 0;
}