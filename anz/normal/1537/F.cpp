#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
ll v[200001];
ll w[200001];

vector <int> graph[200001];

int cache[200001];
bool DFS(int v, int c)
{
	cache[v] = c;
	for (int nv : graph[v])
	{
		if (cache[nv])
		{
			if (cache[nv] == c) return false;
		}
		else
		{
			if (!DFS(nv, 3 - c)) return false;
		}
	}

	return true;
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
			cache[i] = 0;
		}

		for (int i = 1; i <= n; i++) cin >> v[i];
		for (int i = 1; i <= n; i++) cin >> w[i];
		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		if (!DFS(1, 1))
		{
			ll sum = 0;
			for (int i = 1; i <= n; i++)
			{
				sum += w[i] - v[i];
			}

			if (sum % 2 == 0) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}

		ll sum[2] = { 0,0 };
		for (int i = 1; i <= n; i++)
		{
			sum[cache[i] - 1] += w[i] - v[i];
		}

		if (sum[0] == sum[1]) cout << "YES\n";
		else cout << "NO\n";
	}
}