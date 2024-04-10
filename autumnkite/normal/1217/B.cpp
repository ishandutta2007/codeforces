#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 105
int T, n, m, d[N], h[N], mx1, mx2;
int main(){
	T = read();
	while (T--){
		n = read(), m = read(), mx1 = -1e9, mx2 = -1e9;
		for (register int i = 1; i <= n; ++i) d[i] = read(), h[i] = read();
		for (register int i = 1; i <= n; ++i)
			mx1 = std :: max(mx1, d[i] - h[i]), mx2 = std :: max(mx2, d[i]);
		if (mx2 >= m) printf("1\n");
		else if (mx1 <= 0) printf("-1\n");
		else printf("%d\n", (m - mx2 + mx1 - 1) / mx1 + 1);
	}
}