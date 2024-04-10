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
		int x1, y1, z1; cin >> x1 >> y1 >> z1;
		int x2, y2, z2; cin >> x2 >> y2 >> z2;

		ll ans = 0;

		ll tmp;
		tmp = min(z1, y2);
		ans += tmp * 2;
		z1 -= tmp;
		y2 -= tmp;

		tmp = min(z2, x1);
		z2 -= tmp;
		x1 -= tmp;

		tmp = min(z1, z2);
		z1 -= tmp;
		z2 -= tmp;

		tmp = min(z2, y1);
		ans -= tmp * 2;

		cout << ans << '\n';
	}
}