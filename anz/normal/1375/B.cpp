#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int board[301][301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		bool ans = true;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (i == 0 || i == n - 1)
			{
				if (j == 0 || j == m - 1)
				{
					if (board[i][j] > 2) ans = false;
					board[i][j] = 2;
				}
				else
				{
					if (board[i][j] > 3) ans = false;
					board[i][j] = 3;
				}
			}
			else
			{
				if (j == 0 || j == m - 1)
				{
					if (board[i][j] > 3) ans = false;
					board[i][j] = 3;
				}
				else
				{
					if (board[i][j] > 4) ans = false;
					board[i][j] = 4;
				}
			}
		}

		if (!ans)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) cout << board[i][j] << ' ';
			cout << '\n';
		}
	}


}