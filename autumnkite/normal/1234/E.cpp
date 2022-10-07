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
int n, m, a[200005];
long long f[200005];
void add(int l, int r, int x){
	f[l] += x, f[r + 1] -= x;
}
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= m; ++i) a[i] = read();
	for (register int i = 1; i < m; ++i){
		int x = a[i], y = a[i + 1];
		if (x == y) continue;
		if (x > y) std :: swap(x, y);
		add(1, x - 1, y - x), add(y + 1, n, y - x), add(x + 1, y - 1, y - x - 1);
		add(x, x, y - 1), add(y, y, x);
	}
	for (register int i = 1; i <= n; ++i) f[i] += f[i - 1];
	for (register int i = 1; i <= n; ++i) printf("%lld ", f[i]);
}