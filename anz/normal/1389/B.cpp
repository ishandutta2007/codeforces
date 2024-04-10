#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k, z;
ll a[100001];
ll psum[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k >> z;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			psum[i] = psum[i - 1] + a[i];
		}

		ll ans = 0;

		for (ll i = 2; i <= k + 1; i++)
		{
			ll res = psum[i];
			ll rv = min(z * 2, k - (i - 1));
			ll rm = k - (i - 1) - rv;

			res += (a[i] + a[i - 1]) * (rv / 2);
			if (rv % 2) res += a[i - 1];

			if (rv % 2) res += psum[i + rm - 1] - psum[i - 1];
			else res += psum[i + rm] - psum[i];

			ans = max(ans, res);
		}

		cout << ans << '\n';
	}
}