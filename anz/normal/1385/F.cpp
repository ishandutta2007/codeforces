#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
set <int> graph[200001];
set <int> cleaf[200001];

bool cache[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			cleaf[i].clear();
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].insert(v);
			graph[v].insert(u);
		}

		for (int i = 1; i <= n; i++)
		{
			if (graph[i].size() == 1)
			{
				for (int nv : graph[i]) cleaf[nv].insert(i);
			}
		}

		queue <int> q;
		for (int i = 1; i <= n; i++)
		{
			if (cleaf[i].size() >= k)
			{
				q.push(i);
				cache[i] = 1;
			}
		}

		int ans = 0;
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			cache[v] = 0;

			while (cleaf[v].size() >= k)
			{
				ans++;
				for (int i = 0; i < k; i++)
				{
					int nv = *cleaf[v].begin();
					cleaf[v].erase(nv);
					cleaf[nv].erase(v);

					graph[v].erase(nv);
					graph[nv].erase(v);
				}
			}

			if (graph[v].size() == 1)
			{
				for (int nv : graph[v])
				{
					cleaf[nv].insert(v);
					if (cleaf[nv].size() >= k && !cache[v])
					{
						q.push(nv);
						cache[v] = 1;
					}
				}
			}
		}

		cout << ans << '\n';
	}
}