# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300051;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
	int t;
	ll w;
	Edge(int t = 0, ll w = 0): t(t), w(w){}
};
vector <Edge> g[MAXN];
int n, m;
struct SegTree{
	struct Node{
		ll s;
		int ls, rs;
	} t[MAXN * 4];
	int rt, tsz;
	void update(int nw){
		t[nw].s = max(t[t[nw].ls].s, t[t[nw].rs].s);
	}
	void modify(int &nw, int lft, int rgt, int pos, ll nm){
		if (!nw) nw = ++tsz;
		if (lft == rgt){
			t[nw].s = nm;
			return;
		}
		int mid = (lft + rgt) >> 1;
		if (pos <= mid) modify(t[nw].ls, lft, mid, pos, nm);
		else modify(t[nw].rs, mid + 1, rgt, pos, nm);
		update(nw);
	}
	ll getsum(int nw, int lft, int rgt, int l, int r){
		if (l > r) return -INF;
		if (!nw) return -INF;
		if (lft == l && rgt == r) return t[nw].s;
		int mid = (lft + rgt) >> 1;
		ll ans = -INF;
		if (l <= mid) ans = max(ans, getsum(t[nw].ls, lft, mid, l, min(mid, r)));
		if (r >= mid + 1) ans = max(ans, getsum(t[nw].rs, mid + 1, rgt, max(mid + 1, l), r));
		return ans;
	}
} sgt;
int a[MAXN], rk[MAXN];
ll dis[MAXN], dis1[MAXN], disn[MAXN];
bool cmp1(int u, int v){
	return dis1[u] < dis1[v];
}
bool cmp1e(Edge u, Edge v){
	return dis1[u.t] < dis1[v.t];
}
bool cmpn(int u, int v){
	return disn[u] < disn[v];
}
void dfs(int nw, int fa = -1){
	int sz = g[nw].size();
	for (int i = 0; i < sz; i++){
		int nxtn = g[nw][i].t;
		if (nxtn == fa) continue;
		dis[nxtn] = dis[nw] + g[nw][i].w;
		dfs(nxtn, nw);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		g[u].push_back(Edge(v, w));
		g[v].push_back(Edge(u, w));
	}
	dis[1] = 0;
	dfs(1);
	memcpy(dis1, dis, sizeof(dis));
	dis[n] = 0;
	dfs(n);
	memcpy(disn, dis, sizeof(dis));
	for (int i = 1; i <= n; i++) a[i] = i;
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n; i++) rk[a[i]] = i;
	ll mxw = 0;
	for (int i = n; i >= 1; i--){
		sort(g[a[i]].begin(), g[a[i]].end(), cmp1e);
		int sz = g[a[i]].size();
		int lst = n;
		for (int j = sz - 1; j >= 0; j--){
			mxw = max(mxw, dis1[a[i]] + sgt.getsum(sgt.rt, 1, n, rk[g[a[i]][j].t] + 1, lst));
			if (rk[g[a[i]][j].t] < i) break;
			lst = rk[g[a[i]][j].t] - 1;
		}
		// printf("ai %d %lld\n", a[i], mxw);
		sgt.modify(sgt.rt, 1, n, i, disn[a[i]]);
	}
	for (int i = 1; i <= m; i++){
		int u;
		scanf("%d", &u);
		printf("%lld\n", min(dis1[n], mxw + u));
	}
	return 0;
}