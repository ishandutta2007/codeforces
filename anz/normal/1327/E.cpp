#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;
ll n;

ll mpow(ll a, ll n)
{
	if (n == 0) return 1;

	ll res = mpow(a, n / 2);
	res = res * res % MOD;
	if (n % 2) res = res * a % MOD;

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		ll ans = 2 * 9 * mpow(10, n - i - 1) % MOD;
		if (n - i - 1 > 0)
		{
			ans += (n - i - 1) * 81 % MOD * mpow(10, n - i - 2) % MOD;
			ans %= MOD;
		}

		ans *= 10;
		ans %= MOD;

		cout << ans << ' ';
	}
	cout << 10;
}