#include <cstdio>
#include <algorithm>
int n, h, a[1005], b[1005];
bool check(int m){
	for (register int i = 1; i <= m; ++i) b[i] = a[i];
	std :: sort(b + 1, b + 1 + m);
	long long s = 0;
	for (register int i = m; i > 0; i -= 2) s += std :: max(b[i], b[i - 1]);
	return s <= h;
}
int main(){
	scanf("%d%d", &n, &h);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	int l = 0, r = n, ans, md;
	while (l <= r) if (check(md = (l + r) >> 1)) ans = md, l = md + 1; else r = md - 1;
	printf("%d\n", ans);
}