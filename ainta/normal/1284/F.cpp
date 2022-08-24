#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 251000
using namespace std;
int n, Dep[N_], par[N_][20], UF[N_];
vector<int>E[N_], F[N_];
void DFS(int a, int pp) {
	par[a][0] = pp;
	for (int i = 0; i < 18; i++)par[a][i + 1] = par[par[a][i]][i];
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
	}
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	int d = Dep[a] - Dep[b], i;
	for (i = 0; i < 18; i++)if ((d >> i) & 1)a = par[a][i];
	for (i = 17; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Do(int a, int p) {
	int L = LCA(a, p);
	int x = Find(a);
	if (Dep[x] > Dep[L]) {
		printf("%d %d %d %d\n", x, par[x][0], a, p);
		UF[x] = par[x][0];
	}
	else {
		x = p;
		for (int i = 17; i >= 0; i--) {
			if (Dep[x] - Dep[L] >= (1 << i)) {
				int t = par[x][i];
				if (Dep[Find(t)] > Dep[L])x = t;
			}
		}
		x = Find(x);
		if (Dep[x] > Dep[L]) {
			printf("%d %d %d %d\n", x, par[x][0], a, p);
			UF[x] = par[x][0];
		}
		else {
			while (1) {}
		}
	}
}
void Go(int a, int pp) {
	for (auto &x : F[a]) {
		if (x != pp)Go(x, a);
	}
	if (pp) {
		Do(a, pp);
	}
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		F[a].push_back(b);
		F[b].push_back(a);
	}
	for (i = 1; i <= n; i++)UF[i] = i;
	printf("%d\n", n - 1);
	DFS(1, 0);
	Go(1, 0);
}