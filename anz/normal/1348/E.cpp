#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[501], b[501];
bool dp[501][501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		sum += a[i] + b[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int x = 0; x <= min(k - 1, a[i]); x++)
			{
				if ((a[i] - x) % k == 0 || (a[i] - x) % k + b[i] >= k)
				{
					dp[i][j] |= dp[i - 1][(j + k - x) % k];
				}
			}
		}
	}

	ll ans = 0;
	for (int x = 0; x < k; x++)
	{
		if (dp[n][x])
		{
			ll res = (sum - x) / k;
			ans = max(ans, res);
		}
	}

	cout << ans;
}