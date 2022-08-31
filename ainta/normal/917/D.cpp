#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int D[110][110], Mod = 1000000007, n, T[110][110][110];
vector<int>E[110];
int Num[110], Ed[110], ReNum[110], cnt, C[110];
void DFS(int a, int pp) {
	int i, j;
	Num[a] = ++cnt;
	ReNum[cnt] = a;
	C[a] = 1;
	for (i = 0; i < E[a].size(); i++) {
		if (E[a][i] == pp)continue;
		DFS(E[a][i], a);
		C[a] += C[E[a][i]];
	}
	Ed[a] = cnt;
}
void Do(int x) {
	int i, j, k, l;
	int b = Num[x], e = Ed[x];
	for (i = b; i <= e; i++)for (j = 0; j <= C[x]; j++)for (k = 0; k <= C[x]; k++)T[i][j][k] = 0;
	T[b][0][0] = 1;
	for (i = b + 1; i <= e; i++) {
		int y = ReNum[i];
		for (j = 0; j < i-b; j++) {
			for (k = 0; k <= j; k++) {
				if (!T[i - 1][j][k])continue;
				for (l = 1; l <= C[y]; l++) {
					T[Ed[y]][j + C[y]][k + l] = (T[Ed[y]][j + C[y]][k + l] + 1ll * T[i - 1][j][k] * D[y][l]) % Mod;
				}
				T[i][j][k] = (T[i][j][k] + T[i - 1][j][k]) % Mod;
			}
		}
	}
	for (i = 0; i <= C[x]; i++) {
		for (j = 0; j <= C[x]; j++) {
			D[x][j + 1] = (D[x][j + 1] + 1ll * (C[x] - i)*T[e][i][j]) % Mod;
		}
	}
}
int Comb[110][110], R[110], Res[110];
int main() {
	int i, a, b, j;
	for (i = 0; i <= 100; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % Mod;
	}
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	for (i = n; i >= 1; i--) {
		Do(ReNum[i]);
	}
	R[n - 1] = 1;
	for (i = 2; i <= n; i++) {
		int t = D[1][i];
		for (j = 0; j < i - 2; j++) {
			t = 1ll * t*n%Mod;
		}
		R[n - i] = t;
	}
	for (i = 0; i < n; i++) {
		int ck = 1;
		for (j = i; j < n; j++) {
			Res[i] = (Res[i] + 1ll * R[j] * Comb[j][i] % Mod*ck) % Mod;
			ck = Mod - ck;
		}
	}
	for (i = 0; i < n; i++)printf("%d ", Res[i]);
	return 0;
}