#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0, f = 1;
	register char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 205
#define M 45005
int T, n, m, d[N], ans, x[M], y[M];
int edge, to[M], pr[M], hd[N], vis[M], Vis[N];
int top, sta[M];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge, ++d[u];
}
void dfs(int u){
	Vis[u] = 1;
	for (register int &i = hd[u]; i; i = pr[i]){
		int j = i;
		if (!vis[j >> 1]) vis[j >> 1] = 1, dfs(to[j]), sta[++top] = (j >> 1) * (j & 1 ? -1 : 1);
	}
}
int main(){
	T = read();
	while (T--){
		edge = 1, top = 0, ans = 0;
		memset(hd, 0, sizeof hd), memset(pr, 0, sizeof pr), memset(vis, 0, sizeof vis);
		n = read(), m = read();
		for (register int i = 0; i <= n; ++i) d[i] = 0, Vis[i] = 0;
		for (register int i = 1, u, v; i <= m; ++i)
			x[i] = read(), y[i] = read(), addedge(x[i], y[i]), addedge(y[i], x[i]);
		for (register int i = 1; i <= n; ++i)
			if (d[i] & 1) addedge(0, i), addedge(i, 0); else ++ans;
		for (register int i = 0; i <= n; ++i)
			if (!Vis[i]) dfs(i);
		printf("%d\n", ans);
		for (register int i = 1; i <= top; ++i)
			if (sta[i] < 0) if (-sta[i] <= m) printf("%d %d\n", y[-sta[i]], x[-sta[i]]); else ;
			else if (sta[i] <= m) printf("%d %d\n", x[sta[i]], y[sta[i]]);
	}
}