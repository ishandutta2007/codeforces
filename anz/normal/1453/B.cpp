#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll ans = 0;
		ll mx = 0;
		for (int i = 1; i < n; i++)
		{
			ll res = llabs(a[i] - a[i - 1]);
			ans += res;

			if (i == 1 || i == n - 1)
			{
				mx = max(mx, res);
			}

			if (i + 1 < n)
			{
				if (a[i] - a[i - 1] >= 0 && a[i] - a[i + 1] >= 0)
				{
					ll res = min(a[i] - a[i - 1], a[i] - a[i + 1]) * 2;
					mx = max(mx, res);
				}

				if (a[i] - a[i - 1] <= 0 && a[i] - a[i + 1] <= 0)
				{
					ll res = min(a[i - 1] - a[i], a[i + 1] - a[i]) * 2;
					mx = max(mx, res);
				}
			}
		}

		cout << ans - mx << '\n';
	}
}