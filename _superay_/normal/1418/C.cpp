#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], dp[N][2];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 0x3f3f3f3f;
		dp[0][1] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = dp[i - 1][1] + a[i];
			if (i > 1) dp[i][0] = min(dp[i][0], dp[i - 2][1] + a[i - 1] + a[i]);
			dp[i][1] = dp[i - 1][0];
			if (i > 1) dp[i][1] = min(dp[i][1], dp[i - 2][0]);
		}
		printf("%d\n", min(dp[n][0], dp[n][1]));
	}
	return 0;
}