# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
struct Edge{
	int t, nxt;
} g[MAXN * 2];
struct BIT{
	ll c[MAXN];
	inline int lowbit(int x){
		return x & (-x);
	}
	void add(int pos, ll nm){
		for (int i = pos; i < MAXN; i += lowbit(i)) c[i] += nm;
	}
	ll getsum(int pos){
		ll ans = 0;
		for (int i = pos; i; i -= lowbit(i)) ans += c[i];
		return ans;
	}
} t;
int n, m, gsz;
int fte[MAXN];
int dep[MAXN];
ll ans[MAXN];
vector <pair <int, int> > adj[MAXN];
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
void dfs(int nw, int fa){
	int sz = adj[nw].size();
	for (int i = 0; i < sz; i++){
		t.add(dep[nw], adj[nw][i].second);
		t.add(dep[nw] + adj[nw][i].first + 1, -adj[nw][i].second);
	}
	ans[nw] = t.getsum(dep[nw]);
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dep[nxtn] = dep[nw] + 1;
		dfs(nxtn, nw);
	}
	for (int i = 0; i < sz; i++){
		t.add(dep[nw], -adj[nw][i].second);
		t.add(dep[nw] + adj[nw][i].first + 1, adj[nw][i].second);
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		int v, d;
		ll x;
		scanf("%d%d%lld", &v, &d, &x);
		adj[v].push_back(make_pair(d, x));
	}
	dep[1] = 1;
	dfs(1, -1);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	putchar('\n');
	return 0;
}