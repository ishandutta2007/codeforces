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
int n, a[N], h, t, q[N], c[N];
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i)
		a[n + n + i] = a[n + i] = a[i] = read(), c[i] = -1;
	h = 1, t = 0;
	for (register int i = 1, lst = 0; i <= n * 3; ++i){
		while (h <= t && a[q[h]] > 2 * a[i]){
			for (register int j = lst + 1; j <= q[h]; ++j) c[j] = i - j;
			lst = q[h], ++h;
		}
		while (h <= t && a[i] > a[q[t]]) --t;
		q[++t] = i;
	}
	for (register int i = 1; i <= n; ++i) printf("%d ", c[i]);
}