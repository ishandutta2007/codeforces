#include <cstdio>
typedef long long LL;

LL n, m;

void Go(LL &x, LL &y)
{
	if (!x || !y) return ;
	if (x >= 2 * y) x = x % (2 * y), Go(x, y);
	else if (y >= 2 * x) y = y % (2 * x), Go(x, y);
}

int main()
{
	scanf("%lld%lld", &n, &m);
	Go(n, m);
	printf("%lld %lld\n", n, m);
	return 0;
}