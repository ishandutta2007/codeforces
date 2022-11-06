#include <bits/stdc++.h>
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define chkmin(a, b) a = Min(a, b)
using std::queue;
const int N = 505;
int n, m, k, a[N][N], b[N][N], c[21][21][11];
struct node { int x, y, step; } Q[1000005];
int main() {
	scanf("%d%d%d", &n, &m, &k);
	// double begin = clock();
	// srand(time(0));
	// n = 500, m = 500, k = 20;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			// a[i][j] = rand() % 1000000 + 1;
			scanf("%d", &a[i][j]); // (i,j) <-> (i, j+1)
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			// a[i][j] = rand() % 1000000 + 1;
			scanf("%d", &b[i][j]); // (i,j) <-> (i+1, j)
	if (k & 1) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				printf("-1%c", " \n"[j == m]);
		return 0;
	}
	k /= 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			memset(c, 0x3f, sizeof c);
			c[k][k][0] = 0;
			for (int layer = 0; layer < k; layer++)
				for (int x = k - layer; x <= k + layer; x++) {
					int delta = Min(x - (k - layer), (k + layer) - x);
					for (int y = k - delta; y <= k + delta; y++) {
						int nx = i + x - k, ny = j + y - k;
						if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
						if (nx > 1) chkmin(c[x - 1][y][layer + 1], c[x][y][layer] + b[nx - 1][ny]);
						if (nx < n) chkmin(c[x + 1][y][layer + 1], c[x][y][layer] + b[nx][ny]);
						if (ny > 1) chkmin(c[x][y - 1][layer + 1], c[x][y][layer] + a[nx][ny - 1]);
						if (ny < m) chkmin(c[x][y + 1][layer + 1], c[x][y][layer] + a[nx][ny]);
					}
				}
			int ans = 1LL << 30;
			for (int _i = 0; _i <= k; _i++)
				for (int _j = k - _i; _j <= k + _i; _j++)
					ans = std::min(ans, std::min(c[_i][_j][k], c[k * 2 - _i][_j][k]));
			printf("%d%c", ans * 2, " \n"[j == m]);
		}
	// printf("%.4lf\n", (clock() - begin) / CLOCKS_PER_SEC);
	return 0;
}