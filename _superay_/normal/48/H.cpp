#include <bits/stdc++.h>
using namespace std;
const char pat[6][5] = {"....", "####", "\\#.\\", "#//.", ".//#", "\\.#\\"};
int n, m, a, b, c, x, y, tx, ty, ans[105][105];
inline void nxt() {
	y++;
	if (y > m) x++, y = 1;
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	x = y = 1;
	while (a--) {
		ans[x][y] = 1;
		nxt();
	}
	tx = x, ty = y;
	for (int i = 0; i < m; i++) {
		ans[x][y] = (x == tx ? (((y - ty) & 1) ? 2 : 3) : (((ty - y) & 1) ? 3 : 2));
		nxt();
	}
	c -= m;
	while (b--) {
		ans[x][y] = 0;
		nxt();
	}
	tx = x, ty = y;
	while (c--) {
		ans[x][y] = (y >= ty ? (((y - ty) & 1) ? (((x - tx) & 1) ? 3 : 5) : (((x - tx) & 1) ? 2 : 4)) : (((ty - y) & 1) ? (((x - tx) & 1) ? 5 : 3) : (((x - tx) & 1) ? 4 : 2)));
		nxt();
	}
	for (int i = 2; i <= 2 * n + 1; i++, puts("")) for (int j = 2; j <= 2 * m + 1; j++)
		putchar(pat[ans[i / 2][j / 2]][(i % 2) * 2 + (j % 2)]);
	return 0;
}