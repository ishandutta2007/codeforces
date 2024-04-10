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
int T, n, x, y;
char s[2][200005];
void solve(){
	scanf("%d%s%s", &n, s[0], s[1]), x = y = 0;
	while (y < n)
		if (s[x][y] <= '2') ++y;
		else{
			x ^= 1;
			if (s[x][y] <= '2') return puts("NO"), void(0);
			++y;
		}
	if (x == 0) puts("NO"); else puts("YES");
}
int main(){
	scanf("%d", &T);
	while (T--) solve();
}