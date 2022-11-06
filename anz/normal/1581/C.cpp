#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int a[401][401];

int getSum(int x1, int y1, int x2, int y2, bool inv)
{
	int res = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
	if (inv) res = (x2 - x1 + 1) * (y2 - y1 + 1) - res;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			for (int j = 0; j < m; j++) a[i + 1][j + 1] = s[j] - '0';
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) a[i][j] += a[i][j - 1];
			for (int j = 1; j <= m; j++) a[i][j] += a[i - 1][j];
		}

		int ans = 1e9;
		for (int x1 = 1; x1 <= n; x1++) for (int x2 = x1 + 4; x2 <= n; x2++)
		{
			int mx = -1e9;

			for (int y = 4; y <= m; y++)
			{
				int tmp = getSum(x1 + 1, 1, x2 - 1, y - 4, false)
					+ getSum(x1, 1, x1, y - 3, true)
					+ getSum(x2, 1, x2, y - 3, true)
					+ getSum(x1 + 1, y - 3, x2 - 1, y - 3, false)
					- getSum(x1 + 1, y - 3, x2 - 1, y - 3, true);

				mx = max(mx, tmp);

				int res = getSum(x1 + 1, 1, x2 - 1, y - 1, false)
					+ getSum(x1, 1, x1, y - 1, true)
					+ getSum(x2, 1, x2, y - 1, true)
					+ getSum(x1 + 1, y, x2 - 1, y, true) - mx;

				ans = min(ans, res);
			}
		}

		cout << ans << '\n';
	}
}