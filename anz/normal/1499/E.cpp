#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

string x, y;

ll dp[27][1001][1001];
ll solve(int c, int xi, int yi)
{
	if (xi == x.size() && yi == y.size()) return 1;

	ll& ret = dp[c][xi][yi];
	if (ret != -1) return ret;

	ret = 1;

	if (xi < x.size() && c != x[xi] - 'a')
	{	
		ret += solve(x[xi] - 'a', xi + 1, yi);
		ret %= MOD;
	}
	if (yi < y.size() && c != y[yi] - 'a')
	{
		ret += solve(y[yi] - 'a', xi, yi + 1);
		ret %= MOD;
	}

	return ret;
}

ll dp2[27][1001];
ll solve2(int c, int xi, string& x)
{
	if (xi == x.size()) return 1;

	ll& ret = dp2[c][xi];
	if (ret != -1) return ret;

	ret = 1;
	if (xi < x.size() && c != x[xi] - 'a')
	{
		ret += solve2(x[xi] - 'a', xi + 1, x);
		ret %= MOD;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);

	cin >> x >> y;

	ll ans = 0;
	for (int i = 0; i < x.size(); i++) for (int j = 0; j < y.size(); j++)
	{
		ll res = solve(26, i, j);
		ans += res;
		ans %= MOD;
	}

	memset(dp2, -1, sizeof dp2);
	for (int i = 0; i < x.size(); i++)
	{
		ll res = solve2(26, i, x) * y.size() % MOD;
		ans += (MOD - res);
		ans %= MOD;
	}

	memset(dp2, -1, sizeof dp2);
	for (int i = 0; i < y.size(); i++)
	{
		ll res = solve2(26, i, y) * x.size() % MOD;
		ans += (MOD - res);
		ans %= MOD;
	}

	ans += (ll)x.size() * y.size() % MOD;
	ans %= MOD;

	cout << ans;
}