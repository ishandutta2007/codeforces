#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
inline int fastpow(int a, int n)
{
	if(n >= 60)
		return 1000000000000000001ll;
	if(n == -1)
		return 1;
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n, k;
		scanf("%lld %lld", &n, &k);
		if(k > fastpow(2, n - 1))
			printf("-1\n");
		else
		{
			int pos = 1;
			while(pos <= n)
			{
				for(int i = 1; i <= n - pos + 1; i++)
				{
					int t = fastpow(2, n - pos - i);
					if(k <= t)
					{
						for(int j = pos + i - 1; j >= pos; j--)
							printf("%lld ", j);
						pos += i;
						break;
					}
					else
						k -= t;
				}
			}
			putchar('\n');
		}
	}
	return 0;
}