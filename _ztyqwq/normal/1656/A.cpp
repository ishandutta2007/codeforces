#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[100010];
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n, mn = 1, mx = 1;
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for(int i = 2; i <= n; i++)
		{
			if(a[i] < a[mn])
				mn = i;
			if(a[i] > a[mx])
				mx = i;
		}
		printf("%lld %lld\n", mn, mx);
	}
	return 0;
}