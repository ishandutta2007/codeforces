#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
#define INF 0x3f3f3f3f3f3f3f3fll
int T, n;
char s[N];
long long a, b, dp[N][2];
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%lld%lld", &n, &a, &b), scanf("%s", s + 1);
		dp[0][0] = b, dp[0][1] = INF;
		for (register int i = 1; i <= n; ++i)
			if (s[i] == '0'){
				dp[i][0] = std :: min(dp[i - 1][0] + a, dp[i - 1][1] + (a << 1)) + b;
				dp[i][1] = std :: min(dp[i - 1][0] + (a << 1), dp[i - 1][1] + a) + (b << 1);
			}
			else dp[i][0] = INF, dp[i][1] = dp[i - 1][1] + a + (b << 1);
		printf("%lld\n", dp[n][0]);
	}
}