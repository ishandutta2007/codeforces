# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct Edge{
	int t;
	ll c;
	int nxt;
} g[MAXN];
int n, gsz;
ll a[MAXN];
int fte[MAXN], s[MAXN];
int fa[MAXN][21];
ll di[MAXN][21];
void addedge(int x, int y, ll z){
	g[++gsz] = (Edge){y, z, fte[x]};
	fte[x] = gsz;
}
void dfs1(int nw){
	// printf("dsf1 %d\n", nw);
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		fa[nxtn][0] = nw;
		di[nxtn][0] = g[i].c;
		for (int j = 1; j <= 20; j++){
			fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
			di[nxtn][j] = di[nxtn][j - 1] + di[fa[nxtn][j - 1]][j - 1];
		}
		dfs1(nxtn);
	}
}
void dfs2(int nw){
	// printf("dsf2 %d\n", nw);
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		dfs2(nxtn);
		s[nw] += s[nxtn];
	}
}
int work(int nw, ll mxd){
	for (int j = 20; j >= 0; j--){
		if (fa[nw][j] && di[nw][j] <= mxd){
			mxd -= di[nw][j];
			nw = fa[nw][j];
		}
	}
	return nw;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 2; i <= n; i++){
		int p;
		ll w;
		scanf("%d%lld", &p, &w);
		addedge(p, i, w);
	}
	dfs1(1);
	for (int i = 1; i <= n; i++){
		s[fa[i][0]]++;
		s[fa[work(i, a[i])][0]]--;
	}
	dfs2(1);
	for (int i = 1; i <= n; i++) printf("%d ", s[i]);
	putchar('\n');
	return 0;
}