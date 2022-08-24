#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int D[30][1<<12];
int w[2010][12], TP[30][12], G[30][1<<12];
int n, m;
struct point{
	int Mx, num;
	bool operator<(const point &p)const {
		return Mx < p.Mx;
	}
}T[2010];
void Solve() {
	int i, j, k;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 1; j <= n; j++)scanf("%d", &w[j][i]);
	}
	for (i = 1; i <= n; i++) {
		T[i].Mx = 0;
		T[i].num = i;
		for (j = 0; j < m; j++) {
			T[i].Mx = max(T[i].Mx, w[i][j]);
		}
	}
	sort(T + 1, T + n + 1);
	int cnt = 0;
	for (i = max(1, n - m + 1); i <= n; i++) {
		int x = T[i].num;
		cnt++;
		for (j = 0; j < m; j++)TP[cnt][j] = w[x][j];
	}
	n = cnt;
	for (i = 1; i <= n; i++)for (j = 0; j < m; j++)w[i][j] = TP[i][j];
	for (i = 0; i <= n; i++)for (j = 0; j < (1 << m); j++)D[i][j] = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j < (1 << m); j++) {
			vector<int>T;
			for (k = 0; k < m; k++)if ((j >> k) & 1)T.push_back(k);
			G[i][j] = 0;
			for (k = 0; k < m; k++) {
				int s = 0;
				for (auto &t : T) {
					s += w[i][(t + k) % m];
				}
				G[i][j] = max(G[i][j], s);
			}
		}
		for (j = 0; j < (1 << m); j++) {
			int mask = (1 << m) - 1 - j;
			for (k = mask;; k = (k - 1)&mask) {
				D[i][j | k] = max(D[i][j | k], D[i - 1][j] + G[i][k]);
				if (!k)break;
			}
		}
	}
	printf("%d\n", D[n][(1 << m) - 1]);
}
int main() {
	int i, TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}