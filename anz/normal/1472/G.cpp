#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 987654321;

int n, m;
vector <int> graph[200001];

int d[200001];
int dp[200001][2];

int solve(int v, int b)
{
	int& ret = dp[v][b];
	if (ret != -1) return ret;

	if (v == 1) return ret = 0;

	ret = d[v];
	for (int nv : graph[v])
	{
		if (d[v] < d[nv])
		{
			int res = solve(nv, b);
			ret = min(ret, res);
		}
		else if (b == 0)
		{
			int res = solve(nv, 1);
			ret = min(ret, res);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			d[i] = INF;
			dp[i][0] = dp[i][1] = -1;
		}

		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
		}

		queue <int> q;
		d[1] = 0; q.push(1);

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int nv : graph[v])
			{
				if (d[nv] != INF) continue;
				d[nv] = d[v] + 1;
				q.push(nv);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			int res = solve(i, 0);
			cout << res << ' ';
		}

		cout << '\n';
	}
}