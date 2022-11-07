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
		for (int i = 0; i < n; i++) cin >> a[i];

		ll res = 0;
		ll tmp = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] >= tmp)
			{
				tmp = a[i];
				continue;
			}

			ll diff = tmp - a[i];
			res = max(res, diff);
		}

		ll ans = -1;
		for (ll i = 0; i < 40; i++)
		{
			if (res < (1ll << i))
			{
				ans = i;
				break;
			}
		}

		cout << ans << '\n';
	}
}