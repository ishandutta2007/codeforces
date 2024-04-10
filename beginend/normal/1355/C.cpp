#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL get_sum(int l, int r)
{
	return (LL)(l + r) * (r - l + 1) / 2;
}

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	LL ans = 0;
	for (int i = a; i <= b; i++)
	{
		int k1 = b + i - 1, k2 = c + i - 1;
		if (k2 < c) continue;
		if (k1 >= d)
		{
			ans += (LL)(c - b + 1) * (d - c + 1);
			continue;
		}
		k1 = max(k1, c);
		if (k2 <= d) ans += get_sum(k1 - c + 1, k2 - c + 1);
		else ans += get_sum(k1 - c + 1, d - c + 1) + (LL)(k2 - d) * (d - c + 1);
	}
	printf("%lld\n", ans);
	return 0;
}