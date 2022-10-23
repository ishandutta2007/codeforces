# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int MAXM = 200051;
struct Edge0{
	int u, v;
	ll w;
	int id;
	bool operator < (const Edge0 &o) const{
		return w < o.w;
	}
} e[MAXM];
struct Edge{
	int t;
	ll c;
	int nxt;
} g[MAXM * 2];
struct DSU{
	int sz;
	int fa[MAXN];
	void init(int x){
		sz = x;
		for (int i = 1; i <= x; i++) fa[i] = i;
	}
	int findroot(int nw){
		if (fa[nw] == nw) return nw;
		else return fa[nw] = findroot(fa[nw]);
	}
	bool merge(int x, int y){
		int rx = findroot(x), ry = findroot(y);
		if (rx == ry) return false;
		fa[rx] = ry;
		sz--;
		return true;
	}
} t;
int n, m, gsz;
ll tol, ans = 1e18;
int fte[MAXN], dep[MAXN];
bool flag[MAXM];
int fa[MAXN][21];
ll mxl[MAXN][21];
ll fnl[MAXM];
void addedge(int x, int y, ll z){
	g[++gsz] = (Edge){y, z, fte[x]};
	fte[x] = gsz;
}
void dfs(int nw){
	// printf("dfs %d\n", nw);
	// for (int i = 0; i <= 3; i++) printf("%d ", fa[nw][i]);
	// putchar('\n');
	// for (int i = 0; i <= 3; i++) printf("%lld ", mxl[nw][i].s1);
	// putchar('\n');
	// for (int i = 0; i <= 3; i++) printf("%lld ", mxl[nw][i].s2);
	// putchar('\n');
	// putchar('\n');
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw][0]) continue;
		dep[nxtn] = dep[nw] + 1;
		fa[nxtn][0] = nw;
		mxl[nxtn][0] = g[i].c;
		for (int j = 1; j <= 20; j++){
			fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
			mxl[nxtn][j] = max(mxl[nxtn][j - 1], mxl[fa[nxtn][j - 1]][j - 1]);
		}
		dfs(nxtn);
	}
}
ll lca(int x, int y){
	ll ans = -1e18;
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--){
		if (dep[x] - (1 << i) >= dep[y]){
			ans = max(ans, mxl[x][i]);
			x = fa[x][i];
		}
	}
	if (x == y) return ans;
	for (int i = 20; i >= 0; i--){
		if (fa[x][i] != fa[y][i]){
			ans = max(ans, mxl[x][i]);
			ans = max(ans, mxl[y][i]);
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	ans = max(ans, max(mxl[x][0], mxl[y][0]));
	return ans;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
		e[i].id = i;
	}
	sort(e + 1, e + m + 1);
	t.init(n);
	for (int i = 1; i <= m && t.sz > 1; i++){
		if (flag[i] = t.merge(e[i].u, e[i].v)){
		// printf("asdf %d %d %lld\n", e[i].u, e[i].v, e[i].w);	
			addedge(e[i].u, e[i].v, e[i].w);
			addedge(e[i].v, e[i].u, e[i].w);
			tol += e[i].w;
		}
	}
	dfs(1);
	for (int i = 1; i <= m; i++){
		if (flag[i]) fnl[e[i].id] = tol;
		else fnl[e[i].id] = tol - lca(e[i].u, e[i].v) + e[i].w;
	}
	for (int i = 1; i <= m; i++) printf("%lld\n", fnl[i]);
	return 0;
}