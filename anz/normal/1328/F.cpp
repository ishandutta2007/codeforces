#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll k, n;
ll a[200001];
ll psum[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + a[i];

	ll ans = 2e18;
	for (int i = 1; i <= n; i++)
	{
		ll l = lower_bound(a + 1, a + n + 1, a[i]) - a;
		ll r = upper_bound(a + 1, a + n + 1, a[i]) - a;

		if (r - l >= k)
		{
			ans = 0;
			break;
		}

		ll rm = k - (r - l);
		
		ll lcnt = l - 1;
		ll rcnt = n + 1 - r;

		ll lsum = (a[i]-1) * lcnt - (psum[l - 1]);
		ll rsum = (psum[n] - psum[r - 1]) - (a[i] + 1) * rcnt;

		if (lcnt >= rm)
		{
			ll res = lsum + rm;
			ans = min(ans, res);
		}

		if (rcnt >= rm)
		{
			ll res = rsum + rm;
			ans = min(ans, res);
		}

		ll res = lsum + rsum + rm;
		ans = min(ans, res);
	}

	cout << ans;
}