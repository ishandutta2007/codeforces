#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[51], b[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		ll min_a = *min_element(a, a + n);
		ll min_b = *min_element(b, b + n);

		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll ca = a[i] - min_a;
			ll cb = b[i] - min_b;

			ans += max(ca, cb);
		}

		cout << ans << '\n';
	}
}