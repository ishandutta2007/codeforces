#include <cctype>
#include <cstdio>
#define N 2005
#define M 5000005
int n, m, r, c, x, y, id[N][N], sz[M], cnt;
char s[N][N];
int edge, hd[M], to[M * 4], pr[M * 4], co[M * 4];
void addedge(int u, int v, int w){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge, co[edge] = w;
}
int h, t, Q[M], L[M], R[M], ans;
bool vis[M];
void bfs(int s){
	h = 0, t = 1, Q[t] = s, vis[s] = 1, ans += sz[s];
	while (h < t){
		int u = Q[++h];
		for (register int i = hd[u], v; i; i = pr[i]){
			Q[++t] = v = to[i], L[t] = L[h], R[t] = R[h];
			if (co[i] == 1) ++L[t]; else ++R[t];
			if (vis[v] || R[t] > y || L[t] > x){ --t; continue; }
			vis[v] = 1, ans += sz[v];
		}
	}
}
int main(){
	scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
	for (register int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			if (s[i][j] != '*' && (s[i + 1][j] == '*' || i + 1 > n)){
				++cnt;
				int x = i;
				while (s[x][j] == '.' && x) id[x][j] = cnt, --x, ++sz[cnt];
			}
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			if (id[i][j] && id[i][j - 1])
				addedge(id[i][j], id[i][j - 1], 1), addedge(id[i][j - 1], id[i][j], -1);
	bfs(id[r][c]), printf("%d", ans);
}