#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int, int> gcd_ext(int a, int b)
{
	if(b == 0) return { 1, 0 };
	auto p = gcd_ext(b, a % b);
	return { p.second, p.first - p.second * (a / b) };
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i * i < n; i++)
	{
		if(n % i == 0 && __gcd(i, n / i) == 1)
		{
			int a = i, b = n / i;
			auto p = gcd_ext(a, b);
			ll x = p.first, y = p.second;
			x *= (n - 1);
			y *= (n - 1);
			if(x < 0)
			{
				ll k = -x / b;
				x -= k * b;
				y += k * a;
			}
			if(y < 0)
			{
				ll k = -y / a;
				x -= k * b;
				y += k * a;
			}
			while(x < 0)
			{
				x += b;
				y -= a;
			}
			while(y < 0)
			{
				x -= b;
				y += a;
			}
			puts("YES");
			puts("2");
			printf("%lld %d\n", x, b);
			printf("%lld %d\n", y, a);
			return 0;
		}
	}
	puts("NO");
}