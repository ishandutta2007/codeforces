#include <bits/stdc++.h>
#define P 100000000000000000
#define double long double

using namespace std;

typedef long long ll;

ll mul(ll x, ll y)
{
	x = (x % P + P) % P, y = (y % P + P) % P;
	/*return ((((x >> 20) * y % P) << 20) + (x & ((1 << 20) - 1)) * y) % P;*/
	ll tmp = (ll)((double) x * y / P);
	ll s = x * y - P * tmp;
	return s < 0 ? s + P : s;
}

ll two(ll x)
{
	if(x % 2 == 0) return mul(x / 2, x + 1);
	return mul((x + 1) / 2, x);
}

ll three(ll x)
{
	ll tmp = x * (x + 1) / 2;
	if(tmp % 3 == 0) return mul(tmp / 3, 2 * x + 1);
	return mul(tmp, (2 * x + 1) / 3);
}

double twodb(ll x)
{
	return (double)(x) * (double)(x + 1) / 2;
}

double threedb(ll x)
{
	return (double)(x) * (double)(x + 1) * (double)(2 * x + 1) / 6;
}

double calcdb(ll x, ll y)
{
	if(x * y == 0) return 0;
	if(x == y) return twodb(x * x);
	if(x > y) return twodb(y * y) + (threedb(x) - threedb(y)) * y - (x - y) * twodb(y - 1);
	return twodb(x * x) + (threedb(y - 1) - threedb(x - 1)) * x + (y - x) * twodb(x);
}

ll calc(ll x, ll y)
{
	if(x * y == 0) return 0;
	if(x == y) return two(x * x) % P;
	if(x > y) return (two(y * y) + mul(three(x) - three(y), y) - mul(x - y, two(y - 1))) % P;
	return (two(x * x) + mul(three(y - 1) - three(x - 1), x) + mul(y - x, two(x))) % P;
}

#undef P
#define P 10000000000

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		double tmp = 0;
		ll x1, y1, x2, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		tmp = calcdb(x2, y2) - calcdb(x1 - 1, y2) - calcdb(x2, y1 - 1) + calcdb(x1 - 1, y1 - 1);
		if(tmp > 1e10 - 1e-3) {
			printf("...");
			printf("%010lld\n", ((calc(x2, y2) - calc(x1 - 1, y2) - calc(x2, y1 - 1) + calc(x1 - 1, y1 - 1)) % P + P) % P);
		} else printf("%lld\n", (ll) tmp);
	}
	return 0;
}