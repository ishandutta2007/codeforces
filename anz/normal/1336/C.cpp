#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;

string s, t;
ll dp[3001][3001];

ll solve(int i, int j)
{
	if (i > j) return 1;
	ll& ret = dp[i][j];
	if (ret != -1) return ret;

	int idx = j - i;

	ret = 0;
	if (i >= t.size() || t[i] == s[idx])
	{
		ret += solve(i + 1, j);
		ret %= MOD;
	}

	if (j >= t.size() || t[j] == s[idx])
	{
		ret += solve(i, j - 1);
		ret %= MOD;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s >> t;

	memset(dp, -1, sizeof dp);

	ll ans = 0;
	for (int i = t.size() - 1; i < s.size(); i++)
	{
		ans += solve(0, i);
		ans %= MOD;
	}

	cout << ans;
}