#include <cstdio>
#include <algorithm>
int n, a, b, ans;
int main(){
	scanf("%d%d%d", &n, &a, &b), ans = n;
	b *= 5;
	if (a < b) std :: swap(a, b);
	for (register int i = 0; i <= n; i += a)
		ans = std :: min(ans, (n - i) % b);
	printf("%d\n", ans);
}