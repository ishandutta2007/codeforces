#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
vector<int>E[N_], F[N_], G[N_];
int v[N_], SCC[N_], ord[N_], cnt, Dep[N_], U[N_], Root[N_], OO[60], UU[60], vv[N_];
int n, m, K, head, tail, MM[60];
int D[N_][10][51], C[N_][10][51];
char p[N_][60];
void DFS1(int a) {
	v[a] = 1;
	for (auto &x : E[a]) {
		if (!v[x]) {
			DFS1(x);
		}
	}
	ord[++cnt] = a;
}
void DFS2(int a) {
	SCC[a] = cnt;
	G[cnt].push_back(a);
	for (auto &x : F[a]) {
		if (!SCC[x])DFS2(x);
	}
}
void DFS3(int a) {
	vv[a] = 1;
	for (auto &x : E[a]) {
		if (!vv[x] && SCC[a] == SCC[x]) {
			Dep[x] = Dep[a] + 1;
			DFS3(x);
		}
	}
}
int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	//freopen("input.txt", "r", stdin);
	int i, a, b, j, k;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		F[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i]);
	}
	for (i = 1; i <= n; i++) {
		if (!v[i]) {
			DFS1(i);
		}
	}
	cnt = 0;
	for (i = n; i >= 1; i--) {
		if (!SCC[ord[i]]) {
			cnt++;
			Root[cnt] = ord[i];
			DFS2(ord[i]);
		}
	}
	for (i = 1; i <= cnt; i++) {
		DFS3(Root[i]);
	}
	int BS = K * 100000;
	for (i = 1; i <= cnt; i++) {
		int t = K;
		for (auto &x : G[i]) {
			for (auto &y : E[x]) {
				if (SCC[y] != i)continue;
				t = gcd(Dep[y] - Dep[x] - 1 + BS, t);
			}
		}
		U[i] = t;
	}
	int cc = 0;
	for (i = 1; i <= K; i++) {
		if (K%i == 0) {
			OO[i] = cc;
			UU[cc] = i;
			cc++;
		}
	}

	for (i = 1; i <= cnt; i++) {
		for (j = 0; j < cc; j++) {
			for (auto &x : G[i]) {
				for (k = 0; k < UU[j]; k++)MM[k] = 0;
				int tt = (Dep[x] - Dep[Root[i]] + BS) % UU[j];
				for (k = 0; k < K; k++) {
					MM[k%UU[j]] |= p[x][(k + tt) % K] - '0';
				}
				for (k = 0; k < UU[j]; k++)C[i][j][k] += MM[k];
			}
		}
	}
	for (i = 1; i <= cnt; i++)for (j = 0; j < cc; j++)for (k = 0; k < UU[j]; k++)D[i][j][k] = -1e9;
	int st = SCC[1];
	D[st][OO[U[st]]][0] = C[st][OO[U[st]]][0];

	for (i = 1; i <= cnt; i++) {
		for (j = 0; j < cc; j++) {
			for (k = 0; k < UU[j]; k++) {
				if (D[i][j][k] < 0)continue;
				for (auto &x : G[i]) {
					int d = (k + Dep[x] - Dep[Root[i]] + BS) % UU[j];
					for (auto &y : E[x]) {
						int tt = SCC[y];
						if (tt == i)continue;

						int TT = OO[gcd(U[tt], UU[j])];

						int nd = (d + 1 - Dep[y] + Dep[Root[tt]] + BS) % UU[TT];


						int cur = OO[U[tt]];
						for (int l = nd; l < U[tt]; l += UU[TT]) {
							D[tt][cur][l] = max(D[tt][cur][l], D[i][j][k] + C[tt][cur][l]);
						}
					}
				}
			}
		}
	}
	int res = 0;
	for (i = 1; i <= cnt; i++)for (j = 0; j < cc; j++)for (k = 0; k < UU[j]; k++)res = max(res, D[i][j][k]);
	printf("%d\n", res);
}