#include <cstdio>
typedef long long LL;

LL n, ans;

int main()
{
	scanf("%lld", &n);
	for (int i = 0; (1LL << i) < n; i ++)
		ans += 1LL * ((n + (1LL << i) - 1) >> i + 1) * (1LL << i);
	printf("%lld\n", ans);
	return 0;
}