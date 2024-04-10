#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 300005
int n, a[N], p[N], m, x[N * 5], y[N * 5];
void Swap(int u, int v){
	if (u == v) return;
	if (u > v) std :: swap(u, v);
	if (v - u >= n / 2) return ++m, x[m] = u, y[m] = v, std :: swap(a[u], a[v]), std :: swap(p[a[u]], p[a[v]]);
	if (u <= n / 2 && v > n / 2) return Swap(u, n), Swap(1, n), Swap(1, v), Swap(1, n), Swap(u, n);
	if (u > n / 2 && v > n / 2) return Swap(1, u), Swap(1, v), Swap(1, u);
	if (u <= n / 2 && v <= n / 2) return Swap(n, u), Swap(n, v), Swap(n, u);
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read(), p[a[i]] = i;
	for (register int i = 1; i <= n; ++i) Swap(i, p[i]);
	printf("%d\n", m);
	for (register int i = 1; i <= m; ++i) printf("%d %d\n", x[i], y[i]);
}