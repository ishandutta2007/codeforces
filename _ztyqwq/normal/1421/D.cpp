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
		int c1, c2, c3, c4, c5, c6;
		scanf("%lld %lld %lld %lld %lld %lld", &c1, &c2, &c3, &c4, &c5, &c6);
		for(int i = 1; i <= 10; i++)
		{
			c1 = min(c1, c6 + c2);
			c2 = min(c2, c1 + c3);
			c3 = min(c3, c2 + c4);
			c4 = min(c4, c3 + c5);
			c5 = min(c5, c4 + c6);
			c6 = min(c6, c5 + c1);
		}
		if(x >= 0 && y >= 0)
		{
			if(x > y)
				printf("%lld\n", y * c1 + (x - y) * c6);
			else
				printf("%lld\n", x * c1 + (y - x) * c2);
		}
		else if(x <= 0 && y <= 0)
		{
			if(x < y)
				printf("%lld\n", -y * c4 - (x - y) * c3);
			else
				printf("%lld\n", -x * c4 - (y - x) * c5);
		}
		else if(x >= 0 && y <= 0)
			printf("%lld\n", x * c6 - y * c5);
		else if(x <= 0 && y >= 0)
			printf("%lld\n", -x * c3 + y * c2);
	}
	return 0;
}