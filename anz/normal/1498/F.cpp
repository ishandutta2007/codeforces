#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
vector <int> graph[100001];
ll a[100001];

ll x[41][100001];
void DFS(int v, int p)
{
	x[0][v] = a[v];
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v);

		for (int i = 0; i < 2 * k; i++)
		{
			x[(i + 1) % (2 * k)][v] ^= x[i][nv];
		}
	}
}

ll ans[100001];
void DFS2(int v, int p)
{
	for (int i = k; i < k * 2; i++) ans[v] ^= x[i][v];

	for (int nv : graph[v])
	{
		if (nv == p) continue;

		for (int i = 0; i < 2 * k; i++)
		{
			x[(i + 1) % (2 * k)][v] ^= x[i][nv];
		}

		for (int i = 0; i < 2 * k; i++)
		{
			x[(i + 1) % (2 * k)][nv] ^= x[i][v];
		}

		DFS2(nv, v);

		for (int i = 0; i < 2 * k; i++)
		{
			x[(i + 1) % (2 * k)][nv] ^= x[i][v];
		}

		for (int i = 0; i < 2 * k; i++)
		{
			x[(i + 1) % (2 * k)][v] ^= x[i][nv];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) cin >> a[i];

	DFS(1, 0);
	DFS2(1, 0);

	for (int i = 1; i <= n; i++)
		cout << (ans[i] ? 1 : 0) << ' ';
}