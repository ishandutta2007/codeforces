#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;
ll n, k;
ll cnt[1001];

ll mpow(ll a, ll k)
{
	if (k == 0) return 1;

	ll res = mpow(a, k / 2);
	res = res * res % MOD;
	if (k % 2) res = res * a % MOD;
	return res;
}

ll fact[1001];

ll ncr(ll n, ll r)
{
	ll res = fact[n];
	res = res * mpow(fact[r], MOD - 2) % MOD;
	res = res * mpow(fact[n - r], MOD - 2) % MOD;

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= 1000; i++)
		fact[i] = fact[i - 1] * i % MOD;

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		memset(cnt, 0, sizeof cnt);

		for (int i = 0; i < n; i++)
		{
			ll x; cin >> x;
			cnt[x]++;
		}

		ll ans = 1;

		ll rm = k;
		for (int i = n; i >= 1; i--)
		{
			ll av = min(rm, cnt[i]);
			ll res = ncr(cnt[i], av);
			ans = ans * res % MOD;

			rm -= av;
		}

		cout << ans << '\n';
	}
}