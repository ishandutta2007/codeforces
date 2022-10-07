#include <cstdio>
#define N 705
int n, a[N], can[N][N], dp[2][N][N];
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (register int i = 1; i < n; ++i)
		for (register int j = i + 1; j <= n; ++j)
			can[i][j] = gcd(a[i], a[j]) > 1, can[j][i] = can[i][j];
	for (register int i = 1; i <= n; ++i) dp[0][i][i] = dp[1][i][i] = 1;
	for (register int l = 1; l <= n; ++l)
		for (register int i = 1, j; (j = i + l - 1) <= n; ++i)
			for (register int k = i; k <= j; ++k){
				if (!dp[0][k][i] || !dp[1][k][j]) continue;
				if (l == n) return printf("Yes"), 0;
				if (can[i - 1][k]) dp[1][i - 1][j] = 1;
				if (can[k][j + 1]) dp[0][j + 1][i] = 1;
			}
	printf("No");
}