#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mod = 1000000007;
inline void Add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int n, m, lim, C[N][N], f[2][N][N][N];
int main() {
	for (int i = C[0][0] = 1; i <= 100; i++)
		for (int j = C[i][0] = 1; j <= i; j++)
			C[i][j] = min(C[i - 1][j - 1] + C[i - 1][j], 101);
	scanf("%d%d%d", &n, &m, &lim);
	for (int i = 1; i <= n; i++) f[1][i][i][1] = 1;
	int ans = 0;
	for (int i = 2; i <= m; i++) {
		int cur = i & 1, lst = cur ^ 1;
		for (int j = 1; j <= n; j++)
			for (int k = 0; k <= j; k++)
				for (int l = 1; l <= lim; l++)
					f[cur][j][k][l] = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= lim; l++) if (f[lst][j][k][l]) {
					for (int t = k; t <= n - j; t++) if (l * C[t - 1][k - 1] <= lim) {
						Add(f[cur][j + t][t - k][l * C[t - 1][k - 1]], f[lst][j][k][l]);
					}
				}
			}
		}
		int sum = 0;
		for (int j = 2; j <= n; j++) {
			for (int l = 1; l <= lim; l++) Add(sum, f[cur][j][0][l]);
		}
		ans = (ans + 1ll * sum * (m - i + 1)) % mod;
	}
	printf("%d\n", ans);
	return 0;
}