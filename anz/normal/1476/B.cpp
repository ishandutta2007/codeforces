#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[101];
ll p[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			p[i] = a[i] + p[i - 1];
		}

		ll ans = 0;
		for (int i = n; i > 1; i--)
		{
			if (a[i] * 100 <= k * (p[i - 1] + ans)) continue;

			ll rm = (a[i] * 100 / k + (a[i] * 100 % k ? 1 : 0)) - (p[i - 1] + ans);
			ans += rm;
		}

		cout << ans << '\n';
	}
}