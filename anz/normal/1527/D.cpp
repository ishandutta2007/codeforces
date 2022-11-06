#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
ll n;
vector <int> graph[N];

ll sz[N];
ll par[N];
int cache[N];
ll ans[N];

void DFS(int v, int p)
{
	par[v] = p;
	sz[v] = 1;
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v);
		sz[v] += sz[nv];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			graph[i].clear();
			ans[i] = 0;
			cache[i] = 0;
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		DFS(0, -1);

		for (int nv : graph[0])
		{
			ll csz = sz[nv];
			ans[0] += csz * (csz - 1) / 2;
		}

		ans[1] = n * (n - 1) / 2 - ans[0];

		int MEX = 0;
		int a = 0, b = 0;

		for (int v = 1; v < n; v++)
		{
			if (cache[v]) continue;

			int cv = v;
			while (true)
			{
				int pv = par[cv];

				if (pv == 0 || cache[pv] != 0)
				{
					if (pv == 0)
					{
						sz[0] -= sz[cv];
						if (a == 0) a = v;
						else b = v;
					}
					else
					{
						if (a == pv) a = v;
						else b = v;
					}

					cache[cv]++;
					cache[pv]++;
					cv = pv;
					break;
				}

				cache[cv]++;
				cache[pv]++;
				cv = pv;
			}

			if (cache[cv] > 2) break;

			while (cache[MEX]) MEX++;

			ans[MEX] = sz[a] * sz[b];
		}

		ll last = 0;
		for (int i = n; i > 0; i--)
		{
			if (ans[i] == 0) continue;
			ans[i] -= last;
			last += ans[i];
		}

		for (int i = 0; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}