#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		long long a, b, x, y;
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if (x < y) swap(x, y);
		if (x <= 0 && y <= 0) x = -x, y = -y;
		if (x >= 0 && y >= 0) printf("%lld\n", min(b * y + a * (x - y), a * (x + y)));
		else printf("%lld\n", a * (abs(x) + abs(y)));
	}
	return 0;
}