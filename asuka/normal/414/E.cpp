#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)
#define ll long long
using namespace std;

const int N = 100015, M = N * 10;

mt19937_64 rnd(114);

unsigned ll rnk[M];
int rt, tot, Mindep[M], Maxdep[M], mindep[M], id[M], tag[M], dep[M], siz[M], fa[M], ls[M], rs[M], fir[N], las[N];

void init() {mindep[0] = Mindep[0] = 1e9;}

bool ok(int p) {return fir[id[p]] == p || las[id[p]] == p;}

int newnode(int x, int i) {
	tot++;
	rnk[tot] = rnd();
	mindep[tot] = dep[tot] = x; siz[tot] = 1; id[tot] = i;
	Mindep[tot] = 1e9;
	Maxdep[tot] = 0;
	return tot;
}

void down(int p, int v) {
	if (!p || !v) return;
	tag[p] += v;
	mindep[p] += v;
	Mindep[p] += v;
	Maxdep[p] += v;
	dep[p] += v;
}

void pd(int p) {
	down(ls[p], tag[p]);
	down(rs[p], tag[p]);
	tag[p] = 0;
}

void pu(int p) {
	mindep[p] = min({mindep[ls[p]], mindep[rs[p]], dep[p]});
	Mindep[p] = min({Mindep[ls[p]], Mindep[rs[p]], ok(p) ? dep[p] : (int) 1e9});
	Maxdep[p] = max({Maxdep[ls[p]], Maxdep[rs[p]], ok(p) ? dep[p] : 0});
	siz[p] = siz[ls[p]] + siz[rs[p]] + 1;
}

void Split(int p, int k, int &u, int &v) {
	if (!p) return void(u = v = 0);
	pd(p);
	if (siz[ls[p]] + 1 <= k) u = p, Split(rs[u], k - siz[ls[p]] - 1, rs[u], v);
	else v = p, Split(ls[v], k, u, ls[v]);
	fa[ls[p]] = fa[rs[p]] = p;
	pu(p);
}

int merge(int u, int v) {
	if (!u || !v) return u | v;
	int p;
	if (rnk[u] < rnk[v]) pd(p = u), fa[rs[u] = merge(rs[u], v)] = u;
	else pd(p = v), fa[ls[v] = merge(u, ls[v])] = v;
	return pu(p), p;
}

bool isroot(int u) {return ls[fa[u]] != u && rs[fa[u]] != u;}

int rk(int u) {
	int res = siz[ls[u]] + 1;
	for (int f; f = fa[u], !isroot(u); u = f) {
		if (ls[f] != u) res += siz[ls[f]] + 1;
	}
	return res;
}

int query(int p, int k) { // right most vertex with dep = k
	pd(p);
	if (Mindep[rs[p]] <= k && k <= Maxdep[rs[p]]) return query(rs[p], k);
	if (dep[p] == k) return id[p];
	return query(ls[p], k);
}

void update(int p) {
	if (!isroot(p)) update(fa[p]);
	pd(p);
}

void Update(int p) {
	pu(p);
	if (!isroot(p)) Update(fa[p]);
}

int Fir(int u) {return rk(fir[u]);}
int Las(int u) {return rk(las[u]);}
int Dep(int u) {
	update(fir[u]);
	return dep[fir[u]];
}

int Deplca(int u, int v) {
	int l = Fir(u), r = Fir(v);
	if (l > r) swap(l, r);
	int L, M, R;
	Split(rt, r, M, R);
	Split(M, l - 1, L, M);
	int res = mindep[M];
	rt = merge(L, merge(M, R));
	return res;
}

int Dis(int u, int v) {return Dep(u) + Dep(v) - 2 * Deplca(u, v);}

void upK(int u, int k) {
	int l = Fir(u), r = Las(u), dd = Dep(u);
	int L, M, R;
	Split(rt, r, M, R);
	Split(M, l - 1, L, M);
	int v = query(L, dd - k);
	down(M, - k + 1);
	rt = merge(L, R);
	int pos = Las(v);
	Split(rt, pos, L, R);
	M = merge(M, las[v] = newnode(dd - k, v));
	Update(las[v]);
	rt = merge(L, merge(M, R));
}

int Ask(int k) {return query(rt, k + 1);}

int n, q, _dep[N];
vector<int> e[N];

void dfs0(int u, int pa) {
	_dep[u] = _dep[pa] + 1;
	rt = merge(rt, 	fir[u] = las[u] = newnode(_dep[u], u));
	Update(fir[u]);
	for (int v : e[u]) {
		dfs0(v, u);
		rt = merge(rt, las[u] = newnode(_dep[u], u));
		Update(las[u]);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	init();
	rep(i, 1, n) {
		int l, x;
		scanf("%d", &l);
		rep(_, 1, l) {
			scanf("%d", &x);
			e[i].push_back(x);
		}
	}
	dfs0(1, 0);
	rep(_, 1, q) {
		int opt, u, v;
		scanf("%d%d", &opt, &u);
		if (opt == 1) {
			scanf("%d", &v);
			printf("%d\n", Dis(u, v));
		} else if (opt == 2) {
			scanf("%d", &v);
			upK(u, v);
		} else {
			printf("%d\n", Ask(u));
		}
	}
	return 0;
}