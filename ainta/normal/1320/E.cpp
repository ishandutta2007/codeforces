#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#define N_ 201000
#define SZ 262144
#define pli pair<long long,int>
using namespace std;
int n, Num[N_], Ed[N_], cnt, m, K, w[N_], V[N_], ord[N_], Dep[N_], par[N_][20];
int ZZ[N_];
vector<int>E[N_], T[N_], L[N_];
void DFS(int a, int pp) {
	Num[a] = ++cnt;
	ord[cnt] = a;
	par[a][0] = pp;
	for (int i = 0; i < 18; i++)par[a][i + 1] = par[par[a][i]][i];
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
	}
	Ed[a] = cnt;
}
void Add_Edge(int a, int b, int d) {
	T[a].push_back(b);
	T[b].push_back(a);
	L[a].push_back(d);
	L[b].push_back(d);
}
int LCA(int a, int b) {
	if (Dep[a] < Dep[b])return LCA(b, a);
	int d = Dep[a] - Dep[b];
	for (int i = 0; i < 18; i++)if ((d >> i) & 1)a = par[a][i];
	for (int i = 17; i >= 0; i--)if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	if (a != b)a = par[a][0];
	return a;
}
int IT[SZ + SZ];
void Put(int b, int e, int x) {
	b += SZ, e += SZ;
	while (b <= e) {
		IT[b] = IT[e] = x;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
int Get(int t) {
	t += SZ;
	int r = 0;
	while (t) {
		r = max(r, IT[t]);
		t >>= 1;
	}
	return r;
}
long long D[N_], BS = 1e9, Dis[N_];
int P[N_], QQ[N_];

priority_queue<pli>PQ;

void Put2(int a, long long d, int pp) {
	long long t = (d + V[pp] - 1) / V[pp];
	if (D[a] <= t*BS + pp) return;
	D[a] = t * BS + pp;
	Dis[a] = d;
	P[a] = pp;
	PQ.push({ -D[a],a });
}

void Solve() {
	int i;
	scanf("%d%d", &m, &K);
	vector<int>TP, TT;
	for (i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ZZ[a] = i;
		w[i] = a;
		V[i] = b;
		TP.push_back(Num[a]);
	}
	for (i = 1; i <= K; i++) {
		scanf("%d", &QQ[i]);
		TP.push_back(Num[QQ[i]]);
	}
	sort(TP.begin(), TP.end());
	for (auto &t : TP)TT.push_back(t);
	for (i = 1; i < TP.size(); i++) {
		TT.push_back(Num[LCA(ord[TP[i - 1]], ord[TP[i]])]);
	}
	sort(TT.begin(), TT.end());
	TT.resize(unique(TT.begin(), TT.end()) - TT.begin());
	//puts("!");
	for (auto &t : TT) {
		int x = ord[t];
		//printf("%d ", x);
		int pp = Get(t);
		if (pp) {
			pp = ord[pp];
			Add_Edge(pp, x, Dep[x] - Dep[pp]);
		}
		Put(Num[x], Ed[x], t);
	}
	//puts("!");
	for (auto &t : TT) {
		int x = ord[t];
		D[x] = 1e18;
	}
	for (i = 1; i <= m; i++) {
		int a = w[i];
		Put2(a, 0, i);
	}

	while (!PQ.empty()) {
		pli tp = PQ.top();
		PQ.pop();
		int x = tp.second;
		if (D[x] != -tp.first)continue;
		for (int i = 0; i < T[x].size(); i++) {
			Put2(T[x][i], Dis[x] + L[x][i], P[x]);
		}
	}

	for (i = 1; i <= K; i++) {
		printf("%d ", P[QQ[i]]);
	}
	puts("");

	for (auto &t : TT) {
		int x = ord[t];
		Put(Num[x], Ed[x], 0);
		T[x].clear();
		L[x].clear();
	}
}
int main() {
	int i, Q;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	scanf("%d", &Q);
	while (Q--) {
		Solve();
	}
}