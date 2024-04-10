#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
int a[71][71];

int dp[71][71][71][71];
int solve(int i, int j, int used, int rm)
{
	if (j < 0)
	{
		if (rm == 0 && used == 0) return 0;
		else return -2;
	}

	int& ret = dp[i][j][used][rm];
	if (ret != -1) return ret;

	ret = -2;
	if (used > 0)
	{
		int res = solve(i, j - 1, used - 1, (rm + k - (a[i][j]) % k) % k);
		if (res != -2) ret = max(ret, res + a[i][j]);
	}

	int res = solve(i, j - 1, used, rm);
	if (res != -2) ret = max(ret, res);

	return ret;
}

int pre_ans[71][71];
int dp2[71][71];

int solve2(int idx, int rm)
{
	if (idx < 0)
	{
		if (rm == 0) return 0;
		else return -2;
	}

	int& ret = dp2[idx][rm];
	if (ret != -1) return ret;

	ret = -2;
	for (int i = 0; i < k; i++)
	{
		if (pre_ans[idx][i] == -1) continue;
		int res = solve2(idx - 1, (rm + k - i) % k);
		if (res != -2)
		{
			ret = max(ret, res + pre_ans[idx][i]);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);
	memset(pre_ans, -1, sizeof pre_ans);
	memset(dp2, -1, sizeof dp2);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < k; s++)
		{
			int res = -2;
			for (int j = 0; j <= m / 2; j++)
			{
				int cur = solve(i, m - 1, j, s);
				res = max(res, cur);
			}

			pre_ans[i][s] = max(pre_ans[i][s], res);
		}
	}

	int ans = solve2(n - 1, 0);
	cout << ans;
}