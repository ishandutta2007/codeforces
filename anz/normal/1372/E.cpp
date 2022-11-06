#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> itv[101];

int dp[101][101];
int solve(int l, int r)
{
	if (l > r) return 0;

	int& ret = dp[l][r];
	if (ret != -1) return ret;

	ret = 0;
	for (int k = l; k <= r; k++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			int idx = lower_bound(itv[i].begin(), itv[i].end(), k) - itv[i].begin();

			int cl = itv[i][idx - 1] + 1, cr = itv[i][idx];
			if (l <= cl && cr <= r) cnt++;
		}

		int res = cnt * cnt + solve(l, k - 1) + solve(k + 1, r);
		ret = max(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		itv[i].push_back(0);
		int k; cin >> k;
		for (int j = 0; j < k; j++)
		{
			int l, r; cin >> l >> r;
			int sz = r - l + 1;
			itv[i].push_back(itv[i].back() + sz);
		}
	}

	memset(dp, -1, sizeof dp);
	cout << solve(1, m);
}