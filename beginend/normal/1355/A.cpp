#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int fun(LL a)
{
	int mn = 9, mx = 0;
	while (a)
	{
		mn = min((LL)mn, a % 10);
		mx = max((LL)mx, a % 10);
		a /= 10;
	}
	return mn * mx;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		LL a, k;
		scanf("%lld%lld", &a, &k);
		k--;
		while (k--)
		{
			int d = fun(a);
			if (!d) break;
			a += d;
		}
		printf("%lld\n", a);
	}
	return 0;
}