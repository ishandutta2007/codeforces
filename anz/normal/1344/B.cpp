#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string board[1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool cache[1001][1001];

void DFS(int x, int y)
{
	cache[x][y] = 1;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[nx][ny] == '.') continue;
		if (cache[nx][ny]) continue;

		DFS(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];

	bool emp_row = 0, emp_col = 0;

	for (int i = 0; i < n; i++)
	{
		int l = 0, r = m - 1;
		while (l < m && board[i][l] == '.') l++;
		while (r >= 0 && board[i][r] == '.') r--;

		if (l == m) emp_row = 1;
		for (int j = l; j <= r; j++)
		{
			if (board[i][j] == '.')
			{
				cout << -1;
				return 0;
			}
		}
	}

	for (int j = 0; j < m; j++)
	{
		int l = 0, r = n - 1;
		while (l < n && board[l][j] == '.') l++;
		while (r >= 0 && board[r][j] == '.') r--;

		if (l == n) emp_col = 1;
		for (int i = l; i <= r; i++)
		{
			if (board[i][j] == '.')
			{
				cout << -1;
				return 0;
			}
		}
	}

	if (emp_row != emp_col)
	{
		cout << -1;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (board[i][j] == '.') continue;
		if (!cache[i][j])
		{
			ans++;
			DFS(i, j);
		}
	}

	cout << ans;
}