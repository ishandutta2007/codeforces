#include <cstdio>
#include <algorithm>
int n, z, a[200005];
bool check(int x){
	for (register int i = 1; i <= x; ++i)
		if (a[n - x + i] - a[i] < z) return 0;
	return 1;
}
int main(){
	scanf("%d%d", &n, &z);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i);
	std :: sort(a + 1, a + 1 + n);
	int l = 0, r = n / 2, ans = 0, md;
	while (l <= r) if (check(md = (l + r) >> 1)) ans = md, l = md + 1; else r = md - 1;
	printf("%d\n", ans);
}