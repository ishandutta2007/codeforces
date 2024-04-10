#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 524288
using namespace std;
vector<int>E[301000];
int n, m, Num[301000], cnt, par[301000], IT[SZ + SZ];
long long BIT[301000];
void Put(int b, int e, int x) {
	b += SZ, e += SZ;
	while (b <= e) {
		IT[b] = min(IT[b], x);
		IT[e] = min(IT[e], x);
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
void Do(int x, int pp) {
	int Mx = x, Mn = x;
	while (x!=pp) {
		x = par[x];
		Mx = max(Mx, x);
		Mn = min(Mn, x);
	}
	Put(1, Mn, Mx);
}
void DFS(int a) {
	int i, x;
	Num[a] = ++cnt;
	for (i = 0; i < E[a].size(); i++) {
		x = E[a][i];
		if (Num[x]) {
			if (Num[x] > Num[a]) {
				Do(x, a);
			}
			continue;
		}
		par[x] = a;
		DFS(x);
	}
}
int M[301000];
struct Query {
	int num, b, e;
	bool operator<(const Query &p)const {
		return e < p.e;
	}
}Q[301000];
long long Res[301000];
void Add( int x, long long a) {
	while (x <= n) {
		BIT[x] += a;
		x += (x&-x);
	}
}
long long GetSum(int x) {
	long long r = 0;
	while (x) {
		r += BIT[x];
		x -= (x&-x);
	}
	return r;
}
int main() {
	int i, a, b, QC;
	for (i = 1; i < SZ + SZ; i++)IT[i] = 1e9;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		if (!Num[i])DFS(i);
	}
	for (i = 1; i <= n; i++) {
		int t = SZ + i, Mn = 1e9;
		while (t) {
			Mn = min(Mn, IT[t]);
			t >>= 1;
		}
		M[i] = Mn;
	}
	scanf("%d", &QC);
	for (i = 0; i < QC; i++) {
		scanf("%d%d", &Q[i].b, &Q[i].e);
		Q[i].num = i;
	}
	sort(Q, Q + QC);
	int pv = 1;
	for (i = 0; i < QC; i++) {
		while (pv <= n && M[pv] <= Q[i].e) {
			Add(pv, M[pv]);
			pv++;
		}
		long long Tot = 1ll * (Q[i].e - Q[i].b+1) * (Q[i].e - Q[i].b + 2) / 2;
		if (pv > Q[i].b) {
			Tot -= 1ll * (pv - Q[i].b) * (Q[i].e+1) - (GetSum(pv - 1) - GetSum(Q[i].b - 1));
		}
		Res[Q[i].num] = Tot;
	}
	for (i = 0; i < QC; i++)printf("%lld\n", Res[i]);
}