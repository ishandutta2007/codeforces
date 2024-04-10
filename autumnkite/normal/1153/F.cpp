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
#define N 2005
#define P 998244353
int n, k, l, fac[N], dp[N << 1][N], ans;
int qpow(int a, int b = P - 2){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
int main(){
	n = read(), k = read(), l = read();
	fac[0] = 1;
	for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	dp[0][0] = 1;
	for (register int i = 1; i <= (n << 1); ++i)
		for (register int j = 0; j <= i && j <= n; ++j){
			if (j) dp[i][j] = dp[i - 1][j - 1];
			dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j + 1] * (j + 1)) % P;
		}
	for (register int i = 1; i <= (n << 1); ++i)
		for (register int j = k; j <= i && j <= n; ++j)
			ans = (ans + 1ll * dp[i][j] * dp[(n << 1) - i][j] % P * fac[j]) % P;
	ans = 1ll * ans * l % P * qpow((n << 1) + 1) % P * qpow(dp[n << 1][0]) % P;
	printf("%d", ans);
}