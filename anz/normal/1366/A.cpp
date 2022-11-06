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
		ll a, b; cin >> a >> b;
		if (a > b) swap(a, b);

		ll ans = 0;

		ll tmp = min(a, b - a);
		ans += tmp;

		a -= tmp, b -= tmp * 2;

		tmp = a / 3;
		ans += tmp * 2;

		a -= tmp * 3, b -= tmp * 3;
		if (a >= 1 && b >= 2) ans++;

		cout << ans << '\n';
	}
}