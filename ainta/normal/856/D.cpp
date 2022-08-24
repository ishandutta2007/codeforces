#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 201000
struct point {
	int a, b, c;
};
vector<int>E[N_];
vector<point>G[N_];
int n, m, par[N_][20], Dep[N_], Num[N_], Ed[N_], cnt, D[N_], D2[N_];
long long BIT[N_][2];
void DFS(int a, int dep) {
	int i;
	Num[a] = ++cnt;
	Dep[a] = dep;
	for (i = 0; i < E[a].size(); i++)DFS(E[a][i], dep + 1);
	Ed[a] = cnt;
}
int Up(int a, int d) {
	int i = 0;
	while (d) {
		if (d & 1)a = par[a][i];
		d >>= 1; i++;
	}
	return a;
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = Up(a, Dep[a] - Dep[b]);
	for (int i = 17; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
void Ins(int a, int b, int ck) {
	while (a <= n) {
		BIT[a][ck] += b;
		a += (a&-a);
	}
}
long long Sum(int a, int ck) {
	long long r = 0;
	while (a) {
		r += BIT[a][ck];
		a -= (a&-a);
	}
	return r;
}
void Make(int a, int x, int y, int c) {
	int t = D2[a] - Sum(Num[y], 0) + Sum(Num[y], 1) - Sum(Num[x], 0) + Sum(Num[x],1) + c;
	D[a] = max(D[a], t);
}
void Do(int a) {
	int i;
	for (i = 0; i < E[a].size(); i++) {
		Do(E[a][i]);
		D2[a] += D[E[a][i]];
	}
	D[a] = D2[a];
	for (i = 0; i < G[a].size(); i++) {
		Make(a, G[a][i].a, G[a][i].b, G[a][i].c);
	}
	Ins(Num[a], D[a], 0);
	Ins(Ed[a] + 1, -D[a], 0);
	Ins(Num[a], D2[a], 1);
	Ins(Ed[a] + 1, -D2[a], 1);
}
int main() {
	int i, j, a, b, c;
	scanf("%d%d", &n, &m);
	for (i = 2; i <= n; i++) {
		scanf("%d", &par[i][0]);
		E[par[i][0]].push_back(i);
	}
	for (i = 0; i < 17; i++)for (j = 1; j <= n; j++)par[j][i + 1] = par[par[j][i]][i];
	DFS(1, 0);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		G[LCA(a, b)].push_back({ a,b,c });
	}
	Do(1);
	printf("%d\n", D[1]);
}