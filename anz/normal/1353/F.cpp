#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;
int n, m;
ll a[101][101];
ll dp[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			cin >> a[i][j];

		ll ans = INF;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			ll s = a[i][j] - i - j;
			for (int x = 0; x < n; x++) for (int y = 0; y < m; y++)
			{
				ll h = s + x + y;
				if (a[x][y] < h)
				{
					dp[x][y] = INF;
					continue;
				}

				ll tmp = 0;
				if (x)
				{
					if (y) tmp = min(dp[x - 1][y], dp[x][y - 1]);
					else tmp = dp[x - 1][y];
				}
				else if (y) tmp = dp[x][y - 1];

				if (tmp == INF) dp[x][y] = INF;
				else dp[x][y] = a[x][y] - h + tmp;
			}

			ans = min(ans, dp[n - 1][m - 1]);
		}
		
		cout << ans << '\n';
	}
}