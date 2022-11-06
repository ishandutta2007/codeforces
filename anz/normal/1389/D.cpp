#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll l1, r1, l2, r2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> l1 >> r1 >> l2 >> r2;

		if (l1 > l2)
		{
			swap(l1, l2);
			swap(r1, r2);
		}

		ll its = 0;
		if (r1 > l2)
		{
			if (r1 <= r2) its = r1 - l2;
			else its = r2 - l2;
		}

		if (its * n >= k)
		{
			cout << "0\n";
			continue;
		}

		ll rm = k - its * n;

		ll ans = numeric_limits<ll>::max();
		for (int i = 0; i < n; i++) //   
		{
			ll res = 0;

			ll inc = rm / (n - i);
			ll irm = rm - inc * (n - i);

			if (r1 <= l2)
			{
				res += (l2 - r1) * irm;
			}

			ll tmp = min(inc + 1, max(r1, r2) - l1 - its);
			res += tmp * irm;
			res += (inc + 1 - tmp) * 2 * irm;

			if (inc)
			{
				if (r1 <= l2)
				{
					res += (l2 - r1) * (n - i - irm);
				}

				ll tmp = min(inc, max(r1, r2) - l1 - its);
				res += tmp * (n - i - irm);
				res += (inc - tmp) * 2 * (n - i - irm);
			}

			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}