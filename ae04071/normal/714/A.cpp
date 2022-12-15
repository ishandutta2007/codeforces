#include <cstdio>
#include <algorithm>

long long l1, r1, l2, r2, k;

int main()
{
	scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);

	long long res = 0;
	long long l = std::max(l1, l2), r = std::min(r1, r2);
	res = r - l + 1;
	if (l <= k && k <= r)
		res--;

	if (res < 0) res = 0;

	printf("%lld\n", res);
	
	return 0;
}