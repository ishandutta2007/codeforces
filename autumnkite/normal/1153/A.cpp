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
#define N 105
int n, t, x, y, s, mn, ans;
int main(){
	n = read(), t = read(), mn = 1e9;
	for (register int i = 1; i <= n; ++i){
		x = read(), y = read();
		if (x >= t) s = x;
		else s = x + ((t - x - 1) / y + 1) * y;
		if (s < mn) mn = s, ans = i;
	}
	printf("%d\n", ans);
}