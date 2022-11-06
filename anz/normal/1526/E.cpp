#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

ll n, k;
int s[200001];
int inv_s[200001];

ll fact[200001];
ll inv_fact[200001];

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
	if (n < r) return 0;
	return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i <= 200000; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv_fact[i] = mpow(fact[i], MOD - 2);
	}

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		inv_s[s[i]] = i;
	}

	inv_s[n] = -1;

	int cnt = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int a = inv_s[s[i] + 1];
		int b = inv_s[s[i + 1] + 1];

		if (a > b) cnt++;
	}

	ll ans = 0;
	for (ll i = cnt; i <= k; i++)
	{
		ll res = ncr(n - cnt, i - cnt);
		res = res * ncr(k, i) % MOD;
		ans = (ans + res) % MOD;
	}

	cout << ans;
}