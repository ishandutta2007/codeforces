#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 501000
#define SZ 524288
using namespace std;
vector<int>E[N_];
struct QQ {
	int num, b, e;
};
vector<QQ>Q[N_];
int Num[N_], n, w[N_], par[N_], Ed[N_];
long long Dep[N_], Res[N_];
struct Tree {
	long long Mn[SZ+SZ], K[SZ+SZ];
	void UDT(int nd) {
		Mn[nd] = min(Mn[nd * 2], Mn[nd * 2 + 1]);
	}
	void init(int nd, int b, int e) {
		if (b == e) {
			Mn[nd] = Dep[b];
			if (!E[b].empty())Mn[nd] += 1e18;
			return;
		}
		int m = (b + e) >> 1;
		init(nd * 2, b, m);
		init(nd * 2 + 1, m + 1, e);
		UDT(nd);
	}
	void Add2(int nd, long long x) {
		Mn[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void Add(int nd, int b, int e, int s, int l, long long x) {
		if (s > l)return;
		if (b == s&&e == l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if(s<=m)Add(nd * 2, b, m, s, min(m, l), x);
		if(l>m)Add(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x);
		UDT(nd);
	}
	long long Min(int nd, int b, int e, int s, int l) {
		if (s > l)return 1e18;
		if (b == s&&e == l)return Mn[nd];
		Spread(nd);
		int m = (b + e) >> 1;
		long long r = 1e18;
		if (s <= m)r = min(r, Min(nd * 2, b, m, s, min(m, l)));
		if (l > m)r = min(r, Min(nd * 2 + 1, m + 1, e, max(m + 1, s), l));
		return r;
	}
}T;
int cnt;
void DFS(int a) {
	Num[a] = ++cnt;
	for (auto &x : E[a]) {
		Dep[x] = Dep[a] + w[x];
		DFS(x);
	}
	Ed[a] = cnt;
}
void Go(int a) {
	for (auto &t : Q[a]) {
		Res[t.num] = T.Min(1, 1, n, t.b, t.e);
	}
	for (auto &x : E[a]) {
		int b = Num[x], e = Ed[x];
		T.Add(1, 1, n, b, e, -w[x]);
		T.Add(1, 1, n, 1, b-1, w[x]);
		T.Add(1, 1, n, e+1, n, w[x]);
		Go(x);
		T.Add(1, 1, n, b, e, w[x]);
		T.Add(1, 1, n, 1, b - 1, -w[x]);
		T.Add(1, 1, n, e + 1, n, -w[x]);
	}
}
int main() {
	int i, a, QC, b, c;
	scanf("%d%d", &n,&QC);
	for (i = 2; i <= n; i++) {
		scanf("%d%d", &par[i], &w[i]);
		E[par[i]].push_back(i);
	}
	for (i = 1; i <= n; i++) {
		sort(E[i].begin(), E[i].end());
	}
	DFS(1);
	T.init(1, 1, n);
	for (i = 1; i <= QC; i++) {
		scanf("%d%d%d", &a, &b, &c);
		Q[a].push_back({ i,b,c });
	}
	Go(1);
	for (i = 1; i <= QC; i++)printf("%lld\n", Res[i]);
}