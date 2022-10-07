#include <cstdio>
#define N 200005
int n, fa[N][2], sz[N][2];
long long ans;
int find(int x, int c){
	return fa[x][c] == x ? x : (fa[x][c] = find(fa[x][c], c));
}
void merge(int x, int y, int c){
	x = find(x, c), y = find(y, c);
	if (x == y) return;
	fa[y][c] = fa[x][c], sz[x][c] += sz[y][c];
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) fa[i][0] = fa[i][1] = i, sz[i][0] = sz[i][1] = 1;
	for (register int i = 1, u, v, w; i < n; ++i) scanf("%d%d%d", &u, &v, &w), merge(u, v, w);
	for (register int i = 1; i <= n; ++i) ans += 1ll * sz[find(i, 0)][0] * sz[find(i, 1)][1] - 1;
	printf("%lld", ans);
}