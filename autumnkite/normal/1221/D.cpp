#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 300005
#define INF 0x3f3f3f3f3f3f3f3fll
int T, n;
long long a[N], b[N], dp[N][4];
int main(){
	T = read();
	while (T--){
		n = read();
		for (register int i = 1; i <= n; ++i) a[i] = read(), b[i] = read();
		for (register int i = 0; i < 4; ++i) dp[1][i] = b[1] * i;
		for (register int i = 2; i <= n; ++i)
			for (register int j = 0; j < 4; ++j){
				dp[i][j] = INF;
				for (register int k = 0; k < 4; ++k)
					if (a[i - 1] + k != a[i] + j) dp[i][j] = std :: min(dp[i][j], dp[i - 1][k] + b[i] * j);
			}
		long long ans = INF;
		for (register int i = 0; i < 4; ++i) ans = std :: min(ans, dp[n][i]);
		printf("%lld\n", ans);
	}
}