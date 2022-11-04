#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, psr[2005][2005], psc[2005][2005], f[2005][2005][2], K[2005][2005][2], psf[2005][2005][2];
char a[2005][2005];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" %s", a[i] + 1);
		for (int j = 1; j <= m; j++) {
			psr[i][j] = psr[i][j - 1] + (a[i][j] == 'R' ? 1 : 0);
			psc[i][j] = psc[i - 1][j] + (a[i][j] == 'R' ? 1 : 0);
		}
	}
	f[1][1][0] = f[1][1][1] = 1;
	psf[1][1][0] = psf[1][1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1, k = 1; j <= m; j++) {
			while (k < j && psr[i][m] - m + j > psr[i][k]) k++;
			K[i][j][0] = k;
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1, k = 1; i <= n; i++) {
			while (k < i && psc[n][j] - n + i > psc[k][j]) k++;
			K[i][j][1] = k;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (i != 1 || j != 1) {
			f[i][j][0] = (psf[i][j - 1][1] - psf[i][K[i][j][0] - 1][1] + mod) % mod;
			psf[i][j][0] = (psf[i - 1][j][0] + f[i][j][0]) % mod;
			f[i][j][1] = (psf[i - 1][j][0] - psf[K[i][j][1] - 1][j][0] + mod) % mod;
			psf[i][j][1] = (psf[i][j - 1][1] + f[i][j][1]) % mod;
		}
	}
	if (n == 1 && m == 1) puts("1");
	else printf("%d\n", (f[n][m][0] + f[n][m][1]) % mod);
	return 0;
}