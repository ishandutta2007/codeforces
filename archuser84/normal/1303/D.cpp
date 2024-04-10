#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll c[66] = { 0 };
		Loop(i, 0, m)
		{
			ll x;
			cin >> x;
			int l = 0;
			while (x > 0)
			{
				x >>= 1;
				l++;
			}
			c[l - 1]++;
		}
		bool poss = 1;
		ll ans = 0;
		for (int i = 0; n > 0; i++)
		{
			bool d = n & 1;
			if (d)
			{
				if (!c[i])
				{
					for (int j = 1; i + j < 66; j++)
					{
						if (c[i + j])
						{
							c[i + j]--;
							c[i] += 1LL << j;
							ans += j;
							break;
						}
					}
					if (!c[i])
					{
						poss = 0;
						break;
					}
				}
				c[i]--;
			}
			c[i + 1] += c[i] / 2;
			n >>= 1;
		}
		if (poss)
			cout << ans << '\n';
		else
			cout << "-1\n";
	}
}