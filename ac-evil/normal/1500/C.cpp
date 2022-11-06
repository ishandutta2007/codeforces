#include <bits/stdc++.h>
using std::vector; using std::bitset;
const int N = 1505;
int n, m, a[N][N], b[N][N], ta[N], tb[N], used[N], rka[N], rkb[N];
bitset<N> ed, c[N], d[N];
bool cmp1(int x, int y) {
	for (int i = 1; i <= m; i++)
		if (a[x][i] != a[y][i]) return a[x][i] < a[y][i];
	return x < y;
}
bool cmp2(int x, int y) {
	for (int i = 1; i <= m; i++)
		if (b[x][i] != b[y][i]) return b[x][i] < b[y][i];
	return x < y;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	int flag = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &b[i][j]);
			if (b[i][j] != a[i][j]) flag = 0;
		}
	for (int i = 1; i <= n; i++) ta[i] = tb[i] = i;
	std::sort(ta + 1, ta + n + 1, cmp1);
	std::sort(tb + 1, tb + n + 1, cmp2);
	for (int i = 1; i <= n; i++)
		rka[ta[i]] = i, rkb[tb[i]] = i;
	if (flag) { puts("0"); return 0; }
	vector<int> ans;
	ed[n] = 1;
	for (int j = 1; j <= m; j++) {
		c[j][n] = 1;
		for (int i = 1; i < n; i++) {
			if (b[i + 1][j] < b[i][j]) c[j][i] = 1;
			if (b[i + 1][j] != b[i][j]) d[j][i] = 1;
		}
	}
	for (;;) {
		int ok = 0;
		for (int i = 1; i <= m; i++)
			if (!used[i] && ((c[i] & ed).count() == c[i].count()))
				ed |= d[i], used[i] = ok = 1, ans.push_back(i);
		if (!ok) break;
	}
	for (int i = 1, s = 1; i <= n; i++)
		if (ed[i]) {
			for (int x = s; x <= i; x++)
				for (int y = x + 1; y <= i; y++)
					if (ta[rkb[x]] > ta[rkb[y]]) {
						puts("-1"); return 0;
					}
			s = i + 1;
		}
	printf("%d\n", ans.size());
	for (int i = (int)ans.size() - 1; ~i; i--)
		printf("%d ", ans[i]);
	return 0;
}