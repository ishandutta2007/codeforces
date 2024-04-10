#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 301000
using namespace std;
vector<int>E[N_], T[N_], G[N_];
int n, m, Q, Num[N_], Up[N_], cnt, chk[N_], ppp[N_];
void DFS(int a, int pp) {
	Num[a] = ++cnt;
	ppp[a] = pp;
	int r = Num[a];
	for (auto &x : E[a]) {
		if (Num[x]) {
			r = min(r, Num[x]);
			continue;
		}
		T[a].push_back(x);
		DFS(x, a);
		if (Up[x] >= Num[a])chk[x] = 1;
		r = min(r, Up[x]);
	}
	Up[a] = r;
}
void Add_Edge(int a, int b) {
	G[a].push_back(b);
	G[b].push_back(a);
}
int par[N_][20], Dep[N_];
void Do(int a, int pp) {
	par[a][0] = pp;
	for (int i = 0; i < 19; i++)par[a][i + 1] = par[par[a][i]][i];
	for (auto &x : G[a]) {
		if (x != pp) {
			Dep[x] = Dep[a] + 1;
			Do(x, a);
		}
	}
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	int d = Dep[a] - Dep[b], i = 0;
	while (d) {
		if (d & 1)a = par[a][i];
		d >>= 1; i++;
	}
	for (i = 18; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
void Go(int a, int c) {
	if (c)Add_Edge(n + c, a);
	for (auto &x : T[a]) {
		if (chk[x]) {
			cnt++;
			Add_Edge(n + cnt, a);
			Go(x, cnt);
		}
		else Go(x, c);
	}
}
int main() {
	int i, a, b;
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	cnt = 0;
	Go(1, 0);
	Do(1, 0);
	while(Q--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", (Dep[a] + Dep[b] - Dep[LCA(a, b)] * 2) / 2);
	}
}