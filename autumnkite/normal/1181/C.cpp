#include <cstdio>
#include <algorithm>
int n, m;
char a[1005][1005];
int h[1005], cnt, x[1005], y[1005];
long long ans;
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
	for (register int j = 1; j <= m; ++j){
		for (register int i = 1; i <= n; ++i) if (j == 1 || a[i][j] != a[i][j - 1]) h[i] = 1; else ++h[i];
		cnt = 0;
		for (register int l = 1, r = 1; l <= n; l = r + 1, r = l){
			while (r < n && a[r][j] == a[r + 1][j]) ++r;
			++cnt, x[cnt] = l, y[cnt] = r;
		}
		for (register int i = 2; i < cnt; ++i)
			if (y[i - 1] - x[i - 1] >= y[i] - x[i] && y[i + 1] - x[i + 1] >= y[i] - x[i]){
				int s = 0x3f3f3f3f;
				for (register int k = y[i - 1] - y[i] + x[i]; k <= x[i + 1] + y[i] - x[i]; ++k)
					s = std :: min(s, h[k]);
				ans += s;
			}
	}
	printf("%lld", ans);
}