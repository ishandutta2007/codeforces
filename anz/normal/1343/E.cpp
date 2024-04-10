#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int a[3];
vector <int> graph[200001];
ll p[200001];

int dist[3][200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m >> a[0] >> a[1] >> a[2];

		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			dist[0][i] = dist[1][i] = dist[2][i] = -1;
		}

		for (int i = 1; i <= m; i++) cin >> p[i];

		sort(p + 1, p + m + 1);
		for (int i = 1; i <= m; i++) p[i] += p[i - 1];

		for (int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int k = 0; k < 3; k++)
		{
			dist[k][a[k]] = 0;
			queue <int> q;
			q.push(a[k]);

			while (!q.empty())
			{
				int v = q.front(); q.pop();
				for (auto nv : graph[v])
				{
					if (dist[k][nv] != -1) continue;

					dist[k][nv] = dist[k][v] + 1;
					q.push(nv);
				}
			}
		}

		ll ans = numeric_limits<ll>::max();
		for (int i = 1; i <= n; i++)
		{
			int da = dist[0][i];
			int db = dist[1][i];
			int dc = dist[2][i];

			if (da + db + dc > m) continue;
			ll res = p[da + db + dc] + p[db];
			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}