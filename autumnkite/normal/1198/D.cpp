#include <cstdio>
#include <algorithm>
int n;
char s[55];
int dp[55][55][55][55];
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i){
		scanf("%s", s + 1);
		for (register int j = 1; j <= n; ++j)
			dp[i][j][i][j] = s[j] == '#';
	}
	for (register int lx = 1; lx <= n; ++lx)
		for (register int ly = 1; ly <= n; ++ly)
			if (lx != 1 || ly != 1)
				for (register int x1 = 1, x2; x1 <= n - lx + 1; ++x1)
					for (register int y1 = 1, y2; y1 <= n - ly + 1; ++y1){
						x2 = x1 + lx - 1, y2 = y1 +ly - 1;
						dp[x1][y1][x2][y2] = std :: max(lx, ly);
						for (register int i = x1; i < x2; ++i)
							dp[x1][y1][x2][y2] = std :: min(dp[x1][y1][x2][y2], dp[x1][y1][i][y2] + dp[i + 1][y1][x2][y2]);
						for (register int i = y1; i < y2; ++i)
							dp[x1][y1][x2][y2] = std :: min(dp[x1][y1][x2][y2], dp[x1][y1][x2][i] + dp[x1][i + 1][x2][y2]);
					}
	printf("%d\n", dp[1][1][n][n]);
}