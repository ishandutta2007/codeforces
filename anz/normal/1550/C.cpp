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

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll ans = 2 * n - 1;
		for (int i = 0; i + 3 <= n; i++)
		{
			if (a[i] <= a[i + 1] == a[i + 1] <= a[i + 2]) continue;
			if (a[i] >= a[i + 1] == a[i + 1] >= a[i + 2]) continue;

			ans++;

			if (i + 3 < n)
			{
				if (a[i] <= a[i + 1] == a[i + 1] <= a[i + 3]) continue;
				if (a[i] >= a[i + 1] == a[i + 1] >= a[i + 3]) continue;

				if (a[i] <= a[i + 2] == a[i + 2] <= a[i + 3]) continue;
				if (a[i] >= a[i + 2] == a[i + 2] >= a[i + 3]) continue;

				if (a[i + 1] <= a[i + 2] == a[i + 2] <= a[i + 3]) continue;
				if (a[i + 1] >= a[i + 2] == a[i + 2] >= a[i + 3]) continue;

				ans++;
			}
		}

		cout << ans << '\n';
	}
}