#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 987654321;

int n, x;
int a[501];

int dp[501][501][501];
int solve(int idx, int x, int val)
{
	if (idx == n) return 0;

	int& ret = dp[idx][x][val];
	if (ret != -1) return ret;

	ret = INF;
	if (a[idx] < val) return ret;

	ret = min(ret, solve(idx + 1, x, a[idx]));
	if (a[idx] > x && x >= val)
	{
		int res = solve(idx + 1, a[idx], x) + 1;
		ret = min(ret, res);
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
		cin >> n >> x;

		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= 500; j++) for (int k = 0; k <= 500; k++)
				dp[i][j][k] = -1;
		}

		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = solve(0, x, 0);
		if (ans == INF) cout << "-1\n";
		else cout << ans << '\n';
	}
}