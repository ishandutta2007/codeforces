# include <bits/stdc++.h>
# define ll long long
# define int long long
using namespace std;
const int MAXN = 100051;
struct Edge{
	int t;
	ll w;
	int nxt;
	Edge(int t = 0, ll w = 0, int nxt = 0): t(t), w(w), nxt(nxt){}
} g[MAXN * 2];
int n, q, gsz;
ll l;
int fte[MAXN];
int a[MAXN];
ll dep[MAXN], dep1[MAXN], f[MAXN];
int fa[MAXN], sz[MAXN];
int findroot(int nw){
	if (fa[nw] == nw) return nw;
	return fa[nw] = findroot(fa[nw]);
}
bool cmpf(int u, int v){
	return f[u] < f[v];
}
void addedge(int u, int v, ll w){
	g[++gsz] = Edge(v, w, fte[u]);
	fte[u] = gsz;
}
int find(int nw, int fa = -1){
	int ans = nw;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dep[nxtn] = dep[nw] + g[i].w;
		int na = find(nxtn, nw);
		if (dep[na] > dep[ans]) ans = na;
	}
	return ans;
}
signed main(){
	scanf("%lld", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		ll w;
		scanf("%lld%lld%lld", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dep[1] = 0;
	int d1 = find(1);
	dep[d1] = 0;
	int d2 = find(d1);
	memcpy(dep1, dep, sizeof(dep));
	dep[d2] = 0;
	find(d2);
	for (int i = 1; i <= n; i++){
		f[i] = max(dep[i], dep1[i]);
		// printf("f %d %lld\n", i, f[i]);
		a[i] = i;
	}
	sort(a + 1, a + n + 1, cmpf);
	scanf("%lld", &q);
	while (q--){
		scanf("%lld", &l);
		int ans = 0;
		for (int i = 1; i <= n; i++){
			fa[i] = i;
			sz[i] = 1;
		}
		int p = n;
		for (int i = n; i >= 1; i--){
			while (p > i && f[a[p]] > f[a[i]] + l){
				sz[findroot(a[p])]--;
				fa[a[p]] = a[p];
				p--;
			}
			for (int j = fte[a[i]]; j; j = g[j].nxt){
				int nxtn = g[j].t;
				if (f[nxtn] < f[a[i]] || f[nxtn] > f[a[i]] + l) continue;
				int ra = findroot(a[i]), rn = findroot(nxtn);
				if (ra == rn) continue;
				sz[ra] += sz[rn];
				fa[rn] = ra;
			}
			ans = max(ans, sz[findroot(a[i])]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}