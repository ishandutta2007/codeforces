#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int x, y;
		scanf("%lld %lld", &x, &y);
		if(x > y)
			printf("%lld\n", x + y);
		else
		{
			int b = 1, r = (y % x) / (b + 1), a = y / x / b;
			printf("%lld\n", a * x + r);
		}
	}
	return 0;
}