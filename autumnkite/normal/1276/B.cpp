#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 200005, M = 500005;
int T, n, m, a, b, fa[N], s[N];
long long ans;
struct node{
	int x, y;
	bool operator < (const node &rhs) const { return x < rhs.x || (x == rhs.x && y < rhs.y); }
}E[M], p[N];
int find(int x){ return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void merge(int x, int y){
	x = find(x), y = find(y);
	if (x != y) fa[y] = x;
}
void solve(){
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (register int i = 1; i <= m; ++i)
		scanf("%d%d", &E[i].x, &E[i].y);
	for (register int i = 1; i <= n; ++i) fa[i] = i;
	for (register int i = 1; i <= m; ++i)
		if (E[i].x != a && E[i].y != a) merge(E[i].x, E[i].y);
	for (register int i = 1; i <= n; ++i) p[i].x = find(i);
	for (register int i = 1; i <= n; ++i) fa[i] = i;
	for (register int i = 1; i <= m; ++i)
		if (E[i].x != b && E[i].y != b) merge(E[i].x, E[i].y);
	for (register int i = 1; i <= n; ++i) p[i].y = find(i);
	p[a].x = n + 1, p[b].x = n + 1;
	std::sort(p + 1, p + 1 + n);
	for (register int i = 1; i <= n; ++i) s[i] = 0;
	ans = 0;
	for (register int i = 1, j = 1; i <= n - 2; i = j){
		while (j <= n - 2 && p[i].x == p[j].x) ++j;
		for (register int k = i; k < j; ++k) ans += i - 1 - s[p[k].y];
		for (register int k = i; k < j; ++k) ++s[p[k].y];
	}
	printf("%lld\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) solve();
}