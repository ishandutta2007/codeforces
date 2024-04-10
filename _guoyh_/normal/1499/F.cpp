# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 5051;
const int P = 998244353;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int n, k, gsz;
int fte[MAXN];
int f[MAXN][MAXN], s[MAXN][MAXN];
int h[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
void dfs(int nw, int fa){
	f[nw][1] = 1;
	for (int i = 1; i <= k + 1; i++) s[nw][i] = (s[nw][i - 1] + f[nw][i]) % P;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dfs(nxtn, nw);
		for (int j = 1; j <= k + 1; j++){
			h[j] = (1ll * f[nw][j] * s[nxtn][min(j - 1, k - j + 1)] % P + 1ll * f[nxtn][j - 1] * s[nw][min(j, k - j + 2)] % P) % P;
			if (j - 1 <= k - j + 1) h[j] = (h[j] - 1ll * f[nw][j] * f[nxtn][j - 1]) % P;
		}
		for (int j = 1; j <= k + 1; j++){
			f[nw][j] = h[j];
			s[nw][j] = (s[nw][j - 1] + f[nw][j]) % P;
		}
		// printf("nw %d\n", nw);
		// for (int i = 0; i <= k + 1; i++) printf("%d ", f[nw][i]);
		// putchar('\n');
	}
	f[nw][0] = 0;
	for (int i = 1; i <= k + 1; i++) f[nw][0] = (f[nw][0] + f[nw][i]) % P;
	s[nw][0] = f[nw][0];
	for (int i = 1; i <= k + 1; i++) s[nw][i] = (s[nw][i - 1] + f[nw][i]) % P;
	// printf("nw %d\n", nw);
	// for (int i = 0; i <= k + 1; i++) printf("%d ", f[nw][i]);
	// putchar('\n');
}
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, 0);
	printf("%d\n", (f[1][0] % P + P) % P);
	return 0;
}