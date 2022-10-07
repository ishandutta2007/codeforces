#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int T, n, m, a[15][2005], f[15][4105], g[2005][4105];
std :: pair<int, int> mx[2005];
void solve(){
	n = read(), m = read();
	for (register int i = 1; i <= m; ++i) mx[i] = std :: make_pair(0, i);
	for (register int i = 0; i < n; ++i)
		for (register int j = 1; j <= m; ++j)
			a[i][j] = read(), mx[j].first = std :: min(mx[j].first, -a[i][j]);
	std :: sort(mx + 1, mx + 1 + m);
	m = std :: min(m, n);
	for (register int i = 1; i <= m; ++i)
		for (register int j = 0; j < (1 << n); ++j){
			g[i][j] = 0;
			for (register int k = 0; k < n; ++k){
				int s = 0;
				for (register int p = 0; p < n; ++p)
					if (j >> p & 1) s += a[(p + k) % n][mx[i].second];
				g[i][j] = std :: max(g[i][j], s);
			}
		}
	for (register int i = 1; i <= m; ++i)
		for (register int j = 0; j < (1 << n); ++j){
			f[i][j] = f[i - 1][j];
			for (register int k = j; k; k = (k - 1) & j)
				f[i][j] = std :: max(f[i][j], f[i - 1][j ^ k] + g[i][k]);
		}
	printf("%d\n", f[m][(1 << n) - 1]);
}
int main(){
	T = read();
	while (T--) solve();
}