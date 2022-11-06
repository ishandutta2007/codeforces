#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

ll mpow(ll a, ll x)
{
	if (x == 0) return 1;
	ll res = mpow(a, x / 2);
	res = res * res % MOD;
	if (x % 2) res = res * a % MOD;
	return res;
}

string n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	ll ans = 0;

	ll sum = 0;
	ll m1 = mpow(10, n.size() - 1);
	ll m2 = n.size();

	for (ll i = 0; i < n.size() - 1; i++)
	{
		sum += n[i] - '0';
		m1 = m1 * mpow(10, MOD - 2) % MOD;
		m2--;

		ll res = sum * m1 % MOD * m2 % MOD;
		ans = (ans + res) % MOD;

		ll tmp2 = (n[i + 1] - '0') * mpow(10, n.size() - 2 - i) % MOD * (((i + 1) * (i + 2) / 2) % MOD) % MOD;
		ans = (ans + tmp2) % MOD;
	}

	cout << ans;
}