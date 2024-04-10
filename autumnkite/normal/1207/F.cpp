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
#define N 500005
int n, q, bl, a[N], sum[710][710];
int main(){
	q = read(), n = 500000, bl = sqrt(n);
	for (register int i = 1; i <= q; ++i){
		int opt = read(), x = read(), y = read();
		if (opt == 1){
			a[x] += y;
			for (register int j = 1; j <= bl; ++j) sum[j][x % j] += y;
		}
		else if (x > bl){
			int sum = 0;
			if (!y) y = x;
			for (register int j = y; j <= n; j += x) sum += a[j];
			printf("%d\n", sum);
		}
		else printf("%d\n", sum[x][y]);
	}
}