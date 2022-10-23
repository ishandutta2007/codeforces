# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct Edge{
	int t, nxt;
} g[MAXN * 2];
struct Node{
	ll d;
	int on, en;
	Node operator + (const Node &o) const{
		Node ans = (Node){d + o.d, on + o.on, en + o.en};
		return ans;
	}
	Node operator + (const ll &o) const{
		Node ans = *this;
		ans.d += (on + en) * (o / 2);
		if (o % 2 == 1){
			ans.d += en;
			swap(ans.on, ans.en);
		} else if (o % 2 == -1){
			ans.d -= on;
			swap(ans.on, ans.en);
		}
		return ans;
	}
};
struct Tree{
	Node s;
	ll tag;
	int ls, rs;
} t[MAXN * 4];
ll ans;
int n, gsz, tsz, cnt, rt;
int fte[MAXN], dep[MAXN], dfn[MAXN], a[MAXN], sz[MAXN];
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
void update(int nw){
	t[nw].s = t[t[nw].ls].s + t[t[nw].rs].s;
}
void push_down(int nw){
	t[t[nw].ls].s = t[t[nw].ls].s + t[nw].tag;
	t[t[nw].rs].s = t[t[nw].rs].s + t[nw].tag;
	t[t[nw].ls].tag += t[nw].tag;
	t[t[nw].rs].tag += t[nw].tag;
	t[nw].tag = 0;
}
int build(int lft, int rgt){
	int nw = ++tsz;
	if (lft == rgt){
		t[nw].s = (Node){(dep[a[lft]] + 1) / 2, (dep[a[lft]] & 1), !(dep[a[lft]] & 1)};
		return nw;
	}
	int mid = (lft + rgt) >> 1;
	t[nw].ls = build(lft, mid);
	t[nw].rs = build(mid + 1, rgt);
	update(nw);
	// printf("lrs %d %d %lld\n", lft, rgt, t[nw].s.d);
	return nw;
}
void modify(int nw, int lft, int rgt, int l, int r, ll nm){
	if (lft == l && rgt == r){
		t[nw].tag += nm;
		t[nw].s = t[nw].s + nm;
		return;
	}
	push_down(nw);
	int mid = (lft + rgt) >> 1;
	if (l <= mid) modify(t[nw].ls, lft, mid, l, min(mid, r), nm);
	if (r >= mid + 1) modify(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, nm);
	update(nw);
}
void dfs1(int nw, int fa){
	dfn[nw] = ++cnt;
	a[cnt] = nw;
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dep[nxtn] = dep[nw] + 1;
		dfs1(nxtn, nw);
		sz[nw] += sz[nxtn];
	}
}
void dfs2(int nw, int fa){
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		modify(rt, 1, n, 1, n, 1);
		modify(rt, 1, n, dfn[nxtn], dfn[nxtn] + sz[nxtn] - 1, -2);
		dfs2(nxtn, nw);
		modify(rt, 1, n, dfn[nxtn], dfn[nxtn] + sz[nxtn] - 1, 2);
		modify(rt, 1, n, 1, n, -1);
	}
	ans += t[rt].s.d;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs1(1, 0);
	rt = build(1, n);
	dfs2(1, 0);
	printf("%lld\n", ans / 2);
	return 0;
}