#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;
ll n, k, q;

ll a[5001];
ll dp[5001][5001];
ll res[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) dp[0][i] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j - 1 >= 1) dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= n) dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			res[i] += dp[j][i] * dp[k - j][i] % MOD;
			res[i] %= MOD;
		}

		ans += a[i] * res[i] % MOD;
		ans %= MOD;
	}

	while (q--)
	{
		ll i, x; cin >> i >> x;
		ll d = x - a[i];
		a[i] = x;

		ans += (res[i] * d % MOD + MOD) % MOD;
		ans %= MOD;

		cout << ans << '\n';
	}
}