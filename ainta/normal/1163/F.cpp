#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define SZ 262144
#define N_ 201000
#define pli pair<long long, int>
using namespace std;
vector<int>E[N_], F[N_], Num[N_], L[N_];
int n, m, st, ed, C, w[N_], par[N_], P[N_], Q, pN[N_], chk[N_];
long long D[N_], FD[N_], INF = 1e18, IT[SZ + SZ];
priority_queue<pli>PQ;
int top;
struct Edge {
	int a, b, c;
}Ed[N_];
void Push(int a, int p, int pn, long long d) {
	if (D[a] <= d)return;
	par[a] = p;
	pN[a] = pn;
	D[a] = d;
	PQ.push({ -d,a });
}
void Dijk(int a) {
	int i;
	for (i = 1; i <= n; i++)D[i] = INF, par[i] = pN[i] = 0;
	top = 0;
	Push(a, 0, 0, 0);
	while (!PQ.empty()) {
		auto tp = PQ.top();
		PQ.pop();
		if (tp.first != -D[tp.second])continue;
		int x = tp.second;
		for (i = 0; i < E[x].size(); i++) {
			Push(E[x][i], x, Num[x][i], D[x] + L[x][i]);
		}
	}
}
void DFS(int a) {
	int i;
	if (!P[a])P[a] = P[par[a]];
	for (i = 0; i < F[a].size(); i++) {
		DFS(F[a][i]);
	}
}
void Ins(int b, int e, long long x) {
	b += SZ, e += SZ;
	while (b <= e) {
		IT[b] = min(IT[b], x);
		IT[e] = min(IT[e], x);
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
long long Min(int a) {
	long long r = INF;
	a += SZ;
	while (a) {
		r = min(r, IT[a]);
		a >>= 1;
	}
	return r;
}
int main() {
	int i, a, b, d, j;
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		E[a].push_back(b);
		L[a].push_back(d);
		E[b].push_back(a);
		L[b].push_back(d);
		Num[a].push_back(i);
		Num[b].push_back(i);
		Ed[i] = { a,b,d };
	}
	st = 1, ed = n;
	Dijk(ed);
	for (i = 1; i <= n; i++)FD[i] = D[i];
	Dijk(st);
	for (i = 1; i <= n; i++) {
		if (par[i])F[par[i]].push_back(i);
	}
	vector<int>U;
	a = ed;
	U.push_back(a);
	while (a!=st) {
		a = par[a];
		U.push_back(a);
	}
	reverse(U.begin(), U.end());
	for (i = 0; i < U.size(); i++) {
		P[U[i]] = i + 1;
		if (i) {
			chk[pN[U[i]]] = 1;
		}
	}
	DFS(st);
	for (i = 1; i < SZ + SZ; i++)IT[i] = INF;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < E[i].size(); j++) {
			a = i, b = E[i][j];
			if (P[a] >= P[b])continue;
			if (chk[Num[i][j]])continue;
			Ins(P[a], P[b] - 1, D[a] + FD[b] + L[i][j]);
		}
	}
	while (Q--) {
		int pv;
		scanf("%d%d", &pv, &d);
		int a = Ed[pv].a, b = Ed[pv].b;
		if (!chk[pv]) {
			long long res = D[ed];
			res = min(res, min(D[a] + FD[b], D[b] + FD[a]) + d);
			printf("%lld\n", res);
			continue;
		}
		long long res = D[ed] + d - Ed[pv].c;
		res = min(res, Min(min(P[a], P[b])));
		printf("%lld\n", res);
	}
}