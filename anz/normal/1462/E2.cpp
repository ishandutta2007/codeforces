#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;
ll mpow(ll a, ll n)
{
	if (n == 0) return 1;
	ll res = mpow(a, n / 2);
	res = res * res % MOD;
	if (n % 2) res = res * a % MOD;
	return res;
}

ll fact[200001];
ll inv_fact[200001];

ll ncr(ll n, ll r)
{
	ll res = fact[n];
	res = res * inv_fact[r] % MOD;
	res = res * inv_fact[n - r] % MOD;

	return res;
}

int n, m, k;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fact[0] = 1;
	inv_fact[0] = 1;

	for (ll i = 1; i <= 200000; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
		inv_fact[i] = inv_fact[i - 1] * mpow(i, MOD - 2) % MOD;
	}

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		ll ans = 0;
		for (ll i = 0; i < n; i++)
		{
			int ridx = upper_bound(a + i, a + n, a[i] + k) - a;
			if (i + m > ridx) continue;
			ll res = ncr(ridx - i - 1, m - 1);
			ans = (ans + res) % MOD;
		}

		cout << ans << '\n';
	}
}