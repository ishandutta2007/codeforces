#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m, Q, f[1005][1005], a[1005][1005], que[1000005][2];
char str[1005];
inline bool gao(int x, int y) {
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[x][y] == a[nx][ny]) {
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d", &n, &m, &Q);
	for (int i = 1; i <= n; i++) {
		scanf(" %s", str + 1);
		for (int j = 1; j <= m; j++) a[i][j] = str[j] - '0';
	}
	memset(f, -1, sizeof(f));
	int ql = 1, qr = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (gao(i, j)) {
				++qr;
				que[qr][0] = i;
				que[qr][1] = j;
				f[i][j] = 0;
			}
		}
	}
	while (ql <= qr) {
		int x = que[ql][0], y = que[ql][1];
		++ql;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && f[nx][ny] == -1) {
				f[nx][ny] = f[x][y] + 1;
				++qr;
				que[qr][0] = nx;
				que[qr][1] = ny;
			}
		}
	}
	while (Q--) {
		int x, y;
		long long t;
		scanf("%d%d%lld", &x, &y, &t);
		if (f[x][y] == -1) printf("%d\n", a[x][y]);
		else printf("%lld\n", a[x][y] ^ (max(0ll, t - f[x][y]) & 1));
	}
	return 0;
}