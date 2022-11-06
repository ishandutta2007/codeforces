#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <pii> ndir;

vector <pii> graph[200001];
int cache[200001];

vector <int> stk;
bool DFS(int v)
{
	cache[v] = 1;
	for (auto it : graph[v])
	{
		int nv = it.first;
		if (cache[nv] == 0)
		{
			if(DFS(nv)) return true;
		}
		else if (cache[nv] == 1) return true;
	}

	cache[v] = 2;
	stk.push_back(v);

	return false;
}

int dist[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;

		ndir.clear();
		stk.clear();

		for (int i = 1; i <= n; i++) graph[i].clear(), dist[i] = -1;

		for (int i = 0; i < m; i++)
		{
			int d, u, v; cin >> d >> u >> v;
			if (d == 0) ndir.push_back({ u,v });
			else graph[u].push_back({ v,1 });
		}

		for (int i = 1; i <= n; i++) cache[i] = 0;

		bool ans = true;
		for (int i = 1; i <= n; i++)
		{
			if (!cache[i])
			{
				if (DFS(i)) ans = false;
			}
		}

		if (!ans)
		{
			cout << "NO\n";
			continue;
		}

		for (pii e : ndir)
		{
			int u = e.first, v = e.second;
			graph[u].push_back({ v, 0 });
			graph[v].push_back({ u, 0 });
		}

		reverse(stk.begin(), stk.end());

		for (int i = 0; i < stk.size(); i++)
		{
			int v = stk[i];
			dist[v] = i;
		}

		int cnt = stk.size();

		cout << "YES\n";
		for (int v = 1; v <= n; v++)
		{
			for (auto it : graph[v])
			{
				int nv = it.first;
				int d = it.second;

				if (dist[v] < dist[nv]) cout << v << ' ' << nv << '\n';
			}
		}
	}
}