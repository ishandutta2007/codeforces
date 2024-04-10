#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 987654321;

int n, m, k;
vector <pair<pii, int > > graph[1001];

pair<pii, int> edge[1001];
int cnt[1001];
pii route[1001];

int dist[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		if (i == j) continue;
		dist[i][j] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		edge[i] = { {x,y}, w };

		graph[x].push_back({ {y,w},i });
		graph[y].push_back({ {x,w},i });
	}

	for (int i = 0; i < k; i++)
	{
		int x, y; cin >> x >> y;
		route[i] = { x,y };
	}

	for (int i = 1; i <= n; i++)
	{
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		pq.push({ 0, i });

		while (!pq.empty())
		{
			auto it = pq.top(); pq.pop();
			int v = it.second, d = it.first;
			if (dist[i][v] < d) continue;

			for (auto jt : graph[v])
			{
				int nv = jt.first.first, nd = jt.first.second;
				if (dist[i][nv] > d + nd)
				{
					dist[i][nv] = d + nd;
					pq.push({ dist[i][nv], nv });
				}
			}
		}
	}

	int ans = 987654321;

	for (int i = 0; i < m; i++)
	{
		int u = edge[i].first.first, v = edge[i].first.second;

		int res = 0;
		for (int i = 0; i < k; i++)
		{
			int x = route[i].first, y = route[i].second;
			int cd = dist[x][y];

			int cur = min(dist[x][u] + dist[v][y], dist[x][v] + dist[u][y]);
			cur = min(cur, dist[x][y]);

			res += cur;
		}

		ans = min(ans, res);
	}
	
	cout << ans;
}