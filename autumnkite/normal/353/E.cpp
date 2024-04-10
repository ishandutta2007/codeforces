#include <cstdio>
#include <cstring>
int n, m, t, cnt, a[2000005], ans;
char s[1000005];
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	for (register int i = 1; i <= n; ++i)
		i == 1 || s[i] != s[i - 1] ? a[++m] = 1 : a[m] = 0;
	if (s[n] == s[1]) a[1] = 0, --m;
	for (t = 1; !a[t] && t <= n; ++t) a[++m] = a[t];
	for (register int i = t; i <= m; ++i)
		if (a[i]) ++cnt; else ans += (cnt >> 1) + 1, cnt = 0;
	printf("%d", ans + (cnt >> 1));
}