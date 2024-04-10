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
int T, n, a[3005];
int main(){
	T = read();
	while (T--){
		memset(a, 0, sizeof a);
		n = read();
		for (register int i = 1, x; i <= n; ++i) x = read(), x <= 2048 ? ++a[x] : 0;
		for (register int i = 1; i < 2048; i <<= 1)
			a[i << 1] += a[i] >> 1;
		if (a[2048]) puts("YES"); else puts("NO");
	}
}