#include <cstdio>
#include <cstring>
#include <algorithm>
namespace hh_AK_IOI{
	int n, m;
	char a[21][100005];
	int dp[21][1100005], ans = 0x3f3f3f3f;
	int Main(){
		scanf("%d%d", &n, &m);
		for (register int i = 0; i < n; ++i) scanf("%s", a[i] + 1);
		for (register int j = 1; j <= m; ++j){
			int x = 0;
			for (register int i = 0; i < n; ++i)
				if (a[i][j] == '1') x += 1 << i;
			++dp[0][x];
		}
		for (register int k = 0; k < n; ++k)
			for (register int i = n; i; --i)
				for (register int j = 0; j < (1 << n); ++j)
					dp[i][j] += dp[i - 1][j ^ (1 << k)];
		for (register int i = 0; i < (1 << n); ++i){
			int x = 0;
			for (register int j = 0; j <= n; ++j)
				x += std :: min(j, n - j) * dp[j][i];
			ans = std :: min(ans, x);
		}
		printf("%d", ans);
	}
}
int main(){
	return hh_AK_IOI :: Main(), 0;
}