#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;

		ll ans = 0;

		ll cur = 1;
		for (ll i = 2; cur <= n; i++)
		{
			ll g = gcd(cur, i);
			ll nxt = cur / g * i;

			ll cnt = n / cur - n / nxt;
			ans += cnt % MOD * i % MOD;
			ans %= MOD;

			cur = nxt;
		}

		cout << ans << '\n';
	}
}