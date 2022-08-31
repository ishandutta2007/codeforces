#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int TC, w[201000], D[201000][10][10], Path[201000][10][10], Ans[201000], n;
char p[201000];
void Print(int a, int x, int y) {
	vector<int>R1,R2;
	while (a) {
		if (Path[a][x][y]%2 == 0) {
			Ans[a] = 1;
			x = Path[a][x][y] / 2;
		}
		else {
			Ans[a] = 2;
			y = Path[a][x][y] / 2;
		}
		a--;
	}
	for (int i = 1; i <= n; i++)printf("%d", Ans[i]);
	puts("");
}
void Solve() {
	int i, j, k;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 1; i <= n; i++)w[i] = p[i - 1] - '0';
	for (i = 0; i <= n; i++)for (j = 0; j < 10; j++)for (k = 0; k < 10; k++)D[i][j][k] = -1;
	D[0][0][0] = 10;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				if (D[i - 1][j][k] == -1)continue;
				if (j <= w[i] && D[i-1][j][k] >= w[i]) {
					if (D[i][w[i]][k] < D[i - 1][j][k]) {
						D[i][w[i]][k] = D[i - 1][j][k];
						Path[i][w[i]][k] = j * 2;
					}
				}
				if (k <= w[i]) {
					int t = D[i - 1][j][k];
					if (D[i - 1][j][k] == 10)t = w[i];
					if (j <= t && D[i][j][w[i]] < t) {
						D[i][j][w[i]] = t;
						Path[i][j][w[i]] = k * 2 + 1;
					}
				}
			}
		}
	}
	for (i = n; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 0; k < 10; k++) {
				if (D[i][j][k]!=-1) {
					Print(i, j, k);
					return;
				}
			}
		}
	}
	puts("-");
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}