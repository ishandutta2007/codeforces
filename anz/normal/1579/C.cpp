#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
string board[11];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) cin >> board[i];

		for (int i = n - 1; i >= 0; i--) for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '.') continue;
			
			vector <pii> tmp;
			tmp.push_back({ i, j });
			
			int sz = 0;
			while(true)
			{
				int x1 = i - 1 - sz, y1 = j - 1 - sz;
				int x2 = i - 1 - sz, y2 = j + 1 + sz;
				if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) break;
				if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) break;
				if (board[x1][y1] == '.' || board[x2][y2] == '.') break;

				tmp.push_back({ x1, y1 });
				tmp.push_back({ x2, y2 });
				sz++;
			}

			if (sz >= k)
			{
				for (auto it : tmp)
					board[it.first][it.second] = 'x';
			}
		}

		bool ans = true;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (board[i][j] == '*') ans = false;

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}