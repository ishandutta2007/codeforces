#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	sort(a, a + n);

	int m; cin >> m;
	while (m--)
	{
		ll x, y; cin >> x >> y;
		ll ans = -1;

		if (a[n - 1] >= x)
		{
			ll d = *lower_bound(a, a + n, x);
			ll res = max(0ll, y - (sum - d));
			
			if (ans == -1 || ans > res) ans = res;
		}

		if (a[0] < x)
		{
			ll d = *prev(lower_bound(a, a + n, x));
			ll res = x - d + max(0ll, y - (sum - d));

			if (ans == -1 || ans > res) ans = res;
		}

		cout << ans << '\n';
	}
}