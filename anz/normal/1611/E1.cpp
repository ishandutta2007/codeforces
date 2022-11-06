#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
vector <int> graph[200001];
int fri[200001];
int dist[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			fri[i] = -1;
			dist[i] = -1;
		}

		queue <int> q;
		for (int i = 0; i < k; i++)
		{
			int x; cin >> x;
			fri[x] = 0; q.push(x);
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int nv : graph[v])
			{
				if (fri[nv] != -1) continue;
				fri[nv] = fri[v] + 1;
				q.push(nv);
			}
		}

		q.push(1);
		dist[1] = 0;

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int nv : graph[v])
			{
				if (dist[nv] != -1) continue;
				if (dist[v] + 1 >= fri[nv]) continue;
				dist[nv] = dist[v] + 1;
				q.push(nv);
			}
		}

		bool ans = false;
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] != -1 && graph[i].size() == 1) ans = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}