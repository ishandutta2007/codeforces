#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge {
	int a, b, c, num;
	bool operator <(const Edge &p)const {
		return c < p.c;
	}
}w[1010000];
int n, m, UF[101010], chk[1010000];
vector<int>E[101000], L[101000];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Add_Edge(int a, int b, int c) {
	E[a].push_back(b);
	E[b].push_back(a);
	L[a].push_back(c);
	L[b].push_back(c);
}
int par[101000][20], pL[101000][20], Dep[101000], Res[1010000], CKCK[1010000];
void DFS(int a, int pp) {
	par[a][0] = pp;
	for (int i = 0; i < 18; i++) {
		par[a][i + 1] = par[par[a][i]][i];
		pL[a][i + 1] = max(pL[a][i], pL[par[a][i]][i]);
	}
	for (int i = 0; i < E[a].size(); i++) {
		int x = E[a][i], l = L[a][i];
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		pL[x][0] = l;
		DFS(x, a);
	}
}
int Up(int a, int d) {
	int i;
	for (i = 18; i >= 0; i--)if ((d >> i) & 1)a = par[a][i];
	return a;
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = Up(a, Dep[a] - Dep[b]);
	for (int i = 18; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
int Calc(int a, int d) {
	int s = 0, i;
	for (i = 18; i >= 0; i--) {
		if ((d >> i) & 1) {
			s = max(s, pL[a][i]);
			a = par[a][i];
		}
	}
	return s;
}
int Get(int a, int b) {
	int p = LCA(a, b);
	return max(Calc(a, Dep[a] - Dep[p]), Calc(b, Dep[b] - Dep[p]));
}
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &w[i].a, &w[i].b, &w[i].c);
		w[i].num = i;
	}
	for (i = 1; i <= n; i++)UF[i] = i;
	sort(w, w + m);
	for (i = 0; i < m; i++) {
		int a = Find(w[i].a), b = Find(w[i].b);
		if (a != b) {
			UF[a] = b;
			Add_Edge(w[i].a, w[i].b, w[i].c);
			CKCK[w[i].num] = 1;
			chk[i] = 1;
		}
	}
	DFS(1, 0);
	for (i = 0; i < m; i++) {
		if (!chk[i]) {
			Res[w[i].num] = Get(w[i].a, w[i].b);
		}
	}
	for (i = 0; i < m; i++)if (!CKCK[i])printf("%d\n", Res[i]);
}