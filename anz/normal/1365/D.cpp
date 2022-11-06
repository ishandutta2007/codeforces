#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string maze[51];

int cache[51][51];
void DFS(int i, int j)
{
	if (maze[i][j] == '#') return;
	cache[i][j] = 1;

	for (int k = 0; k < 4; k++)
	{
		int x = i + "1210"[k] - '1';
		int y = j + "2101"[k] - '1';

		if (x < 0 || x >= n || y < 0 || y >= m) continue;
		if (cache[x][y]) continue;
		if (maze[x][y] == '#') continue;

		DFS(x, y);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> maze[i];

		bool ans = true;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == 'B')
			{
				for (int k = 0; k < 4; k++)
				{
					int x = i + "1210"[k] - '1';
					int y = j + "2101"[k] - '1';

					if (x < 0 || x >= n || y < 0 || y >= m) continue;
					if (maze[x][y] == 'G') ans = false;
					if (maze[x][y] == '.') maze[x][y] = '#';
				}
			}
		}

		memset(cache, 0, sizeof cache);
		DFS(n - 1, m - 1);

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			if (maze[i][j] == 'G' && !cache[i][j]) ans = false;
		}

		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}