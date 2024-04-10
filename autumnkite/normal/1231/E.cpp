#include <cstdio>
#include <cstring>
int T, n, cnt[30];
char s[105], t[105];
void solve(){
	scanf("%d%s%s", &n, s + 1, t + 1);
	memset(cnt, 0, sizeof cnt);
	for (register int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'], --cnt[t[i] - 'a'];
	for (register int i = 0; i < 26; ++i) if (cnt[i] != 0) return puts("-1"), void(0);
	for (register int len = n; len; --len)
		for (register int i = 1; i <= n - len + 1; ++i){
			int j = i + len - 1, p = i;
			for (register int k = 1; k <= n && p <= j; ++k)
				if (s[k] == t[p]) ++p;
			if (p > j) return printf("%d\n", n - len), void(0);
		}
}
int main(){
	scanf("%d", &T);
	while (T--) solve();
}