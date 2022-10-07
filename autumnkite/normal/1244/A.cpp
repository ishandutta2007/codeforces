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
void solve(){
	int a = read(), b = read(), c = read(), d = read(), k = read();
	int x = (a - 1) / c + 1, y = (b - 1) / d + 1;
	if (x + y <= k) printf("%d %d\n", x, y); else printf("-1\n");
}
int main(){
	int T = read();
	while (T--) solve();
}