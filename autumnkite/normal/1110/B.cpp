#include <cstdio>
#include <cstring>
#include <algorithm>
int n, m, k, a[100005], b[100005], ans;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	for (register int i = 1; i < n; ++i) b[i] = a[i + 1] - a[i] - 1;
	ans = n;
	std :: sort(b + 1, b + n);
	for (register int i = 1; i <= n - k; ++i) ans += b[i];
	printf("%d\n", ans);
}