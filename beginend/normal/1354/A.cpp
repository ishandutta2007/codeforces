#include<bits/stdc++.h>

typedef long long LL;

LL a, b, c, d;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (b >= a) printf("%lld\n", b);
		else
		{
			a -= b;
			if (d >= c) puts("-1");
			else printf("%lld\n",(a + c - d - 1) / (c - d) * c + b);
		}
	}
	return 0;
}