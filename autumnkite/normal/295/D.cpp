#include <cstdio>
#define P 1000000007
int n, m, dp[2005][2005], ans;
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= m; ++i) dp[1][i] = 1;
	for (register int i = 2; i <= n; ++i){
		int s = 0;
		dp[i][1] = 1;
		for (register int j = 2; j <= m; ++j)
			(s += dp[i - 1][j]) %= P, dp[i][j] = (dp[i][j - 1] + s) % P;
	}
	for (register int i = 1; i <= n; ++i)
		for (register int j = 2; j <= m; ++j)
			(ans += 1ll * (dp[i][j] - dp[i - 1][j] + P) * dp[n - i + 1][j] % P * (m - j + 1) % P) %= P;
	printf("%d", ans);
}