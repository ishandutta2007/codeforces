#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 1e9;

int n, k;
int a[2001];
int dp[2001][2001];
int solve(int idx, int rm)
{
	if (idx == 0)
	{
		if (rm == 0) return 0;
		else return -INF;
	}

	int& ret = dp[idx][rm];
	if (ret != -1) return ret;

	ret = -INF;

	int res = solve(idx - 1, rm) + (a[idx] == idx - rm ? 1 : 0);
	ret = max(ret, res);

	if (rm > 0)
	{
		int res = solve(idx - 1, rm - 1);
		ret = max(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		memset(dp, -1, sizeof dp);

		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];

		int ans = -1;
		for (int i = 0; i < n; i++)
		{
			int res = solve(n, i);
			if (res >= k)
			{
				ans = i;
				break;
			}
		}

		cout << ans << '\n';
	}
}