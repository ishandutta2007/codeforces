#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, t;
string board[1001];

vector <int> graph[1000001];

int cnt = 0;
int num[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int DFS(int x, int y)
{
	num[x][y] = cnt;

	int res = 1;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (num[nx][ny] != -1) continue;
		if (board[x][y] != board[nx][ny]) continue;

		res += DFS(nx, ny);
	}

	return res;
}

int dist[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) cin >> board[i];

	memset(num, -1, sizeof num);
	memset(dist, -1, sizeof dist);

	queue <int> q;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (num[i][j] == -1)
		{
			int res = DFS(i, j);

			if (res > 1)
			{
				q.push(cnt);
				dist[cnt] = 0;
			}
			cnt++;
		}
	}

	for (int x = 0; x < n; x++) for (int y = 0; y < m; y++)
	{
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (num[x][y] == num[nx][ny]) continue;
			graph[num[x][y]].push_back(num[nx][ny]);
			graph[num[nx][ny]].push_back(num[x][y]);
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		sort(graph[i].begin(), graph[i].end());
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}

	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (auto nv : graph[v])
		{
			if (dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1;
			q.push(nv);
		}
	}

	while (t--)
	{
		int i, j; ll p;
		cin >> i >> j >> p;
		i--; j--;

		if (dist[num[i][j]] == -1)
		{
			cout << board[i][j] << '\n';
			continue;
		}

		if (dist[num[i][j]] > p)
			cout << board[i][j] << '\n';
		else
			cout << ((board[i][j] - '0') ^ ((p - dist[num[i][j]]) % 2)) << '\n';
	}
}