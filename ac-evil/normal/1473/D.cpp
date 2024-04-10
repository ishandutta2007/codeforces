#include <bits/stdc++.h>
using std::max; using std::min;
const int N = 200005;
int T, n, m;
char s[N];
int a[N], f[19][N], g[19][N];
void build(int n) {
	for (int i = 0; i < n; i++) f[0][i] = g[0][i] = a[i];
	for (int i = 1; i < 19; i++)
		for (int j = 0; j < n - (1<<i-1); j++)
			f[i][j] = max(f[i-1][j], f[i-1][j+(1<<i-1)]),
			g[i][j] = min(g[i-1][j], g[i-1][j+(1<<i-1)]);
}
int qmax(int l, int r) {
	int i = log2(r-l+1);
	return max(f[i][l], f[i][r-(1<<i)+1]);
}
int qmin(int l, int r) {
	int i = log2(r-l+1);
	return min(g[i][l], g[i][r-(1<<i)+1]);
}
int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		scanf("%s", s);
		for (int i = 1; i <= n; i++)
			a[i] = a[i-1] + (s[i-1] == '-' ? -1 : 1);//, printf("{%d}", a[i]);
		build(n+1);
		while (m--) {
			int l, r; scanf("%d%d", &l, &r);
			int mxl = qmax(0, l-1);
			int mnl = qmin(0, l-1);
			int mxr = a[l-1] + qmax(r, n) - a[r];
			int mnr = a[l-1] + qmin(r, n) - a[r];
			//printf("(%d, %d, %d, %d)[%d]\n", mxl, mxr, mnl, mnr, qmax(1, 1));
			printf("%d\n", max(mxl, mxr) - min(mnl, mnr) + 1);
		}
	}
	return 0;
}