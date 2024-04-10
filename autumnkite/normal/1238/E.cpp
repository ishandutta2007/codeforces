#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
int n, m, val[20][1 << 20], cnt[1 << 20], dp[1 << 20];
char s[100005];
int main(){
	scanf("%d%d%s", &n, &m, s + 1);
	for (register int i = 2; i <= n; ++i){
		int x = s[i - 1] - 'a', y = s[i] - 'a';
		++val[x][1 << y], ++val[y][1 << x];
	}
	for (register int i = 0; i < m; ++i)
		for (register int j = 0; j < (1 << m); ++j)
			val[i][j] = val[i][j & -j] + val[i][j & (j - 1)];
	cnt[0] = 0;
	for (register int i = 1; i < (1 << m); ++i) cnt[i] = cnt[i >> 1] + (i & 1);
	dp[0] = 0;
	for (register int i = 1; i < (1 << m); ++i){
		int k = cnt[i];
		dp[i] = INF;
		for (register int j = 0; j < m; ++j)
			if (i >> j & 1)
				dp[i] = std :: min(dp[i], dp[i ^ (1 << j)] + (val[j][i ^ (1 << j)] - val[j][((1 << m) - 1) ^ i]) * k);
	}
	printf("%d\n", dp[(1 << m) - 1]);
}