# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
struct Node{
	ll mx, nm;
	Node operator + (const Node &o) const{
		if (mx > o.mx) return *this;
		else if (mx < o.mx) return o;
		else return (Node){mx, nm + o.nm};
	}
};
struct Tree{
	Node s;
	int ls, rs;
} t[MAXN * 50];
struct Edge{
	int t, nxt;
} g[MAXN * 2];
int n, gsz, tsz;
int c[MAXN];
int rt[MAXN];
int fte[MAXN];
ll ans[MAXN];
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
void update(int nw){
	t[nw].s = t[t[nw].ls].s + t[t[nw].rs].s;
}
int modify(int nw, int lft, int rgt, int p, Node nm){
	int newn = nw ? nw : ++tsz;
	if (lft == rgt){
		t[newn].s = nm;
		return newn;
	}
	int mid = (lft + rgt) >> 1;
	if (p <= mid) t[newn].ls = modify(t[newn].ls, lft, mid, p, nm);
	else t[newn].rs = modify(t[newn].rs, mid + 1, rgt, p, nm);
	update(newn);
	return newn;
}
int merge(int p1, int p2, int lft, int rgt){
	if (!p1 || !p2) return p1 + p2;
	if (lft == rgt){
		t[p1].s.mx += t[p2].s.mx;
		return p1;
	}
	int mid = (lft + rgt) >> 1;
	t[p1].ls = merge(t[p1].ls, t[p2].ls, lft, mid);
	t[p1].rs = merge(t[p1].rs, t[p2].rs, mid + 1, rgt);
	update(p1);
	return p1;
}
void dfs(int nw, int fa){
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dfs(nxtn, nw);
		rt[nw] = merge(rt[nw], rt[nxtn], 1, n);
	}
	ans[nw] = t[rt[nw]].s.nm;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", c + i);
		rt[i] = modify(rt[i], 1, n, c[i], (Node){1, c[i]});
	}
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	putchar('\n');
	return 0;
}