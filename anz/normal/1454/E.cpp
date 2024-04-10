#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
vector <int> graph[200001];

int cache[200001];
int isCircle[200001];

void DFS(int v, int p)
{
	cache[v] = 1;

	for (int nv : graph[v])
	{
		if (nv == p) continue;
		if (cache[nv])
		{
			if (cache[nv] == 1)
			{
				isCircle[nv] = 2;
				isCircle[v] = 1;
			}
		}
		else DFS(nv, v);

		if (isCircle[nv] == 1 && isCircle[v] != 2)
			isCircle[v] = 1;
	}

	cache[v] = 2;
}

int DFS2(int v, int p)
{
	int res = 1;
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		if (isCircle[nv]) continue;

		res += DFS2(nv, v);
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			cache[i] = 0;
			isCircle[i] = 0; 
		}

		for (int i = 0; i < n; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		ll ans = n * (n - 1);

		DFS(1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (isCircle[i])
			{
				ll res = DFS2(i, 0);
				ans -= res * (res - 1) / 2;
			}
		}

		cout << ans << '\n';
	}
}