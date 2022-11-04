#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll Sum[63];

int main()
{
	ll x, y;
	scanf("%lld%lld", &x, &y);
	if((x - y) & 1)
	{
		puts("0");
		return 0;
	}
	ll s = (x - y) / 2;
	ll ans = 1;
	for(int i = 62; i >= 0; i--)
	{
		bool B1 = (y >> i) & 1, B2 = (s >> i) & 1;
		if(B1 && B2)
		{
			puts("0");
			return 0;
		}
		if(B1 && !B2) ans *= 2;
	}
	if(x == y) ans -= 2;
	printf("%lld\n", ans);
	return 0;
}