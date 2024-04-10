#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int Case;
LL p, q, b;

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%lld%lld%lld", &p, &q, &b);
		LL d = __gcd(p, q);
		p /= d, q /= d;
		while (q > 1)
		{
			d = __gcd(q, b);
			if (d == 1) break ;
			for (; q % d == 0; q /= d) ;
		}
		puts(q > 1 ? "Infinite" : "Finite");
	}
	return 0;
}