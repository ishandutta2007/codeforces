#include <bits/stdc++.h>
using namespace std;
int n, a[105], b[105], dp[105][10005];
int main() {
	scanf("%d", &n);
	memset(dp, 0xbf, sizeof(dp));
	dp[0][0] = 0;
	int ss = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &b[i], &a[i]);
		ss += a[i];
		for (int j = i; j >= 1; j--) {
			for (int k = 10000; k >= b[i]; k--) {
				if (dp[j - 1][k - b[i]] >= 0) dp[j][k] = max(dp[j][k], dp[j - 1][k - b[i]] + a[i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		double ans = -1.0;
		for (int j = 0; j <= 10000; j++) if (dp[i][j] >= 0) {
			ans = max(ans, min(1.0 * j, 0.5 * dp[i][j] + 0.5 * ss));
		}
		printf("%.10lf%c", ans, " \n"[i == n]);
	}
	return 0;
}