#include <bits/stdc++.h>
using namespace std;
int mod;
int n, C[405][405], g[405][3], f[405][405];
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &mod);
	for (int i = C[0][0] = 1; i <= n; i++) for (int j = C[i][0] = 1; j <= i; j++)
		C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	for (int k = 0; k < 3; k++) g[0][k] = 1;
	g[1][0] = g[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 1; j <= i; j++) {
				g[i][k] = (g[i][k] + 1ll * g[j - 1][k ? 2 : 1] * g[i - j][k == 2 ? 2 : 1] % mod * C[i - 1][j - 1]) % mod;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = g[i][0];
		for (int j = 1; j < i; j++) {
			for (int k = 1; k <= i - 2 && k <= j; k++) {
				f[i][j] = (f[i][j] + 1ll * f[i - k - 1][j - k] * C[j][k] % mod * g[k][0]) % mod;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = (ans + f[n][i]) % mod;
	printf("%d\n", ans);
	return 0;
}