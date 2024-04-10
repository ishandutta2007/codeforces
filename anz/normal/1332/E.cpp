#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;
const ll mpow(ll a, ll n) // a^n
{
	if (n == 0) return 1;
	ll t = mpow(a, n / 2);
	t = t * t % MOD;
	if (n % 2) t = t * a % MOD;
	return t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m, l, r; cin >> n >> m >> l >> r;
	n *= m;

	ll odd = (r - l) / 2 + 1;
	ll even = (r - l) / 2 + 1;

	if ((r - l) % 2 == 0)
	{
		if (l % 2) even--;
		else odd--;
	}

	ll ans;
	if (n % 2) ans = mpow(r - l + 1, n);
	else
	{
		ll res1 = mpow(odd + even, n);
		ll res2 = mpow(odd - even, n);

		ans = (res1 + res2) % MOD * mpow(2, MOD - 2) % MOD;
	}

	cout << ans;
}