#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll ten[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

ll dp[1 << 9][51];
ll solve(int bs, int rm)
{
	ll& ret = dp[bs][rm];
	if (ret != -1) return ret;
	if (rm == 0) return ret = 0;

	ret = -2;
	for (int i = 9; i >= 1; i--)
	{
		if (bs & (1 << i - 1)) continue;
		if (rm < i) continue;
		ll res = solve(bs | (1 << i - 1), rm - i);
		if (res != -2)
		{
			res = res * 10 + i;
			if (ret == -2 || ret > res) ret = res;
		}
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
		memset(dp, -1, sizeof dp);

		int x; cin >> x;
		ll ans = solve(0, x);
		if (ans == -2) ans = -1;
		cout << ans << '\n';
	}
}