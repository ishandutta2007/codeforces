#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 300015;
int n, q, val[N << 1];
vector<int> e[N << 1];

int fa[N << 1];
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void uni(int u, int v) {fa[find(u)] = find(v);}

int f[21][N << 1], dep[N << 1], dfn[N << 1], clk;

void dfs(int u, int pa) {
	f[0][u] = pa;
	dep[u] = dep[pa] + 1;
	dfn[u] = ++clk;
	rep(j, 1, 20) f[j][u] = f[j - 1][f[j - 1][u]];
	for (int v : e[u]) dfs(v, u);
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int t = dep[u] - dep[v];
	rep(j, 0, 20) if (t >> j & 1) u = f[j][u];
	if (u == v) return u;
	per(j, 0, 20) {
		if (f[j][u] != f[j][v]) {
			u = f[j][u];
			v = f[j][v];
		}
	}
	return f[0][u];
}


#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)


int tag[N << 2];
pii Max[N << 2], Min[N << 2], oMax[N << 2], oMin[N << 2];


void pushup(int p) {
	Max[p] = max(Max[ls], Max[rs]);
	Min[p] = min(Min[ls], Min[rs]);
}

void clear(int p) {Max[p] = mp(-inf, -1); Min[p] = mp(inf, -1);}

void build(int p, int l, int r) {
	clear(p);
	if (l == r) {
		oMax[p] = oMin[p] = mp(dfn[l], l);
		return;
	}
	build(ls, l, mid); build(rs, mid + 1, r);
	oMax[p] = max(oMax[ls], oMax[rs]);
	oMin[p] = min(oMin[ls], oMin[rs]);
}

void down(int p, int v) {
	tag[p] = v;
	if (v == 0) clear(p);
	else Max[p] = oMax[p], Min[p] = oMin[p];
}

void pushdown(int p) {
	if (~tag[p]) down(ls, tag[p]), down(rs, tag[p]);
	tag[p] = -1;
}

void modify(int p, int l, int r, int x, int y, int v) {
	if (x <= l && r <= y) return down(p, v);
	pushdown(p);
	if (x <= mid) modify(ls, l, mid, x, y, v);
	if (y > mid) modify(rs, mid + 1, r, x, y, v);
	pushup(p);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &q);
	int tot = n;
	rep(i, 1, n + n) fa[i] = i;
	memset(val, -1, sizeof val);
	vector<tuple<int, int, int>> vec;
	rep(i, 2, n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		vec.emplace_back(w, u, v);
	}
	sort(all(vec));
	for (auto [w, u, v] : vec) {
		val[++tot] = w;
		e[tot].emplace_back(find(u)); e[tot].emplace_back(find(v));
		uni(u, tot); uni(v, tot);
	}
	dfs(tot, 0);
	memset(tag, -1, sizeof tag);
	build(1, 1, n);
	rep(_, 1, q) {
		int opt, l, r, x;
		scanf("%d", &opt);
		if (opt <= 2) {
			scanf("%d%d", &l, &r);
			modify(1, 1, n, l, r, !(opt - 1));
		} else {
			scanf("%d", &x);
			int res = -1, a = Min[1].se, b = Max[1].se;
			rep(_, 0, 1) {
				if (~a) res = max(res, val[lca(a, x)]);
				swap(a, b);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}