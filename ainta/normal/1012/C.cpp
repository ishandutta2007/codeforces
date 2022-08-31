#include<cstdio>
#include<algorithm>
using namespace std;
int D[5010][2510][4];
int n, w[101000];
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (i = 0; i <= n; i++)for (j = 0; j <= (n >> 1) + 1; j++)for (k = 0; k < 4; k++)D[i][j][k] = 1e9;
	D[0][0][0] = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= (i >> 1) + 1; j++) {
			if (D[i][j][0] < 8e8) {
				int t = D[i][j][0];
				D[i + 1][j][0] = min(D[i + 1][j][0], t);
				if (w[i + 1] >= w[i])D[i + 1][j][1] = min(D[i + 1][j][1], t + w[i + 1] - w[i] + 1);
				if (w[i + 1] >= w[i+2])D[i + 1][j][2] = min(D[i + 1][j][2], t + w[i + 1] - w[i + 2] + 1);
				if (w[i] < w[i + 1])D[i + 1][j + 1][3] = min(D[i + 1][j + 1][3], t);
			}
			if (D[i][j][1] < 8e8) {
				int t = D[i][j][1], h = w[i - 1] - 1;
				D[i + 1][j][0] = min(D[i + 1][j][0], t);
				if (w[i + 1] >= w[i + 2])D[i + 1][j][2] = min(D[i + 1][j][2], t + w[i + 1] - w[i + 2] + 1);
				if (h < w[i + 1])D[i + 1][j + 1][3] = min(D[i + 1][j + 1][3], t);
			}
			if (D[i][j][2] < 8e8) {
				int t = D[i][j][2], h = w[i + 1] - 1;
				D[i + 1][j][0] = min(D[i + 1][j][0], t);
				if (w[i + 1] >= w[i + 2])D[i + 1][j][2] = min(D[i + 1][j][2], t + w[i + 1] - w[i + 2] + 1);
				D[i + 1][j + 1][3] = min(D[i + 1][j + 1][3], t);
			}
			if (D[i][j][3] < 8e8) {
				int t = D[i][j][3];
				if (w[i + 1] < w[i])D[i + 1][j][0] = min(D[i + 1][j][0], t);
				if (w[i + 1] >= w[i])D[i + 1][j][1] = min(D[i + 1][j][1], t + w[i + 1] - w[i] + 1);
				if (w[i + 2] - 1 < w[i]) {
					D[i+1][j][2] = min(D[i + 1][j][2], t + max(w[i + 1] - w[i + 2] + 1,0));
				}
			}
		}
	}
	for (i = 1; i <= (n + 1) / 2; i++) {
		int r = 1e9;
		for (j = 0; j < 4; j++)r = min(r, D[n][i][j]);
		printf("%d ", r);
	}
	puts("");
}