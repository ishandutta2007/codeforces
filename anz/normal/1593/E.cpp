#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
vector <int> graph[400001];

int cache[400001];
int deg[400001];

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
			deg[i] = 0;
			cache[i] = 0;
		}

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);

			deg[u]++, deg[v]++;
		}

		int ans = n;

		vector <int> vec;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] <= 1)
			{
				vec.push_back(i);
				cache[i] = 1;
			}
		}

		while (k-- && !vec.empty())
		{
			vector <int> nvec;
			for (int v : vec)
			{
				ans--;

				for (int nv : graph[v])
				{
					if (cache[nv]) continue;
					if (--deg[nv] <= 1)
					{
						nvec.push_back(nv);
						cache[nv] = 1;
					}
				}
			}

			vec = nvec;
		}

		//cout << "ANS: ";
		cout << ans << '\n';
	}
}