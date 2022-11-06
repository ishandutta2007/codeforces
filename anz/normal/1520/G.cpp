#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;

ll n, m, w;
int board[2001][2001];
ll distl[2001][2001];
ll distr[2001][2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(distl, -1, sizeof distl);
	memset(distr, -1, sizeof distr);

	cin >> n >> m >> w;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> board[i][j];

	ll fl = INF, fr = INF;

	queue <pii> q;
	distl[0][0] = 0;
	q.push({ 0,0 });

	while (!q.empty())
	{
		auto it = q.front(); q.pop();
		int x = it.first, y = it.second;

		if (board[x][y] > 0)
		{
			fl = min(fl, distl[x][y] * w + board[x][y]);
		}

		for (int k = 0; k < 4; k++)
		{
			int nx = x + "0121"[k] - '1';
			int ny = y + "1012"[k] - '1';

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1) continue;
			if (distl[nx][ny] != -1) continue;

			distl[nx][ny] = distl[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	distr[n - 1][m - 1] = 0;
	q.push({ n - 1,m - 1 });

	while (!q.empty())
	{
		auto it = q.front(); q.pop();
		int x = it.first, y = it.second;

		if (board[x][y] > 0)
		{
			fr = min(fr, distr[x][y] * w + board[x][y]);
		}

		for (int k = 0; k < 4; k++)
		{
			int nx = x + "0121"[k] - '1';
			int ny = y + "1012"[k] - '1';

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == -1) continue;
			if (distr[nx][ny] != -1) continue;

			distr[nx][ny] = distr[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	ll ans = INF;
	if (distr[0][0] != -1)
		ans = min(ans, distr[0][0] * w);

	ans = min(ans, fl + fr);
	if (ans == INF) cout << -1;
	else cout << ans;
}