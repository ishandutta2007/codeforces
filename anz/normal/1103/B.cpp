#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

bool query(ll x, ll y)
{
	cout << "? " << x << ' ' << y << endl;
	char c; cin >> c;
	if (c == 'x') return 0;
	else return 1;
}

int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);

	string gm; cin >> gm;
	while (gm == "start")
	{
		if (!query(0, 1))
		{
			cout << "! 1" << endl;
			cin >> gm;
			continue;
		}

		ll x = 1, y = 2;
		while (true)
		{
			bool res = query(x, y);
			if (res)
			{
				x *= 2;
				y *= 2;
				continue;
			}

			ll l = 0, r = x;
			while (l + 1 < r)
			{
				ll m = (l + r) / 2;
				bool res = query(x - m - 1, y);
				if (!res) l = m;
				else r = m;
			}

			cout << "! " << x + l + 1 << endl;
			break;
		}

		cin >> gm;
	}
}