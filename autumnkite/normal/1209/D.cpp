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
#define N 100005
int n, k, fa[N], s;
int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if (x != y) fa[y] = x;
}
int main(){
	n = read(), k = read();
	for (register int i = 1; i <= n; ++i) fa[i] = i;
	for (register int i = 1, u, v; i <= k; ++i)
		u = read(), v = read(), merge(u, v);
	for (register int i = 1; i <= n; ++i)
		s += find(i) == i;
	printf("%d\n", std :: max(0, k - (n - s)));
}