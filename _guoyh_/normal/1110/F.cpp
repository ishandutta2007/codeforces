# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 500051;
struct Edge{
	int t;
	ll c;
	bool operator < (const Edge &o) const{
		return t < o.t;
	}
};
struct Tree{
	ll s, tag;
	int ls, rs;
} t[MAXN * 4];
struct Query{
	int l, r, id;
};
vector <Edge> g[MAXN];
int n, m, gsz, lsz, tsz, rt = 1;
ll dis[MAXN];
int fte[MAXN], llf[MAXN], rlf[MAXN];
int lf[MAXN], lid1[MAXN], lid2[MAXN];
ll ans[MAXN];
vector <Query> q[MAXN];
void update(int nw){
	t[nw].s = min(t[t[nw].ls].s, t[t[nw].rs].s);
}
void push_down(int nw){
	t[t[nw].ls].s += t[nw].tag;
	t[t[nw].rs].s += t[nw].tag;
	t[t[nw].ls].tag += t[nw].tag;
	t[t[nw].rs].tag += t[nw].tag;
	t[nw].tag = 0;
}
int build(int lft, int rgt){
	// printf("build %d %d\n", lft, rgt);
	int nw = ++tsz;
	if (lft == rgt){
		t[nw].s = dis[lf[lft]];
		return nw;
	}
	int mid = (lft + rgt) >> 1;
	t[nw].ls = build(lft, mid);
	t[nw].rs = build(mid + 1, rgt);
	update(nw);
	return nw;
}
void modify(int nw, int lft, int rgt, int l, int r, ll nm){
	if (l > r) return;
	if (l == lft && r == rgt){
		t[nw].s += nm;
		t[nw].tag += nm;
		return;
	}
	push_down(nw);
	int mid = (lft + rgt) >> 1;
	if (l <= mid) modify(t[nw].ls, lft, mid, l, min(r, mid), nm);
	if (r >= mid + 1) modify(t[nw].rs, mid + 1, rgt, max(l, mid + 1), r, nm);
	update(nw);
}
ll getmin(int nw, int lft, int rgt, int l, int r){
	// printf("getmin %d %d %d %d %d\n", nw, lft, rgt, l, r);
	if (l > r) return 1e9;
	if (lft == l && rgt == r) return t[nw].s;
	push_down(nw);
	int mid = (lft + rgt) >> 1;
	ll ans = 1e18;
	if (l <= mid) ans = min(ans, getmin(t[nw].ls, lft, mid, l, min(r, mid)));
	if (r >= mid + 1) ans = min(ans, getmin(t[nw].rs, mid + 1, rgt, max(l, mid + 1), r));
	return ans;
}
void dfs1(int nw, int fa){
	if (g[nw].size() == 0){
		lf[++lsz] = nw;
		lid1[nw] = lid2[nw] = lsz;
		llf[nw] = rlf[nw] = lsz;
		return;
	}
	llf[nw] = 1e9;
	int sz = g[nw].size();
	for (int i = 0; i < sz; i++){
		int nxtn = g[nw][i].t;
		if (nxtn == fa) continue;
		dis[nxtn] = dis[nw] + g[nw][i].c;
		dfs1(nxtn, nw);
		llf[nw] = min(llf[nw], llf[nxtn]);
		rlf[nw] = max(rlf[nw], rlf[nxtn]);
	}
	// printf("dfs1 %d %d %d\n", nw, llf[nw], rlf[nw]);
}
void dfs2(int nw, int fa){
	// printf("dfs2 %d\n", nw);
	int sz = g[nw].size();
	for (int i = 0; i < sz; i++){
		int nxtn = g[nw][i].t;
		if (nxtn == fa) continue;
		modify(rt, 1, lsz, 1, lsz, g[nw][i].c);
		modify(rt, 1, lsz, llf[nxtn], rlf[nxtn], -2 * g[nw][i].c);
		dfs2(nxtn, nw);
		modify(rt, 1, lsz, llf[nxtn], rlf[nxtn], 2 * g[nw][i].c);
		modify(rt, 1, lsz, 1, lsz, -g[nw][i].c);
	}
	sz = q[nw].size();
	for (int i = 0; i < sz; i++) ans[q[nw][i].id] = getmin(rt, 1, lsz, lid1[q[nw][i].l], lid2[q[nw][i].r]);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++){
		int p;
		ll w;
		scanf("%d%lld", &p, &w);
		g[p].push_back((Edge){i, w});
	}
	for (int i = 1; i <= m; i++){
		int u, l, r;
		scanf("%d%d%d", &u, &l, &r);
		q[u].push_back((Query){l, r, i});
	}
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
	dfs1(1, -1);
	for (int i = n; i >= 1; i--) if (!lid1[i]) lid1[i] = lid1[i + 1];
	for (int i = 1; i <= n; i++) if (!lid2[i]) lid2[i] = lid2[i - 1];
	rt = build(1, lsz);
	dfs2(1, -1);
	for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}