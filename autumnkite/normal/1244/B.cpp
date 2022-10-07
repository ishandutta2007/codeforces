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
int n, ans;
char s[1005];
void solve(){
	n = read(), scanf("%s", s + 1);
	ans = n;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == '1') ans = std :: max(ans, std :: max(i, n - i + 1) << 1);
	printf("%d\n", ans);
}
int main(){
	int T = read();
	while (T--) solve();
}