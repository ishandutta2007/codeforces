#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

ll fac[500001];
ll mpow(ll a, ll n)
{
	if (n == 0) return 1;
	ll res = mpow(a, n / 2);
	res = res * res % MOD;
	if (n % 2) res = res * a % MOD;
	return res;
}

ll ncr(ll n, ll r)
{
	return fac[n] * mpow(fac[r], MOD - 2) % MOD * mpow(fac[n - r], MOD - 2) % MOD;
}

ll n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fac[0] = 1;
	for (ll i = 1; i <= 500000; i++)
		fac[i] = fac[i - 1] * i % MOD;

	ll ans = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		if (n / i - 1 < k - 1) continue;
		ans += ncr(n / i - 1, k - 1);
		ans %= MOD;
	}

	cout << ans;
}