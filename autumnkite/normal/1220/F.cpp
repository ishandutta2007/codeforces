#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, a[N], tmp[N], ls[N], rs[N], dep[N];
int topr, star[N], mxr[N], ldep[N], topl, stal[N], mxl[N], ans, ansk;
void dfs(int u){
	if (!u) return;
	dfs(ls[u]), dfs(rs[u]), dep[u] = std :: max(dep[ls[u]], dep[rs[u]]) + 1;
}
int main(){
	n = read();
	for (register int i = 0; i < n; ++i) a[i] = read() - 1;
	int k = 0;
	for (register int i = 0; i < n; ++i) if (!a[i]){ k = i; break; }
	for (register int i = k; i < n; ++i) tmp[i - k] = a[i];
	for (register int i = 0; i < k; ++i) tmp[n - k + i] = a[i];
	for (register int i = 0; i < n; ++i) a[i] = tmp[i];
	--n;
	for (register int i = 1; i <= n; ++i){
		star[topr + 1] = 0;
		while (topr && a[star[topr]] > a[i]) --topr;
		ls[i] = star[topr + 1], rs[star[topr]] = i, star[++topr] = i;
	}
	dfs(star[1]), ans = dep[star[1]], ansk = k;
	int u = star[1];
	while (u) stal[++topl] = u, mxl[topl] = std :: max(mxl[topl - 1], dep[rs[u]] + topl), u = ls[u];
	topr = 0;
	for (register int i = 1; i < n; ++i){
		int rdep = 0;
		while (topr && a[star[topr]] > a[i]) rdep = std :: max(rdep + 1, ldep[topr] + 1), --topr;
		star[++topr] = i, ldep[topr] = rdep, mxr[topr] = std :: max(mxr[topr - 1], ldep[topr] + topr);
		int u = rs[stal[topl]];
		--topl, ls[stal[topl]] = u;
		while (u) stal[++topl] = u, mxl[topl] = std :: max(mxl[topl - 1], dep[rs[u]] + topl), u = ls[u];
		int s = std :: max(mxl[topl], mxr[topr]);
		if (s < ans) ans = s, ansk = k + i + 1;
	}
	printf("%d %d\n", ans + 1, ansk % (n + 1));
}