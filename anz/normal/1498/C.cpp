#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 1e9 + 7;

ll n, k;
ll dp[2][1001][1001];
ll solve(int d, ll cn, ll k)
{
	if (k < 1) return 0;
	if (cn < 1 || cn > n) return 1;
	ll& ret = dp[d][cn][k];
	if (ret != -1) return ret;

	ret = 0;
	if (d == 0)
	{
		ll r1 = solve(0, cn + 1, k);
		ll r2 = solve(1, cn - 1, k - 1);
		ret += (r1 + r2) % MOD;
		ret %= MOD;
	}
	else
	{
		ll r1 = solve(1, cn - 1, k);
		ll r2 = solve(0, cn + 1, k - 1);
		ret += (r1 + r2) % MOD;
		ret %= MOD;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{	
		cin >> n >> k;

		for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++)
		{
			dp[0][i][j] = dp[1][i][j] = -1;
		}

		ll ans = solve(0, 1, k);
		cout << ans << '\n';
	}
}