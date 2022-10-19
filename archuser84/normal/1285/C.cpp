#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll my_pow(ll x, int p)
{
	if (p == 0)
		return 1;
	return x * my_pow(x, p - 1);
}

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

int main()
{
	ll x;
	cin >> x;
	ll ans = x;
	ll ans1 = 1, ans2 = x;
	vector<ll> taj;
	ll Sqr = sqrt(x);
	for (ll p = 2; x > 1 && p <= Sqr; ++p)
	{
		if (x % p == 0)
		{
			int n = 0;
			while (x % p == 0)
			{
				++n;
				x /= p;
			}
			taj.push_back(my_pow(p, n));
		}
	}
	if (x > 1)
	{
		taj.push_back(x);
	}
	
	int size = taj.size();
	int t = my_pow(2, size);
	for (int i = 0; i < t; ++i)
	{
		int j = i;
		ll a = 1, b = 1;
		for (int k = 0; k < size; ++k)
		{
			if (j % 2)
				b *= taj[k];
			else
				a *= taj[k];
			j /= 2;
		}
		if (max(a, b) < ans)
		{
			ans = max(a, b);
			ans1 = a;
			ans2 = b;
		}
	}

	cout << ans1 << ' ' << ans2 << '\n';
}