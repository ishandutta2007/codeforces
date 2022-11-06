#include <bits/stdc++.h>
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
using std::max; using std::min;
const int N = 14, M = 105;
int n, m, t[M], f[1 << N][M], g[1 << N][M], h[1 << N][N + M];
struct Point { int x, y; } a[N], b[M];
int dist(Point a, Point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &b[i].x, &b[i].y, &t[i]);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < m; j++)
			if (t[j] > t[j + 1]) std::swap(t[j], t[j + 1]), std::swap(b[j], b[j + 1]);
	memset(f, 0x3f, sizeof f);
	memset(g, ~0x3f, sizeof g);
	memset(h, 0x3f, sizeof h);
	for (int i = 1; i <= n + m; i++) {
		Point now = i <= n ? a[i] : b[i - n];
		for (int j = 1; j < 1 << n; j++)
			for (int k = 0; k < n; k++)
				if (j >> k & 1) chkmin(h[j][i], dist(now, a[k + 1]));
	}
	for (int i = 0; i < n; i++) f[1 << i][0] = 0;
	for (int i = 1; i <= m; i++) g[0][i] = 1;
	int ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++)
				if (!(i >> k & 1)) chkmin(f[i | (1 << k)][j], f[i][j] + h[i][k + 1]);
			for (int k = 1; k <= m; k++)
				if (f[i][j] + h[i][k + n] <= t[k]) chkmax(g[i][k], j + 1);
		}
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k < j; k++)
				if (t[k] + min(h[i][j + n], dist(b[k], b[j])) <= t[j]) chkmax(g[i][j], g[i][k] + 1);
			if (g[i][j] < 0) continue;
			chkmax(ans, g[i][j]);
			for (int k = 0; k < n; k++)
				if (!(i >> k & 1)) chkmin(f[i | (1 << k)][g[i][j]], t[j] + min(h[i][k + 1], dist(b[j], a[k + 1])));
		}
	}
	printf("%d\n", ans);
	return 0;
}