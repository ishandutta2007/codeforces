# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
# define fst first
# define scd second
# define mpr make_pair
using namespace std;
const int MAXN = 100051;
struct Edge{
	int t;
	ll w;
	int nxt;
	Edge(){nxt = 0;}
	Edge(int t, ll w, int nxt): t(t), w(w), nxt(nxt){}
} g[MAXN * 80];
struct Tree{
	int ls, rs;
} t[MAXN * 10];
int n, m, s, gsz, tsz, rt1, rt2;
int fte[MAXN * 10];
ll dis[MAXN * 10];
void addedge(int u, int v, ll w){
	g[++gsz] = Edge(v, w, fte[u]);
	fte[u] = gsz;
}
int build1(int l, int r){
	// printf("build1 %d %d\n", l, r);
	if (l == r) return l;
	int nw = ++tsz;
	int mid = (l + r) >> 1;
	t[nw].ls = build1(l, mid);
	t[nw].rs = build1(mid + 1, r);
	addedge(nw, t[nw].ls, 0ll);
	addedge(nw, t[nw].rs, 0ll);
	return nw;
}
int build2(int l, int r){
	// printf("build2 %d %d\n", l, r);
	if (l == r) return l;
	int nw = ++tsz;
	int mid = (l + r) >> 1;
	t[nw].ls = build2(l, mid);
	t[nw].rs = build2(mid + 1, r);
	addedge(t[nw].ls, nw, 0ll);
	addedge(t[nw].rs, nw, 0ll);
	return nw;
}
void work1(int nw, int lft, int rgt, int l, int r, int u, ll w){
	if (lft == l && rgt == r){
		addedge(u, nw, w);
		return;
	}
	int mid = (lft + rgt) >> 1;
	if (l <= mid) work1(t[nw].ls, lft, mid, l, min(mid, r), u, w);
	if (r >= mid + 1) work1(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, u, w);
}
void work2(int nw, int lft, int rgt, int l, int r, int v, ll w){
	if (lft == l && rgt == r){
		addedge(nw, v, w);
		return;
	}
	int mid = (lft + rgt) >> 1;
	if (l <= mid) work2(t[nw].ls, lft, mid, l, min(mid, r), v, w);
	if (r >= mid + 1) work2(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, v, w);
}
void dijkstra(){
	priority_queue <pair <ll, int> > q;
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push(mpr(0ll, s));
	while (!q.empty()){
		pair <ll, int> nw = q.top();
		q.pop();
		nw.fst = -nw.fst;
		if (nw.fst > dis[nw.scd]) continue;
		for (int i = fte[nw.scd]; i; i = g[i].nxt){
			pair <ll, int> nxtn = mpr(nw.fst + g[i].w, g[i].t);
			if (nxtn.fst >= dis[nxtn.scd]) continue;
			dis[nxtn.scd] = nxtn.fst;
			nxtn.fst = -nxtn.fst;
			q.push(nxtn);
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &s);
	tsz = n;
	rt1 = build1(1, n);
	rt2 = build2(1, n);
	for (int i = 1; i <= m; i++){
		int op, u, v, l, r;
		ll w;
		scanf("%d", &op);
		if (op == 1){
			scanf("%d%d%lld", &u, &v, &w);
			addedge(u, v, w);
		} else if (op == 2){
			scanf("%d%d%d%lld", &u, &l, &r, &w);
			work1(rt1, 1, n, l, r, u, w);
		} else {
			scanf("%d%d%d%lld", &v, &l, &r, &w);
			work2(rt2, 1, n, l, r, v, w);
		}
	}
	dijkstra();
	for (int i = 1; i <= n; i++){
		if (dis[i] > 1e18) printf("-1 ");
		else printf("%lld ", dis[i]);
	}
	return 0;
}