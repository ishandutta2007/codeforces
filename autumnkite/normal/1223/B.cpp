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
int n;
char s[105], t[105];
bool vis[26];
void solve(){
	scanf("%s%s", s + 1, t + 1), n = strlen(s + 1);
	memset(vis, 0, sizeof vis);
	for (register int i = 1; i <= n; ++i) vis[s[i] - 'a'] = 1;
	for (register int i = 1; i <= n; ++i)
		if (vis[t[i] - 'a']) return puts("YES"), void(0);
	puts("NO");
}
int main(){
	int T = read();
	while (T--) solve();
}