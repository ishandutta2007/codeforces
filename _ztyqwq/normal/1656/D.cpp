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
		int n;
		scanf("%lld", &n);
		int k = 0, m = n;
		while(!(m & 1))
			k++, m >>= 1;
		if(m == 1)
			printf("-1\n");
		else
		{
			if(m <= 5000000000ll && m * (m + 1) / 2 <= n)
				printf("%lld\n", m);
			else
				printf("%lld\n", (1 << (k + 1)));
		}
	}
	return 0;
}