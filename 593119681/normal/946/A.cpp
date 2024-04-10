#include <cstdio>
typedef long long LL;

int n;

int main()
{
	while (~scanf("%d", &n))
	{
		LL sum = 0;
		for (int i = 1, x; i <= n; i ++)
		{
			scanf("%d", &x);
			sum += x > 0 ? x : -x;
		}
		printf("%lld\n", sum);
	}
	return 0;
}