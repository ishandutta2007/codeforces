#include <cstdio>
#include <algorithm>
int n, m, a[200005], b[200005], ans;
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i);
	register int s = m, x = 1;
	while (s > a[x + 1] - b[x] && x < n) s -= a[x + 1] - b[x], ++x;
	ans = b[x] + s - a[1];
	for (register int i = 2; i <= n; ++i){
		s += a[i] - b[i - 1];
		while (s > a[x + 1] - b[x] && x < n) s -= a[x + 1] - b[x], ++x;
		ans = std :: max(ans, b[x] + s - a[i]);
	}
	printf("%d", ans);
}