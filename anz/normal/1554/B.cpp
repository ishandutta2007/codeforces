#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];

		ll mxd = 2;
		while (mxd <= n) mxd *= 2;

		ll mx = n * (n - 1);

		ll ans = -1e18;
		for (ll i = n; i > 1; i--)
		{
			for (ll j = i - 1; j >= 1; j--)
			{
				if ((mx - i * j) > mxd * k) break;
				ll res = i * j - k * (a[i] | a[j]);
				ans = max(ans, res);
			}
		}

		cout << ans << '\n';
	}
}