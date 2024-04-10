#include <bits/stdc++.h>
using namespace std;
inline void getmin(int &x, int y) { if (x > y) x = y; }
int n, m, K;
int heng[505][505], shu[505][505];
int dp[15][505][505];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	if (K % 2 == 1) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) printf("%d%c", -1, " \n"[j == m]);
		return 0;
	}
	K /= 2;
	for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) scanf("%d", &heng[i][j]);
	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) scanf("%d", &shu[i][j]);
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dp[0][i][j] = 0;
	for (int d = 1; d <= K; d++) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			if (i > 1) {
				getmin(dp[d][i - 1][j], dp[d - 1][i][j] + shu[i - 1][j]);
			}
			if (i < n) {
				getmin(dp[d][i + 1][j], dp[d - 1][i][j] + shu[i][j]);
			}
			if (j > 1) {
				getmin(dp[d][i][j - 1], dp[d - 1][i][j] + heng[i][j - 1]);
			}
			if (j < m) {
				getmin(dp[d][i][j + 1], dp[d - 1][i][j] + heng[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) printf("%d%c", 2 * dp[K][i][j], " \n"[j == m]);
	return 0;
}