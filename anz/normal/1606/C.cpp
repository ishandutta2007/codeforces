#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[11];

ll ten[11];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ten[0] = 1;
	for (int i = 1; i <= 10; i++) ten[i] = ten[i - 1] * 10;

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k; k++;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll ans = 0;
		for (int i = 1; i < n; i++)
		{
			ll c = min(k, ten[a[i] - a[i - 1]] - 1);
			ans += c * ten[a[i - 1]];

			k -= c;
		}

		ans += k * ten[a[n - 1]];

		cout << ans << '\n';
	}
}