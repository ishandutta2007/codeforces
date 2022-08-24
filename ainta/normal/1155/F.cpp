#include<cstdio>
#include<algorithm>
#include<vector>
#define MX 14
using namespace std;
int n, m, D[1<<MX][MX][MX], w[MX][MX], Path[1<<MX][MX][MX], OK[1<<MX], DP[1<<MX], PP[1<<MX], PT[1<<MX][3], C[1<<MX];
int DD[1 << MX][MX];
void Add(int a, int b) {
	printf("%d %d\n", a + 1, b + 1);
}
void Print(int bef, int mask) {
	int i, j, x, y;
	if (!bef) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (D[mask][i][j] && w[i][j]) {
					if (i == j)return;
					x = i, y = j;
				}
			}
		}
		Add(x, y);
		while (x != y) {
			int t = Path[mask][x][y];
			Add(y, t);
			mask ^= (1 << y);
			y = t;
		}
	}
	else {
		x = PT[bef|mask][0], y = PT[bef|mask][1];
		int MM = bef | mask;
		if (x == y) {
			for (i = 0; i < n; i++) {
				for (j = i + 1; j < n; j++) {
					if ((bef >> i) & 1) {
						if ((bef >> j) & 1) {
							if (w[i][x] && w[j][x]) {
								Add(i, x);
								Add(j, x);
								return;
							}
						}
					}
				}
			}
		}
		while (x != y) {
			int t = Path[mask][x][y];
			Add(y, t);
			mask ^= (1 << y);
			y = t;
		}
		for (i = 0; i < n; i++) {
			if ((bef >> i) & 1) {
				if (w[PT[MM][0]][i]) {
					Add(i, PT[MM][0]);
					break;
				}
			}
		}
		for (i = 0; i < n; i++) {
			if ((bef >> i) & 1) {
				if (w[PT[MM][1]][i]) {
					Add(i, PT[MM][1]);
					break;
				}
			}
		}
	}
}
int main() {
	int i, a, b, j, k, l;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		w[a][b] = w[b][a] = 1;
	}
	for (i = 0; i < n; i++) {
		D[1 << i][i][i] = 1;
	}
	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (D[i][j][k]){
					for (l = 0; l < n; l++) {
						if ((i >> l) & 1)continue;
						if (!w[k][l])continue;
						D[i | (1 << l)][j][l] = 1;
						Path[i | (1 << l)][j][l] = k;
					}
				}
			}
		}
	}
	for (i = 0; i < (1 << n); i++)for (j = 0; j < n; j++)if ((i >> j) & 1)C[i]++;
	for (i = 0; i < (1 << n); i++) {
		DP[i] = 1e9;
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (D[i][j][k] && (w[k][j] || j == k) && C[i]!=2) {
					OK[i] = 1;
					DP[i] = C[i];
					PP[i] = 0;
				}
			}
		}
	}
	for (i = 1; i < (1 << n); i++) {
		if (DP[i] > 7e7)continue;
		if (C[i] == 1)continue;
		int mask = (1 << n) - 1 - i;
		int V[20], VC = 0;
		for (j = 0; j < n; j++) {
			if ((i >> j) & 1)continue;
			for (k = 0; k < n; k++) {
				if ((i >> k) & 1) {
					if (w[j][k])break;
				}
			}
			if (k != n)V[VC++] = j;
		}
		for (j = 0; j < n; j++) {
			if ((i >> j) & 1)continue;
			for (k = 0; k < n; k++) {
				if (!((i >> k) & 1))continue;
				for (l = k+1; l < n; l++) {
					if (!((i >> l) & 1))continue;
					if (w[k][j] && w[l][j]) {
						if (DP[i | (1 << j)] > DP[i] + 2) {
							DP[i | (1 << j)] = DP[i] + 2;
							PP[i | (1 << j)] = i;
							PT[i | (1<<j)][0] = j;
							PT[i | (1<<j)][1] = j;
						}
					}
				}
			}
		}
		for (j = mask; ; j = (j - 1)&mask) {
			if (!j)break;
			if (C[j] == 1)continue;
			for (k = 0; k < VC; k++) {
				for (l = k + 1; l < VC; l++) {
					if (D[j][V[k]][V[l]]) {
						int d = DP[i] + C[j] + 1;
						if (DP[i | j] > d) {
							DP[i | j] = d;
							PP[i | j] = i;
							PT[i | j][0] = V[k];
							PT[i | j][1] = V[l];
						}
					}
				}
			}
		}
	}
	int t = (1 << n) - 1;
	printf("%d\n", DP[t]);
	while (t) {
		Print(PP[t], t^PP[t]);
		t = PP[t];
	}
}