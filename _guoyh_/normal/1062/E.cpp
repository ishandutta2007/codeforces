# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
struct Edge{
	int t, nxt;
} g[MAXN];
int n, q, cnt, gsz;
int dfn[MAXN], a[MAXN], fte[MAXN], lg[MAXN], dep[MAXN];
int fa[MAXN][21], mi[MAXN][21], mx[MAXN][21];
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
void dfs(int nw){
	dfn[nw] = ++cnt;
	a[cnt] = nw;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		dep[nxtn] = dep[nw] + 1;
		fa[nxtn][0] = nw;
		for (int j = 1; j <= 20; j++) fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
		dfs(nxtn);
	}
}
int merge1(int x, int y){
	if (x != 0 && (y == 0 || dfn[x] < dfn[y])) return x;
	else return y;
}
int merge2(int x, int y){
	if (x != 0 && (y == 0 || dfn[x] > dfn[y])) return x;
	else return y;
}
int getmin(int l, int r){
	if (l > r) return 0;
	return merge1(mi[l][lg[r - l + 1]], mi[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
}
int getmax(int l, int r){
	if (l > r) return 0;
	return merge2(mx[l][lg[r - l + 1]], mx[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]]);
}
int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--){
		if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--){
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++){
		int p;
		scanf("%d", &p);
		addedge(p, i);
	}
	dfs(1);
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = (i >= (1 << (lg[i - 1] + 1))) ? lg[i - 1] + 1 : lg[i - 1];
	for (int i = n; i >= 1; i--){
		mi[i][0] = mx[i][0] = i;
		for (int j = 1; j <= 20 && i + (1 << j) - 1 <= n; j++){
			mi[i][j] = merge1(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = merge2(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 1; i <= q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		int mid = getmin(l, r), mxd = getmax(l, r);
		int mid2 = merge1(getmin(l, mid - 1), getmin(mid + 1, r));
		int mxd2 = merge2(getmax(l, mxd - 1), getmax(mxd + 1, r));
		// printf("min max %d %d %d %d\n", mid, mid2, mxd, mxd2);
		int l1 = lca(mid, mxd2), l2 = lca(mid2, mxd);
		if (dep[l1] > dep[l2]) printf("%d %d\n", mxd, dep[l1]);
		else printf("%d %d\n", mid, dep[l2]);
	}
	return 0;
}