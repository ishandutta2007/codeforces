#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL num[205];

int gcd(int x, int y)
{
	return !y ? x : gcd(y, x % y);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int a, b, q;
		scanf("%d%d%d", &a, &b, &q);
		if (a > b) swap(a, b);
		int d = a / gcd(a, b);
		while (q--)
		{
			LL l, r; scanf("%lld%lld", &l, &r);
			LL ans = 0;
			while ((r + 1) % b != 0)
				ans -= r % a != r % b % a, r++;
			while (l % b != 0)
				ans += l % a != l % b % a, l++;
			LL k1 = l / b - 1, k2 = r / b;
			ans += b * (k2 - k2 / d);
			ans -= b * (k1 - k1 / d);
			printf("%lld ", ans);
		}
		puts("");
	}
	return 0;
}