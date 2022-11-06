#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string board[2001];
ll same[2001][2001];
ll from_up[2001][2001];
ll from_down[2001][2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		int st = 0;
		int cnt = 1;
		for (int j = 1; j < m; j++)
		{
			if (board[i][j] != board[i][j - 1])
			{
				for (int k = st; k < j; k++)
					same[i][k] = min(k - st, j - 1 - k) + 1;

				st = j;
				cnt = 1;
			}
			else cnt++;
		}

		for (int k = st; k < m; k++)
			same[i][k] = min(k - st, m - 1 - k) + 1;
	}

	for (int j = 0; j < m; j++) from_up[0][j] = 1;
	for (int i = 1; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (board[i][j] == board[i - 1][j])
			from_up[i][j] = min(same[i][j], from_up[i - 1][j] + 1);
		else
			from_up[i][j] = 1;
	}

	for (int j = 0; j < m; j++) from_down[n - 1][j] = 1;
	for (int i = n - 2; i >= 0; i--) for (int j = 0; j < m; j++)
	{
		if (board[i][j] == board[i + 1][j])
			from_down[i][j] = min(same[i][j], from_down[i + 1][j] + 1);
		else
			from_down[i][j] = 1;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		ans += min(from_up[i][j], from_down[i][j]);

	cout << ans;
}