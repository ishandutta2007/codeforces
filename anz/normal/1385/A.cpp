#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll x, y, z; cin >> x >> y >> z;

		bool ans = true;
		ll a, b, c;
		if (x == y)
		{
			if (z > x) ans = false;
			else
			{
				a = x;
				b = z;
				c = 1;
			}
		}
		else if (y == z)
		{
			if (x > y) ans = false;
			else
			{
				c = y;
				a = x;
				b = 1;
			}
		}
		else if (z == x)
		{
			if (y > z) ans = false;
			else
			{
				b = z;
				c = y;
				a = 1;
			}
		}
		else ans = false;

		if (!ans) cout << "NO\n";
		else
		{
			cout << "YES\n";
			cout << a << ' ' << b << ' ' << c << '\n';
		}
	}
}