#include <cstdio>
#include <cstring>
#include <algorithm>
int n, m, a[1005], c[5], ans;
char s[1005][1005];
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (register int i = 1; i <= m; ++i) scanf("%d", a + i);
	for (register int i = 1; i <= m; ++i){
		memset(c, 0, sizeof c);
		for (register int j = 1; j <= n; ++j)
			++c[s[j][i] - 'A'];
		int mx = 0;
		for (register int j = 0; j < 5; ++j)
			mx = std :: max(mx, c[j]);
		ans += mx * a[i];
	}
	printf("%d\n", ans);
}