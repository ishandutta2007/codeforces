#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll m, d, w;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> m >> d >> w;
		ll g = gcd(d - 1, w);

		ll dd = w / g;

		if (d == 1)
		{
			cout << "0\n";
			continue;
		}

		ll cnt = (min(d, m) - 1) / dd;
		ll ans = min(d, m) * cnt - cnt * (cnt + 1) / 2 * dd;
		cout << ans << '\n';
	}
}