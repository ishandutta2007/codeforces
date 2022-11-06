#include <stdio.h>
#include <string.h>
#include <algorithm>

long long f(long long n, long long l, long long r)
{
	if(r < l)
		return 0;

	if(n <= 1)
	{
		return n;
	}

	long long t = n;
	long long c = 0, x;

	while(t)
	{
		c++;
		t /= 2;
	}

	x = (1LL<<(c-1)) - 1;

	if(r <= x)
	{
		return f(n/2, l, r);
	}

	if(l >= x+2)
	{
		return f(n/2, l-x-1, r-x-1);
	}

	return f(n/2, l, x) + f(n/2, 1, r-x-1) + n % 2;
}

int main()
{
	long long n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);

	printf("%lld", f(n, l, r));
	return 0;
}