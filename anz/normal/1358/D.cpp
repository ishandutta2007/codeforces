#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, x;
ll d[400001];
ll psum[400001];
ll ss[400001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> x;
	for (int i = n; i > 0; i--) cin >> d[i], d[n + i] = d[i];
	for (int i = 1; i <= 2 * n; i++)
	{
		psum[i] = psum[i - 1] + d[i];
		ss[i] = ss[i - 1] + (d[i] * (d[i] + 1) / 2);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = i - 1, r = 2 * n;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			ll res = psum[m] - psum[i - 1];

			if (res <= x) l = m;
			else r = m;
		}

		ll rm = x - (psum[l] - psum[i - 1]);

		ll res = ss[l] - ss[i - 1];

		ll t1 = d[l + 1];
		ll t2 = d[l + 1] - rm;
		
		res += t1 * (t1 + 1) / 2 - t2 * (t2 + 1) / 2;

		ans = max(ans, res);
	}

	cout << ans;
}