#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[301][301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		memset(ans, 0, sizeof ans);

		int x = 0, y = 0;
		while (k)
		{
			ans[x][y] = 1;
			k--;
			
			x = (x + 1) % n;
			y = (y + 1) % n;
			if (ans[x][y]) y++;
		}

		vector <int> r, c;
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++) sum += ans[i][j];
			r.push_back(sum);
		}
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++) sum += ans[j][i];
			c.push_back(sum);
		}

		int t1 = *max_element(r.begin(), r.end()) - *min_element(r.begin(), r.end());
		int t2 = *max_element(c.begin(), c.end()) - *min_element(c.begin(), c.end());

		int res = t1 * t1 + t2 * t2;
		cout << res << '\n';

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << ans[i][j];
			cout << '\n';
		}
	}
}