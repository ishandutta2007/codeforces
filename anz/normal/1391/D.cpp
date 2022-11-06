#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int board[3][1000001];

int dp[1000001][8];
int solve(int idx, int st)
{
	if (idx == m) return 0;

	int& ret = dp[idx][st];
	if (ret != -1) return ret;

	ret = 987654321;

	for (int bs = 0; bs < (1 << n); bs++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (bs & (1 << i))
			{
				board[i][idx] = 1 - board[i][idx];
				cnt++;
			}
		}

		bool flag = true;
		for (int i = 0; i < n - 1; i++)
		{
			int one = board[i][idx - 1] + board[i][idx]
				+ board[i + 1][idx - 1] + board[i + 1][idx];

			if (one % 2 == 0) flag = false;
		}

		if (flag)
		{
			int res = solve(idx + 1, bs) + cnt;
			ret = min(ret, res);
		}

		for (int i = 0; i < n; i++)
		{
			if (bs & (1 << i))
			{
				board[i][idx] = 1 - board[i][idx];
			}
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	if (min(n, m) >= 4)
	{
		cout << -1;
		return 0;
	}

	if (min(n, m) == 1)
	{
		cout << 0;
		return 0;
	}

	// now 2 or 3

	if (n < m)
	{
		for (int i = 0; i < n; i++)
		{
			string tmp; cin >> tmp;
			for (int j = 0; j < m; j++) board[i][j] = tmp[j] - '0';
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			string tmp; cin >> tmp;
			for (int j = 0; j < m; j++) board[j][i] = tmp[j] - '0';
		}

		swap(n, m);
	}

	memset(dp, -1, sizeof dp);

	int ans = 987654321;
	for (int bs = 0; bs < (1 << n); bs++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (bs & (1 << i))
			{
				board[i][0] = 1 - board[i][0];
				cnt++;
			}
		}

		int res = solve(1, bs) + cnt;
		ans = min(ans, res);

		for (int i = 0; i < n; i++)
		{
			if (bs & (1 << i))
			{
				board[i][0] = 1 - board[i][0];
			}
		}
	}

	cout << ans;
}