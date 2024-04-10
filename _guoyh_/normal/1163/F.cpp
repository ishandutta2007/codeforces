# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 400051;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, q;
struct Edge{
	int s, t, w, nxt;
	Edge(int s = 0, int t = 0, int w = 0, int nxt = 0): s(s), t(t), w(w), nxt(nxt){}
} g[MAXN * 2];
int gsz = 1;
int fte[MAXN];
void addedge(int u, int v, int w){
	g[++gsz] = Edge(u, v, w, fte[u]);
	fte[u] = gsz;
}
struct Node{
	int id;
	ll di;
	Node(int id = 0, ll di = 0): id(id), di(di){}
};
bool operator < (const Node &u, const Node &v){
	return u.di > v.di;
}
ll dis0[MAXN], dis1[MAXN];
void dijkstra(int S, ll *dis){
	priority_queue <Node> q;
	memset(dis, 0x3f, sizeof(ll) * MAXN);
	dis[S] = 0;
	q.push(Node(S, 0));
	while (!q.empty()){
		Node nw = q.top();
		q.pop();
		if (nw.di > dis[nw.id]) continue;
		for (int i = fte[nw.id]; i; i = g[i].nxt){
			Node nxtn = Node(g[i].t, nw.di + g[i].w);
			if (nxtn.di >= dis[nxtn.id]) continue;
			dis[nxtn.id] = nxtn.di;
			q.push(nxtn);
		}
	}
}
int f0[MAXN], f1[MAXN];
int sp[MAXN], ssz;
bool inp[MAXN];
int pid[MAXN];
void getPath(){
	for (int i = n; i != 1; ){
		sp[++ssz] = i;
		for (int j = fte[i]; j; j = g[j].nxt){
			if (dis0[g[j].t] + g[j].w == dis0[i]){
				i = g[j].t;
				pid[j] = ssz + 1;
				inp[j] = true;
				// printf("inp %d %d\n", j, ssz);
				break;
			}
		}
	}
	sp[++ssz] = 1;
}
int dfs(int nw, ll *dis, int *f){
	if (f[nw]) return f[nw];
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (dis[nw] == dis[nxtn] + g[i].w) f[nw] = max(f[nw], dfs(nxtn, dis, f));
	}
	return f[nw];
}
struct SegTree{
	struct Node{
		ll s, tag;
		int ls, rs;
		Node(){
			s = tag = INF;
			ls = rs = 0;
		}
	} t[MAXN * 4];
	int rt, tsz;
	void update(int nw){
		t[nw].s = min(min(t[t[nw].ls].s, t[t[nw].rs].s), t[nw].tag);
	}
	void modify(int &nw, int lft, int rgt, int l, int r, ll nm){
		if (l > r) return;
		if (!nw) nw = ++tsz;
		if (lft == l && rgt == r){
			t[nw].tag = min(t[nw].tag, nm);
			t[nw].s = min(t[nw].s, nm);
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (l <= mid) modify(t[nw].ls, lft, mid, l, min(mid, r), nm);
		if (r >= mid + 1) modify(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, nm);
		update(nw);
	}
	ll getsum(int nw, int lft, int rgt, int l, int r){
		if (!nw) return INF;
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		ll ans = t[nw].tag;
		if (l <= mid) ans = min(ans, getsum(t[nw].ls, lft, mid, l, min(mid, r)));
		if (r >= mid + 1) ans = min(ans, getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
		return ans;
	}
} sgt;
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dijkstra(1, dis0);
	getPath();
	for (int i = 1; i <= ssz; i++) f0[sp[i]] = i;
	for (int i = 1; i <= n; i++) dfs(i, dis0, f0);
	dijkstra(n, dis1);
	for (int i = 1; i <= ssz; i++) f1[sp[i]] = ssz - i + 1;
	for (int i = 1; i <= n; i++) dfs(i, dis1, f1);
	for (int i = 2; i <= m * 2 + 1; i++){
		if (inp[i] || inp[i ^ 1]) continue;
		// printf("edge %d %d %d %d %d %lld\n", g[i].s, g[i].t, g[i].w, ssz - f1[g[i].t] + 1 + 1, f0[g[i].s], dis0[g[i].s] + g[i].w + dis1[g[i].t]);
		sgt.modify(sgt.rt, 1, ssz, ssz - f1[g[i].t] + 1 + 1, f0[g[i].s], dis0[g[i].s] + g[i].w + dis1[g[i].t]);
	}
	// for (int i = 1; i <= n; i++) printf("f %d %d %d\n", i, f0[i], f1[i]);
	while (q--){
		int eid, l;
		scanf("%d%d", &eid, &l);
		ll ans = INF;
		eid = inp[eid * 2] ? eid * 2 : eid * 2 + 1;
		// printf("pid %d %d %d %d %d\n", eid, pid[eid], inp[eid], l, g[eid].w);
		if (!inp[eid]){
			ans = dis0[n];
			ans = min(ans, dis0[g[eid].s] + dis1[g[eid].t] + l);
			ans = min(ans, dis1[g[eid].s] + dis0[g[eid].t] + l);
		} else if (l <= g[eid].w) ans = dis0[n] - g[eid].w + l;
		else {
			ans = dis0[n] - g[eid].w + l;
			// printf("ans0 %lld\n", ans);
			ans = min(ans, sgt.getsum(sgt.rt, 1, ssz, pid[eid], pid[eid]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}