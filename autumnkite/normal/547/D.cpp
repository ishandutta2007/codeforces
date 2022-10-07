#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 200005;
int n, r[N], c[N], col[N];
int edge, to[N << 2], pr[N << 2], hd[N << 2];
void addedge(int u, int v){
	to[edge] = v, pr[edge] = hd[u], hd[u] = edge++;
}
void dfs(int u, int c){
	if (~col[u]) return;
	col[u] = c, c ^= 1;
	for (register int i = hd[u]; ~i; i = pr[i]) dfs(to[i], c);
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) hd[i] = -1, col[i] = -1;
	for (register int i = 1, x, y; i <= n; ++i){
		x = read(), y = read();
		if (r[x]) addedge(r[x], i), addedge(i, r[x]), r[x] = 0; else r[x] = i;
		if (c[y]) addedge(c[y], i), addedge(i, c[y]), c[y] = 0; else c[y] = i;
	}
	for (register int i = 1; i <= n; ++i) dfs(i, 0);
	for (register int i = 1; i <= n; ++i)
		if (col[i]) putchar('r'); else putchar('b');
	putchar('\n');
}