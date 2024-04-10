#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f3f3fll
int n, m, k, sa[100005], sb[100005];
long long ans;
int main(){
	scanf("%d%d", &n, &m);
	if (m == 0){
		printf("%lld\n", 1ll * n * n);
		for (register int i = 1; i <= n; ++i) putchar('o');
		putchar('\n');
		return 0;
	}
	if (n == 0){
		printf("%lld\n", -1ll * m * m);
		for (register int i = 1; i <= m; ++i) putchar('x');
		putchar('\n');
		return 0;
	}
	if (m == 1){
		printf("%lld\n", 1ll * n * n - 1);
		for (register int i = 1; i <= n; ++i) putchar('o');
		putchar('x'), putchar('\n');
		return 0;
	}
	ans = -INF;
	for (register int i = 2; i <= std :: min(n + 1, m); ++i){
		int len = m / i, r = m % i;
		long long sum = 1ll * len * len * (i - r) + 1ll * (len + 1) * (len + 1) * r;
		sum = 1ll * (n - i + 2) * (n - i + 2) + i - 2 - sum;
		if (sum > ans) ans = sum, k = i;
	}
	printf("%lld\n", ans);
	for (register int i = 1; i <= k; ++i) sb[i] = m / k;
	for (register int i = 1; i <= m % k; ++i) ++sb[i];
	for (register int i = 1; i <= k - 2; ++i) sa[i] = 1;
	sa[k - 1] = n - k + 2;
	for (register int i = 1; i < k; ++i){
		for (register int j = 1; j <= sb[i]; ++j) putchar('x');
		for (register int j = 1; j <= sa[i]; ++j) putchar('o');
	}
	for (register int i = 1; i <= sb[k]; ++i) putchar('x');
	putchar('\n');
}