#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		ll sum = 0;
		ll mx1 = -1, mx2 = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];

			if (a[i] > mx2) mx2 = a[i];
			if (mx2 > mx1) swap(mx1, mx2);
		}

		ll ans = 0;

		for (int i = 0; i < n; i++)
		{
			ll rm = -1;
			if (a[i] == mx1)
			{
				rm = mx2 * (n - 1) - (sum - a[i]);
			}
			else
			{
				rm = mx1 * (n - 1) - (sum - a[i]);
			}

			if (a[i] < rm)
			{
				ll res = rm - a[i];
				ans = max(ans, res);
			}
			else
			{
				ll res = ((n - 1) - (a[i] - rm) % (n - 1)) % (n - 1);
				ans = max(ans, res);
			}
		}

		cout << ans << '\n';
	}
}