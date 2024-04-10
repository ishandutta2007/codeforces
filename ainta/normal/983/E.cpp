#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
#define SZ 262144

using namespace std;
vector<int>E[N_];
int n, par[N_][19], Dep[N_], Num[N_], Ed[N_], cnt, Up[N_][20], ReNum[N_], Res[N_];
struct point {
	int x, y;
	bool operator<(const point &p)const {
		return x < p.x;
	}
};
vector<point>V[N_];

struct Seg {
	int x, y1, y2, ck, num;
	bool operator<(const Seg &p)const {
		return x < p.x;
	}
};
vector<Seg>U[N_];

void DFS(int a) {
	Num[a] = ++cnt;
	ReNum[cnt] = a;
	for (int i = 0; i < 18; i++)par[a][i + 1] = par[par[a][i]][i];
	for (auto &x : E[a]) {
		Dep[x] = Dep[a] + 1;
		par[x][0] = a;
		DFS(x);
	}
	Ed[a] = cnt;
}
int go_Up(int a, int d) {
	int i = 0;
	while (d) {
		if (d & 1)a = par[a][i];
		d >>= 1; i++;
	}
	return a;
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	a = go_Up(a, Dep[a] - Dep[b]);
	for (int i = 18; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
int IT1[SZ + SZ];
void Put1(int a, int b) {
	a += SZ;
	while (a) {
		IT1[a] = min(IT1[a], b);
		a >>= 1;
	}
}
int Get1(int b, int e) {
	b += SZ, e += SZ;
	int r = 1e9;
	while (b <= e) {
		r = min(r, min(IT1[b], IT1[e]));
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
	return r;
}
int CC[N_];
void Make(int num, int u, int x1, int x2, int y1, int y2) {
	int i;
	U[u].push_back({ x1 - 1, y1, y2, -1, num });
	U[u].push_back({ x2, y1, y2, 1, num });
}
int BIT[N_];
void Add(int a, int b) {
	while (a <= n) {
		BIT[a] += b;
		a += (a&-a);
	}
}
int Sum(int a) {
	int r = 0;
	while (a) {
		r += BIT[a];
		a -= (a&-a);
	}
	return r;
}
void Go(int a) {
	if (V[a].empty() || U[a].empty())return;
	sort(V[a].begin(), V[a].end());
	sort(U[a].begin(), U[a].end());
	int pv = 0;
	for (int i = 0; i < U[a].size(); i++) {
		while (pv < V[a].size() && V[a][pv].x <= U[a][i].x) {
			Add(V[a][pv].y, 1);
			pv++;
		}
		CC[U[a][i].num] += U[a][i].ck * (Sum(U[a][i].y2) - Sum(U[a][i].y1 - 1));
	}
	while (pv > 0) {
		pv--;
		Add(V[a][pv].y, -1);
	}
}
int main() {
	int i, a, m, b, j;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		scanf("%d", &a);
		E[a].push_back(i);
	}
	DFS(1);
	scanf("%d", &m);
	for (i = 1; i < SZ + SZ; i++)IT1[i] = 1e9;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		int u = LCA(a, b);
		V[u].push_back({ Num[a],Num[b] });
		V[u].push_back({ Num[b],Num[a] });
		Put1(Num[a], Num[u]);
		Put1(Num[b], Num[u]);
	}
	for (i = 1; i <= n; i++) {
		int t = Get1(Num[i], Ed[i]);
		if (t > Num[i]) t = Num[i];
		Up[i][0] = ReNum[t];
	}
	for (i = 0; i < 18; i++)for (j = 1; j <= n; j++) {
		Up[j][i + 1] = Up[Up[j][i]][i];
	}
	int Q;
	scanf("%d", &Q);
	for (int ii = 0; ii<Q; ii++) {
		scanf("%d%d", &a, &b);
		if (Up[a][18] != Up[b][18]) {
			Res[ii] = -1;
			continue;
		}
		int u = LCA(a, b);
		int r = 0;
		for (i = 18; i >= 0; i--) {
			int t = Up[a][i];
			if (Dep[t] > Dep[u]) {
				a = t;
				r += (1 << i);
			}
			t = Up[b][i];
			if (Dep[t] > Dep[u]) {
				b = t;
				r += (1 << i);
			}
		}
		if (a == u || b == u) {
			Res[ii] = r + 1;
			continue;
		}
		Res[ii] = r + 2;
		Make(ii, u, Num[a], Ed[a], Num[b], Ed[b]);
	}
	for (i = 1; i <= n; i++) {
		Go(i);
	}
	for (i = 0; i < Q; i++) {
		if (CC[i])Res[i]--;
		printf("%d\n", Res[i]);
	}
}