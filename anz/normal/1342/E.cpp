#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;
ll n, k;
ll fac[200001];
ll inv_fac[200001];

ll mpow(ll n, ll a)
{
	if (a == 0) return 1;
	ll res = mpow(n, a / 2);
	res = res * res % MOD;
	if (a % 2) res = res * n % MOD;
	return res;
}

ll ncr(ll n, ll r)
{
	return fac[n] * inv_fac[r] % MOD * inv_fac[n - r] % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	if (n <= k)
	{
		cout << 0;
		return 0;
	}

	if (k == 0)
	{
		ll ans = 1;
		for (ll i = 1; i <= n; i++) ans *= i, ans %= MOD;
		cout << ans;
		return 0;
	}

	fac[0] = inv_fac[0] = 1;
	ll tmp = 1, inv_tmp = 1;
	for (ll i = 1; i <= n; i++)
	{
		tmp *= i; tmp %= MOD;
		fac[i] = tmp;

		inv_tmp *= mpow(i, MOD - 2); inv_tmp %= MOD;
		inv_fac[i] = inv_tmp;
	}

	ll ans = 0;
	for (ll i = 0; i < n - k; i++)
	{
		ll t = n - k - i;
		ll res = ncr(n - k, t) * mpow(t, n) % MOD;
		
		if (i % 2 == 0) ans += res, ans %= MOD;
		else ans += MOD - res, ans %= MOD;
	}
	ans *= ncr(n, k), ans %= MOD;
	ans *= 2, ans %= MOD;
	cout << ans;
}