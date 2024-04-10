#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].first;
		for (int i = 0; i < n; i++)
			cin >> a[i].second;

		sort(a, a + n);

		ll cx = 1, cy = 1;
		ll ans = 0;

		for (int i = 0; i < n; i++)
		{
			ll nx = a[i].first, ny = a[i].second;

			ll cur = cx - cy;
			ll nxt = nx - ny;

			if (cur % 2 == 0)
			{
				if (cur == nxt) ans += ny - cy;
				else ans += (nxt - cur) / 2;
			}
			else
			{
				ans += (nxt - cur + 1) / 2;
			}

			cx = nx, cy = ny;
		}

		cout << ans << '\n';
	}
}