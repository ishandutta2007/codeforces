#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll x[5], y[5];

struct Node
{
	int x11, x12, x21, x22;
	int y11, y12, y21, y22;
};

Node idx[6] =
{
	{1,2,3,4,1,3,2,4},
	{1,2,3,4,1,4,2,3},
	{1,3,2,4,1,2,3,4},
	{1,3,2,4,1,4,2,3},
	{1,4,2,3,1,2,3,4},
	{1,4,2,3,1,3,2,4}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int i = 1; i <= 4; i++)
			cin >> x[i] >> y[i];

		ll ans = numeric_limits<ll>::max();

		for (int k = 0; k < 6; k++)
		{
			ll res = 0;

			ll x11 = x[idx[k].x11], x12 = x[idx[k].x12];
			ll x21 = x[idx[k].x21], x22 = x[idx[k].x22];

			if (x11 > x12) swap(x11, x12);
			if (x21 > x22) swap(x21, x22);

			ll y11 = y[idx[k].y11], y12 = y[idx[k].y12];
			ll y21 = y[idx[k].y21], y22 = y[idx[k].y22];

			if (y11 > y12) swap(y11, y12);
			if (y21 > y22) swap(y21, y22);

			res += x12 - x11 + x22 - x21;
			ll xl = max(x11 - x22, x21 - x12);
			ll xr = max(x22 - x11, x12 - x21);

			res += y12 - y11 + y22 - y21;
			ll yl = max(y11 - y22, y21 - y12);
			ll yr = max(y22 - y11, y12 - y21);

			if (xr < yl)
				res += (yl - xr) * 2;
			if (yr < xl)
				res += (xl - yr) * 2;

			ans = min(ans, res);
		}
	
		cout << ans << '\n';
	}
}