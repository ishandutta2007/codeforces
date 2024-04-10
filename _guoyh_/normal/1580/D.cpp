# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 4005;
int n, m;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int rt, tsz;
int a[MAXN];
int build(int l, int r){
	int mn = l;
	for (int i = l; i <= r; i++) mn = a[i] < a[mn] ? i : mn;
	if (mn > l) addedge(mn, build(l, mn - 1));
	if (mn < r) addedge(mn, build(mn + 1, r));
	return mn;
}
int sz[MAXN];
ll f[MAXN][MAXN], f1[MAXN][MAXN];
void dfs(int nw){
	sz[nw] = 1;
	f[nw][0] = 0;
	f[nw][1] = 1ll * (m - 1) * a[nw];
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		dfs(nxtn);
		memset(f1[nw], ~0x3f, sizeof(f1[nw]));
		for (int j = 0; j <= sz[nw] && j <= m; j++){
			for (int k = 0; k <= sz[nxtn] && k <= m; k++){
				f1[nw][j + k] = max(f1[nw][j + k], f[nw][j] + f[nxtn][k] - 2ll * j * k * a[nw]);
			}
		}
		sz[nw] += sz[nxtn];
		memcpy(f[nw], f1[nw], sizeof(f[nw]));
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	rt = build(1, n);
	memset(f, ~0x3f, sizeof(f));
	dfs(rt);
	printf("%lld\n", f[rt][m]);
	return 0;
}