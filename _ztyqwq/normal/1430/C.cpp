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
		printf("2\n");
		if(n == 2)
			printf("1 2\n");
		else
		{
			printf("%lld %lld\n", n, n - 2);
			printf("%lld %lld\n", n - 1, n - 1);
			for(int i = n - 3; i >= 1; i--)
				printf("%lld %lld\n", i, i + 2);
		}
	}
	return 0;
}