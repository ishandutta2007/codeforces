#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int dp[1000001];
int solve(int x)
{
	int& ret = dp[x];
	if (ret != -1) return ret;

	if (x == 0) return ret = 1;

	ret = 0;

	int el = 11;
	while (x >= el)
	{
		if (solve(x - el)) return ret = 1;
		el = el * 10 + 1;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);

	int t; cin >> t;
	while (t--)
	{
		int x; cin >> x;
		if (x > 1000000)
		{
			cout << "YES\n";
			continue;
		}

		if (solve(x)) cout << "YES\n";
		else cout << "NO\n";
	}
}