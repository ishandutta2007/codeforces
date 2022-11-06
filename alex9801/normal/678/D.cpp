#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

const int mod = 1000000007;

struct str
{
	long long a, b, c, d;
	str(long long aa = 0, long long ab = 0, long long ac = 0, long long ad = 0) :a(aa), b(ab), c(ac), d(ad)
	{
		a %= mod;
		b %= mod;
		c %= mod;
		d %= mod;
	}
};

str pro(str x, str y)
{
	return str(x.a*y.a + x.b*y.c, x.a*y.b + x.b*y.d, x.c*y.a + x.d*y.c, x.c*y.b + x.d*y.d);
}

str pow(str x, long long v)
{
	if(v==1)
		return x;
	if(v%2==1)
		return pro(pow(x, v-1), x);
	str t = pow(x, v/2);
	return pro(t, t);
}

int main()
{
	int a, b, x;
	long long n;
	str t;
	scanf("%d%d%I64d%d", &a, &b, &n, &x);

	t = pow(str(a, b, 0, 1), n);
	printf("%I64d", (t.a*x + t.b) % mod);
	return 0;
}