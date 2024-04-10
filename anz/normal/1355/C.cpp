#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, s;

vector <ll> mn, mx;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b, c, d; cin >> a >> b >> c >> d;

	ll ans = 0;
	for (ll y = b; y <= c; y++)
	{
		if (b + y <= c) continue;

		ll res = 0;
		if (a + y <= c)
		{
			ll tmp = b + y - c;
			res = tmp * (tmp + 1) / 2;

			if (b + y >= d)
			{
				ll tmp = d - b - y;
				res -= tmp * (tmp + 1) / 2;
			}
		}
		else if (a + y <= d)
		{
			ll tmp = b + y - c;
			res = tmp * (tmp + 1) / 2;

			tmp = a + y - c - 1;
			res -= tmp * (tmp + 1) / 2;
			if (d <= b + y)
			{
				tmp = b + y - d - 1;
				res -= tmp * (tmp + 1) / 2;
			}
		}
		else
		{
			res = (b - a + 1) * (d - c + 1);
		}

		ans += res;
	}

	cout << ans;
}