#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, m, mw, fa[N], sz[N];
long long sum, ans[N];
std :: vector< std :: pair<int, int> > E[N];
int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
long long calc(int x){
	return 1ll * x * (x - 1) >> 1;
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if (x == y) return;
	sum -=calc(sz[x]), sum -= calc(sz[y]);
	fa[y] = x, sz[x] += sz[y];
	sum += calc(sz[x]);
}
int main(){
	n = read(), m = read();
	for (register int i = 1, u, v, w; i < n; ++i)
		u = read(), v = read(), mw = std :: max(mw, w = read()), E[w].push_back(std :: make_pair(u, v));
	for (register int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
	sum = 0;
	for (register int i = 1; i <= mw; ++i){
		for (auto p : E[i]) merge(p.first, p.second);
		ans[i] = sum;
	}
	for (register int i = 1, x; i <= m; ++i)
		x = std :: min(mw, read()), printf("%lld ", ans[x]);
}