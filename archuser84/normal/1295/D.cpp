#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll gcd(ll a, ll b)
{
	ll x = a, y = b;
	while (y != 0)
	{
		ll h = x;
		x = y;
		y = h % y;
	}
	return x;
}

int npPow(ll x)
{
	return (x % 2) * (-2) + 1;
}

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		ll a, m;
		cin >> a >> m;
		vector<ll> fac;
		ll sq = sqrt(m);
		ll n = m;
		ll b = a;
		for (ll i = 2; i <= sq; i++)
		{
			if (n % i == 0)
			{
				int count = 0;
				while (n % i == 0)
				{
					n /= i;
					count++;
				}
				int c2 = 0;
				while (b % i == 0)
				{
					b /= i;
					c2++;
				}
				if (count > c2)
					fac.push_back(i);
			}
		}
		if (n > 1 && a % n != 0)
		{
			fac.push_back(n);
		}
		ll g = gcd(a, m);

		ll ans = 0;
		ll size = 1 << fac.size();
		for (ll i = 0; i < size; i++)
		{
			ll y = g;
			ll count = 0;
			ll j = i;
			ll p = 0;
			while (j > 0)
			{
				if (j & 1)
				{
					y *= fac[p];
					count++;
				}
				p++;
				j >>= 1;
			}
			ll min;
			if (a % y == 0)
				min = a;
			else
				min = a + y - (a % y);
			ll max = (a + m - 1) - ((a + m - 1) % y);
			if (min < max)
				ans += npPow(count) * (1 + (max - min) / y);
			else if (min == max)
				ans += npPow(count);
		}
		cout << ans << '\n';
	}
}