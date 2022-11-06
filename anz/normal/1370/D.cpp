#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll ans = 2e9;

	ll l = 0, r = 1e9;

	int sz = 0;
	while (l + 1 < r)
	{
		sz = 0;

		ll m = (l + r) / 2;
		for (int i = 1; i <= n; i++)
		{
			if (sz % 2 == 0)
			{
				if (a[i] <= m) sz++;
			}
			else
			{
				sz++;
			}
		}

		if (sz >= k) r = m;
		else l = m;
	}

	ans = min(ans, r);

	l = 0, r = 1e9;
	sz = 0;

	while (l + 1 < r)
	{
		sz = 0;

		ll m = (l + r) / 2;
		for (int i = 1; i <= n; i++)
		{
			if (sz % 2 == 1)
			{
				if (a[i] <= m) sz++;
			}
			else
			{
				sz++;
			}
		}

		if (sz >= k) r = m;
		else l = m;
	}

	ans = min(ans, r);

	cout << ans;
}