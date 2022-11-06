#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int a[100001];
vector <int> graph[100001];

int cnt = 0;
int pxor;

int DFS(int v, int p)
{
	int res = a[v];
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		res ^= DFS(nv, v);
	}

	if (res == pxor)
	{
		cnt++;
		return 0;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) graph[i].clear();

		cnt = 0;
		pxor = 0;
		for (int i = 1; i <= n; i++) cin >> a[i], pxor ^= a[i];
		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		if (pxor == 0)
		{
			cout << "YES\n";
			continue;
		}

		if (DFS(1, 0) || k == 2 || cnt == 1)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
	}
}