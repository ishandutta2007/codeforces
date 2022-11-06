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

	ll a = 1, b = 0;
	for (int i = 0; i < n; i++)
	{
		ll c = (a + b) % MOD;
		a = b, b = c;
	}

	ll res = b;
	ll inv = mpow(2, MOD - 2);

	for (int i = 0; i < n; i++)
	{
		res = res * inv % MOD;
	}

	cout << res;
}