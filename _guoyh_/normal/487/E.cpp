# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int INF = 0x3f3f3f3f;
int n, m, q;
int a[MAXN];
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN];
int gsz = 1;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int stk[MAXN], stp;
bool inst[MAXN];
int dfn[MAXN], low[MAXN], dsz;
int ssz;
int fa1[MAXN];
void tarjan(int nw, int fa){
	stk[++stp] = nw;
	inst[nw] = true;
	dfn[nw] = low[nw] = ++dsz;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if ((i ^ 1) == fa) continue;
		if (!dfn[nxtn]){
			tarjan(nxtn, i);
			low[nw] = min(low[nw], low[nxtn]);
			// printf("nxtn %d %d %d\n", nw, nxtn, low[nxtn]);
			if (low[nxtn] >= dfn[nw]){
				ssz++;
				while (stp > 0){
					int u = stk[stp];
					fa1[u] = ssz + n;
					inst[u] = false;
					stp--;
					if (u == nxtn) break;
				}
				fa1[ssz + n] = nw;
			}
		} else if (inst[nxtn]) low[nw] = min(low[nw], dfn[nxtn]);
	}
}
struct SegTree{
	struct Node{
		int s;
		int ls, rs;
		Node(){
			s = INF;
			ls = rs = 0;
		}
	} t[MAXN * 4];
	int tsz, rt;
	void update(int nw){
		t[nw].s = min(t[t[nw].ls].s, t[t[nw].rs].s);
	}
	void modify(int &nw, int lft, int rgt, int pos, int val){
		if (!nw) nw = ++tsz;
		if (lft == rgt){
			t[nw].s = val;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify(t[nw].ls, lft, mid, pos, val);
		else modify(t[nw].rs, mid + 1, rgt, pos, val);
		update(nw);
	}
	int getmin(int nw, int lft, int rgt, int l, int r){
		if (!nw) return INF;
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1, ans = INF;
		if (l <= mid) ans = min(ans, getmin(t[nw].ls, lft, mid, l, min(mid, r)));
		if (r >= mid + 1) ans = min(ans, getmin(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
		return ans;
	}
} sgt;
multiset <int> w[MAXN];
int sz[MAXN], dep[MAXN], hs[MAXN], tp[MAXN];
void dfsHs(int nw){
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		dep[nxtn] = dep[nw] + 1;
		dfsHs(nxtn);
		if (nw > n) w[nw].insert(a[nxtn]);
		sz[nw] += sz[nxtn];
		if (!hs[nw] || sz[nxtn] > sz[hs[nw]]) hs[nw] = nxtn;
	}
}
void dfsTp(int nw){
	dfn[nw] = ++dsz;
	if (hs[nw]){
		tp[hs[nw]] = tp[nw];
		dfsTp(hs[nw]);
	}
	if (nw <= n) sgt.modify(sgt.rt, 1, n + ssz, dfn[nw], a[nw]);
	else sgt.modify(sgt.rt, 1, n + ssz, dfn[nw], *w[nw].begin());
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == hs[nw]) continue;
		tp[nxtn] = nxtn;
		dfsTp(nxtn);
	}
}
void mod(int nw, int val){
	int pv = a[nw];
	a[nw] = val;
	sgt.modify(sgt.rt, 1, n + ssz, dfn[nw], val);
	if (fa1[nw]){
		w[fa1[nw]].erase(w[fa1[nw]].find(pv));
		w[fa1[nw]].insert(val);
		sgt.modify(sgt.rt, 1, n + ssz, dfn[fa1[nw]], *w[fa1[nw]].begin());
	}
}
int qry(int u, int v){
	int ans = INF;
	while (tp[u] != tp[v]){
		if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
		ans = min(ans, sgt.getmin(sgt.rt, 1, n + ssz, dfn[tp[u]], dfn[u]));
		u = fa1[tp[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	ans = min(ans, sgt.getmin(sgt.rt, 1, n + ssz, dfn[u], dfn[v]));
	if (u > n) ans = min(ans, a[fa1[u]]);
	return ans;
}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	tarjan(1, 0);
	gsz = 0;
	dsz = 0;
	memset(fte, 0, sizeof(fte));
	for (int i = 2; i <= ssz + n; i++){
		addedge(fa1[i], i);
		// printf("%d->%d\n", fa1[i], i);
	}
	dfsHs(1);
	tp[1] = 1;
	dfsTp(1);
	while (q--){
		char op;
		int u, v;
		scanf(" %c", &op);
		scanf("%d%d", &u, &v);
		if (op == 'C') mod(u, v);
		else printf("%d\n", qry(u, v));
	}
	return 0;
}