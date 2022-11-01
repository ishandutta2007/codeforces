#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL get_sum(LL l, LL r)
{
	return (r - l + 1) * (r + l) / 2;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		LL x1, x2, y1, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		LL n = x2 + y2 - x1 - y1, m = y2 - y1;
		printf("%lld\n", get_sum(n - m + 1, n) - get_sum(1, m) + 1);
	}
	return 0;
}