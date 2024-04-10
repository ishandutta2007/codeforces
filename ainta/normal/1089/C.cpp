#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, w[510][510], chk[510], U[510][510];
vector<int>E[510];
char p[10];
int main() {
	int i, j, k, c;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (i != j)w[i][j] = 1e9;
	for (i = 0; i < K; i++) {
		scanf("%d", &c);
		int a, b;
		for (j = 0; j < c; j++) {
			scanf("%d", &a);
			if (j) {
				w[a][b] = w[b][a] = 1;
				E[a].push_back(b);
				E[b].push_back(a);
			}
			b = a;
		}
	}
	for (k = 1; k <= n; k++)for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
	for (int TC = 0; TC < n; TC++) {
		for (i = 1; i <= n; i++)chk[i] = 0;
		while (1) {
			int s = 0;
			for (i = 1; i <= n; i++) {
				if (!chk[i])s++;
				for (auto &x : E[i]) {
					U[i][x] = 0;
				}
			}
			for (i = 1; i <= n; i++) {
				if (chk[i])continue;
				for (j = 1; j <= n; j++) {
					for (auto &x : E[j]) {
						if (w[x][i] < w[j][i])U[j][x]++;
					}
				}
			}
			int pv = 0;
			for (i = 1; i <= n; i++) {
				int ck = 0;
				for (auto &x : E[i]) {
					if (U[i][x] * 2 > s) {
						ck = 1;
						break;
					}
				}
				if (!ck) {
					pv = i;
				}
			}
			printf("%d\n", pv);
			fflush(stdout);
			scanf("%s", p);
			if (p[0] == 'F')break;
			int a;
			scanf("%d", &a);
			for (i = 1; i <= n; i++) {
				if (w[pv][i] <= w[a][i])chk[i] = 1;
			}
		}
	}
}