#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
double D[60][60][60], Comb[60][60], F[60];
double S[60][60], T[60][60], TP[60], w[60], SS[60];
bool vis[60][60];
int n, C[60];
vector<int>E[60];
double Prob(int a, int b, int c, int d) {
	return Comb[c][d] * Comb[a - c][b - d] / Comb[a][b];
}
void DFS(int a, int pp) {
	C[a] = 1;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		DFS(x, a);
		C[a] += C[x];
	}
	if (vis[pp][a])return;
	vis[pp][a] = 1;
	int i, j, k, s = 0, l;
	for (i = 0; i < C[a]; i++) {
		for (j = 0; j < C[a]; j++)S[i][j] = T[i][j] = 0.0;
		S[i][0] = 1.0;
	}
	for (auto &x : E[a]) {
		if (x == pp)continue;
		SS[0] = 0.0;
		for (j = 0; j < C[x]; j++) {
			TP[j] = D[a][x][j];
			SS[j + 1] = SS[j] + TP[j];
		}
		for (j = 0; j <= C[x]; j++)w[j] = 0;
		for (j = 0; j < C[x]; j++) {
			w[j + 1] += TP[j] * Prob(C[x], j + 1, 1, 1);
			w[j] += Prob(C[x],j,1,0) * (SS[C[x]] - SS[j]) / (C[x]-j) * 0.5;
		}
		for (j = 0; j < C[a]; j++) {
			for (k = 0; k <= s; k++) {
				for (l = 0; l <= C[x]; l++) {
					T[j][k + l] += S[j][k] * w[l] * Prob(C[a] - s - 1, j - k, C[x], l);
				}
			}
		}
		s += C[x];
		for (j = 0; j < C[a]; j++)for (k = 0; k <= s; k++) {
			S[j][k] = T[j][k];
			T[j][k] = 0.0;
		}
	}
	for (i = 0; i < C[a]; i++)D[pp][a][i] = S[i][i];
	if (!pp)printf("%.10f\n", D[pp][a][0]);
}
int main() {
	int i, a, b, j, k;
	scanf("%d", &n);
	for (i = 0; i < 60; i++) {
		for (j = 0; j <= i; j++) {
			double t = 1;
			for (k = 1; k <= j; k++) t = t*(i - k + 1) / k;
			Comb[i][j] = t;
		}
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		DFS(i, 0);
	}
}