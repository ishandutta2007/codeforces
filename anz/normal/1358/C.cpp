#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		ll mn = min(x2 - x1, y2 - y1);
		ll mx = max(x2 - x1, y2 - y1);

		ll ans = (mn - 1) * mn;
		ans += (mx - mn + 1) * mn;

		cout << ans + 1 << '\n';
	}
}