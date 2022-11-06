#include <bits/stdc++.h>
const int N = 1005, P = 998244353;
char a[N], b[N];
int n, m, f[N][N][2], g[N][2];
void upd(int &a, int b) { (a += b) >= P && (a -= P); }
int main() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		g[i][0] = a[i] == a[i - 1] ? 1 : g[i - 1][0] + 1;
	for (int i = 1; i <= m; i++)
		g[i][1] = b[i] == b[i - 1] ? 1 : g[i - 1][1] + 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (i < n) upd(f[i + 1][j][0], 1);
			if (j < m) upd(f[i][j + 1][1], 1);
			if (i < n) {
				if (a[i + 1] != a[i]) upd(f[i + 1][j][0], f[i][j][0]);
				if (a[i + 1] != b[j]) upd(f[i + 1][j][0], f[i][j][1]);
			}
			if (j < m) {
				if (b[j + 1] != a[i]) upd(f[i][j + 1][1], f[i][j][0]);
				if (b[j + 1] != b[j]) upd(f[i][j + 1][1], f[i][j][1]);
			}
			if (i > 0 && j > 0) upd(ans, f[i][j][0]), upd(ans, f[i][j][1]);
		}
	for (int i = 1; i <= n; i++) ans = (ans - 1LL * m * g[i][0] % P + P) % P;
	for (int i = 1; i <= m; i++) ans = (ans - 1LL * n * g[i][1] % P + P) % P;
	printf("%d", ans);
	return 0;
}