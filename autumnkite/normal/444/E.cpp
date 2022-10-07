#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, fa[N], sz[N], ans;
long long a[N], sum;
struct node{
	int u, v, w;
	bool operator < (const node &res) const { return w < res.w; }
}e[N];
int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
int merge(int x, int y){
	int fx = find(x), fy = find(y);
	fa[fy] = fx, sz[fx] += sz[fy], a[fx] += a[fy];
	return sz[fx] <= sum - a[fx];
}
int main(){
	n = read();
	for (register int i = 1; i < n; ++i) e[i] = (node){read(), read(), read()};
	for (register int i = 1; i <= n; ++i) sum += a[i] = read(), fa[i] = i, sz[i] = 1;
	std :: sort(e + 1, e + n);
	for (register int i = 1; i < n; ++i)
		if (ans = e[i].w, !merge(e[i].u, e[i].v)) break;
	printf("%d", ans);
}