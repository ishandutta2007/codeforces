#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int cg[4] = {0, 2, 3, 1};
inline int get(int u, int b)
{
	if(u == 1)
		return 0;
	int u4 = u >> 2, q = b / u4;
	return u4 * cg[q] + get(u4, b % u4);
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		if(n <= 3)
			printf("%lld\n", n);
		else
		{
			n--;
			int q = n / 3 - 1, r = n % 3, now = 4;
			while(q >= now)
			{
				q -= now;
				now <<= 2;
			}
			int num1 = now + q, num2 = (now << 1) + get(now, q);
			int num3 = num1 ^ num2;
			if(r == 0)
				printf("%lld\n", num1);
			else if(r == 1)
				printf("%lld\n", num2);
			else
				printf("%lld\n", num3);
		}
	}
	return 0;
}