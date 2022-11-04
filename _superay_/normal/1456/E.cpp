#include <bits/stdc++.h>
using namespace std;
inline void getmin(long long &x, long long y) {
	if (x > y) x = y;
}
int n, m, pos[55];
long long L[55], R[55], C[55], f[55][55][55][4][4];
inline long long calc(int k, int i, int j, int p, int q) {
	if (i == 0 || j == n + 1) return 0;
	int x, y;
	if (p == 0) x = L[i] >> k & 1;
	else if (p == 1) x = !(L[i] >> k & 1);
	else if (p == 2) x = R[i] >> k & 1;
	else x = !(R[i] >> k & 1);
	if (q == 0) y = L[j] >> k & 1;
	else if (q == 1) y = !(L[j] >> k & 1);
	else if (q == 2) y = R[j] >> k & 1;
	else y = !(R[j] >> k & 1);
	return C[k] * (x != y);
};
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &L[i], &R[i]);
		for (int j = m - 1; j >= 0; j--) if ((L[i] >> j & 1) != (R[i] >> j & 1)) {
			pos[i] = j;
			break;
		}
	}
	for (int i = 0; i < m; i++) scanf("%lld", &C[i]);
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i <= n; i++) for (int p = 0; p <= 2; p += 2) for (int q = 0; q <= 2; q += 2)
		f[m][i][i + 1][p][q] = 0;
	for (int k = m - 1; k >= 0; k--) {
		for (int i = 0; i <= n; i++) for (int j = i + 1; j <= n + 1; j++) for (int p = 0; p <= 2; p += 2) for (int q = 0; q <= 2; q += 2) if (f[k + 1][i][j][p][q] < 1e18) {
			for (int x = 0; x < 2; x++) if (!x || (k < pos[i] && !((p == 0 && (L[i] >> k & 1)) || (p == 2 && !(R[i] >> k & 1))))) {
				for (int y = 0; y < 2; y++) if (!y || (k < pos[j] && !((q == 0 && (L[j] >> k & 1)) || (q == 2 && !(R[j] >> k & 1))))) {
					getmin(f[k][i][j][p + x][q + y], f[k + 1][i][j][p][q] + calc(k, i, j, p + x, q + y));
				}
			}
		}
		for (int len = 2; len <= n + 1; len++) for (int i = 0; i <= n - len + 1; i++) {
			int j = i + len;
			if (k) {
				for (int mid = i + 1; mid < j; mid++) for (int p = 0; p < 4; p++) for (int q = 0; q < 4; q++) for (int x = 1; x <= 3; x += 2) if (f[k][i][mid][p][x] < 1e18 && f[k][mid][j][x][q] < 1e18) {
					getmin(f[k][i][j][p][q], f[k][i][mid][p][x] + f[k][mid][j][x][q]);
				}
			} else {
				for (int mid = i + 1; mid < j; mid++) for (int p = 0; p < 4; p++) for (int q = 0; q < 4; q++) for (int x = 0; x < 4; x++) if (f[k][i][mid][p][x] < 1e18 && f[k][mid][j][x][q] < 1e18) {
					getmin(f[k][i][j][p][q], f[k][i][mid][p][x] + f[k][mid][j][x][q]);
				}
			}
		}
	}
	long long ans = 1e18;
	for (int p = 0; p < 4; p++) for (int q = 0; q < 4; q++) getmin(ans, f[0][0][n + 1][p][q]);
	printf("%lld\n", ans);
	return 0;
}