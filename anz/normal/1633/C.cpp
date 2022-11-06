#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll up(ll a, ll b) { return (a + b - 1) / b; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ll hc, dc, hm, dm;
		cin >> hc >> dc >> hm >> dm;
		ll k, w, a;
		cin >> k >> w >> a;

		bool ans = false;
		for (ll i = 0; i <= k; i++)
		{
			ll res = up(hc + a * i, dm) - up(hm, dc + w * (k - i));
			if (res >= 0) ans = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}