#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#define N_ 101000
using namespace std;

struct Edge {
	int ed;
	long long l;
	int num;
}EE[N_];

vector<Edge>E[N_];
int n, Q, chk[N_], C[N_], Num[N_], Ed[N_], cnt, ord[N_], par[N_], pN[N_];
long long WH, dis[N_];

struct Tree {
	vector<long long>Mx, K;
	int n;
	void UDT(int nd) {
		Mx[nd] = max(Mx[nd * 2], Mx[nd * 2 + 1]);
	}
	void init(int nd, int b, int e) {
		if (b == e) {
			Mx[nd] = dis[ord[b]];
			return;
		}
		int m = (b + e) >> 1;
		init(nd * 2, b, m);
		init(nd * 2 + 1, m + 1, e);
		UDT(nd);
	}
	void init(int N) {
		n = N;
		int sz = 1;
		while (sz <= n)sz *= 2;
		Mx.resize(sz * 2);
		K.resize(sz * 2);
		init(1, 1, n);
	}
	void Add2(int nd, long long x) {
		Mx[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd*2, K[nd]);
		Add2(nd * 2 + 1, K[nd]);
		K[nd] = 0;
	}
	void Add(int nd, int b, int e, int s, int l, long long x) {
		if (s > l)return;
		if (s <= b && e <= l) {
			Add2(nd, x);
			return;
		}
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)Add(nd * 2, b, m, s, l, x);
		if (l > m)Add(nd * 2 + 1, m + 1, e, s, l, x);
		UDT(nd);
	}
	long long Max(int nd, int b, int e, int s, int l) {
		long long r = -1e18;
		if (s > l)return r;
		if (s <= b && e <= l)return Mx[nd];
		Spread(nd);
		int m = (b + e) >> 1;
		if (s <= m)r = max(r, Max(nd * 2, b, m, s, l));
		if (l > m)r = max(r, Max(nd * 2 + 1, m + 1, e, s, l));
		UDT(nd);
		return r;
	}
	long long Get(int b, int e) {
		return Max(1, 1, n, b, e);
	}
}T[N_];



void DFS(int a, int pp, long long d) {
	dis[a] = d;
	Num[a] = ++cnt;
	ord[cnt] = a;
	C[a] = 1;
	par[a] = pp;
	for (auto &t : E[a]) {
		int x = t.ed;
		if (chk[x] || x == pp)continue;
		pN[x] = t.num;
		DFS(x, a, d + t.l);
		C[a] += C[x];
	}
	Ed[a] = cnt;
}

int get_mid(int a, int pp, int c) {
	for (auto &t : E[a]) {
		int x = t.ed;
		if (chk[x] || x == pp)continue;
		if (C[x] > c)return get_mid(x, a, c);
	}
	return a;
}

struct AA {
	int root, myroot, be, ed, br, er;
};

vector<AA>U[N_];
vector<int>CH[N_];
multiset<long long>Set[N_];
multiset<long long>Ans;

void BEF(int a) {
	if (Set[a].empty())return;
	auto it = Set[a].end();
	long long tt = *(--it);
	if (it != Set[a].begin())tt += *(--it);
	Ans.erase(Ans.find(tt));
}

void AFT(int a) {
	if (Set[a].empty())return;
	auto it = Set[a].end();
	long long tt = *(--it);
	if (it != Set[a].begin())tt += *(--it);
	Ans.insert(tt);
}

void Do(int a) {
	cnt = 0;
	DFS(a, 0, 0);
	if (C[a] == 1)return;
	int m = get_mid(a, 0, C[a] / 2);
	chk[m] = 1;
	for (auto &t : E[m]) {
		int x = t.ed;
		if (chk[x])continue;
		Do(x);
		CH[m].push_back(x);
	}
	chk[m] = 0;
	cnt = 0;
	DFS(m, 0, 0);
	T[m].init(cnt);
	int cur=0;
	for (int i = 2; i <= cnt; i++) {
		int x = ord[i];
		if (par[x] == m)cur = x;
		U[pN[x]].push_back({ m, cur, Num[x],Ed[x], Num[cur], Ed[cur] });
	}
	for (auto &t : CH[m]) {
		Set[m].insert(T[m].Get(Num[t], Ed[t]));
	}
}

void Go(AA t, long long del) {
	int m = t.root;
	BEF(m);
	Set[m].erase(Set[m].find(T[m].Get(t.br, t.er)));
	T[m].Add(1, 1, T[m].n, t.be, t.ed, del);
	Set[m].insert(T[m].Get(t.br, t.er));
	AFT(m);
}
long long Answer() {
	long long r = *--Ans.end();
	printf("%lld\n", r);
	return r;
}

int main() {
	int i;
	scanf("%d%d%lld", &n, &Q, &WH);
	for (i = 1; i < n; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		E[a].push_back({ b,c,i });
		E[b].push_back({ a,c,i });
		EE[i] = { a,c,i };
	}
	Do(1);
	for (i = 1; i <= n; i++)AFT(i);
	long long last = 0;
	while (Q--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		a = (a + last) % (n - 1) + 1;
		b = (b + last) % WH;
		long long del = b - EE[a].l;
		for (auto &t : U[a]) {
			Go(t, del);
		}
		EE[a].l += del;
		last = Answer();
	}
}