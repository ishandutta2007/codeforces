# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 20051;
const int MAXV = MAXN * 3;
const int MAXE = 10000051;
const int INF = 0x3f3f3f3f;
int n, m, nsz;

struct Edge{
	int t, c, nxt;
	Edge(int t = 0, int c = 0, int nxt = 0): t(t), c(c), nxt(nxt){}
} g[MAXE * 2];
int gsz = 1;
int fte[MAXV];
void addedge(int u, int v, int c = INF){
	g[++gsz] = Edge(v, c, fte[u]);
	fte[u] = gsz;
	g[++gsz] = Edge(u, 0, fte[v]);
	fte[v] = gsz;
}

int cnt;
int fa[MAXN], sz[MAXN], dfn[MAXN], a[MAXN], top[MAXN], hs[MAXN], d[MAXN], eid[MAXN];
void dfs1(int nw){
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		eid[nxtn] = i / 2;
		fa[nxtn] = nw;
		d[nxtn] = d[nw] + 1;
		dfs1(nxtn);
		if (sz[nxtn] >= sz[hs[nw]]) hs[nw] = nxtn;
		sz[nw] += sz[nxtn];
	}
}
void dfs2(int nw){
	dfn[nw] = ++cnt;
	a[cnt] = nw;
	// printf("nw %d %d %d %d\n", nw, dfn[nw], hs[nw], top[nw]);
	if (hs[nw]){
		top[hs[nw]] = top[nw];
		dfs2(hs[nw]);
	}
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw] || nxtn == hs[nw]) continue;
		top[nxtn] = nxtn;
		dfs2(nxtn);
	}
}

struct SegTree{
	struct Node{
		int nw;
		int ls, rs;
	} t[MAXN * 2];
	int rt;
	void build(int &nw, int lft, int rgt){
		if (lft == rgt){
			nw = a[lft];
			return;
		}
		nw = ++nsz;
		int mid = (lft + rgt) >> 1;
		build(t[nw].ls, lft, mid);
		build(t[nw].rs, mid + 1, rgt);
		addedge(nw, t[nw].ls);
		addedge(nw, t[nw].rs);
	}
	void conn(int nw, int lft, int rgt, int l, int r, int vt){
		if (l > r) return;
		if (lft == l && rgt == r){
			addedge(vt, nw);
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (l <= mid) conn(t[nw].ls, lft, mid, l, min(mid, r), vt);
		if (r >= mid + 1) conn(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r, vt);
	}
} sgt;

void work(int u, int v, int vt){
	// printf("work1 %d %d\n", u, v);
	if (top[u] == top[v]){
		if (d[u] < d[v]) swap(u, v);
		sgt.conn(sgt.rt, 1, n, dfn[v] + 1, dfn[u], vt);
		return;
	}
	if (d[top[u]] < d[top[v]]) swap(u, v);
	sgt.conn(sgt.rt, 1, n, dfn[top[u]], dfn[u], vt);
	work(fa[top[u]], v, vt);
}

int dep[MAXV];
int curE[MAXV];
bool bfs(int S, int T){
	queue <int> q;
	memset(dep, -1, sizeof(dep));
	dep[S] = 0;
	q.push(S);
	while (!q.empty()){
		int nw = q.front();
		q.pop();
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			if (g[i].c == 0 || dep[nxtn] != -1) continue;
			dep[nxtn] = dep[nw] + 1;
			q.push(nxtn);
		}
	}
	return dep[T] != -1;
}
int dfs(int nw, int mxf, int T){
	if (nw == T) return mxf;
	if (mxf == 0) return 0;
	int df = 0;
	for (int &i = curE[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (g[i].c == 0 || dep[nxtn] != dep[nw] + 1) continue;
		int nwf = dfs(nxtn, min(g[i].c, mxf - df), T);
		if (!nwf) dep[nxtn] = -1;
		g[i].c -= nwf;
		g[i ^ 1].c += nwf;
		df += nwf;
		if (df == mxf) break;
	}
	return df;
}
int dinic(int S, int T){
	int ans = 0;
	while (bfs(S, T)){
		memcpy(curE, fte, sizeof(fte));
		ans += dfs(S, INF, T);
	}
	return ans;
}

int pv[MAXN];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs1(1);
	top[1] = 1;
	dfs2(1);
	gsz = 1;
	memset(fte, 0, sizeof(fte));
	nsz = n;
	int S = ++nsz, T = ++nsz;
	sgt.build(sgt.rt, 1, n);
	for (int i = 1; i <= m; i++){
		pv[i] = ++nsz;
		int u, v;
		scanf("%d%d", &u, &v);
		work(u, v, pv[i]);
		addedge(S, pv[i], 1);
	}
	for (int i = 1; i <= n; i++) addedge(i, T, 1);
	printf("%d\n", dinic(S, T));
	bfs(S, T);
	int cnt = 0;
	for (int i = 1; i <= m; i++) cnt += (dep[pv[i]] == -1);
	printf("%d ", cnt);
	for (int i = 1; i <= m; i++) if (dep[pv[i]] == -1) printf("%d ", i);
	putchar('\n');
	cnt = 0;
	for (int i = 1; i <= n; i++) cnt += (dep[i] != -1);
	printf("%d ", cnt);
	for (int i = 1; i <= n; i++) if (dep[i] != -1) printf("%d ", eid[i]);
	putchar('\n');
	return 0;
}