#include<cstdio>
#include<algorithm>
using namespace std;
int D[51][51][51];
struct point {
	int l, r, h, c;
}w[51];
int n, H, m;
int main() {
	int i, j, k;
	scanf("%d%d%d", &n, &H, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &w[i].l, &w[i].r, &w[i].h, &w[i].c);
	}
	for (i = 1; i <= H; i++) {
		for (int L = 1; L <= n; L++) {
			for (int b = 1; b <= n - L + 1; b++) {
				int e = b + L - 1;
				D[i][b][e] = D[i - 1][b][e];
				for (k = b; k <= e; k++) {
					int s = D[i][b][k - 1] + D[i][k + 1][e] + i * i;

					for (j = 1; j <= m; j++) {
						if (w[j].l >= b && w[j].r <= e && w[j].l <= k && w[j].r >= k && w[j].h<i)s -= w[j].c;
					}
					D[i][b][e] = max(D[i][b][e], s);
				}
			}
		}
	}
	printf("%d\n", D[H][1][n]);
}