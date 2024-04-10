#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int p[100001];
int h[100001];

vector <int> graph[100001];
int par[100001];
int child[100001];
int cgood[100001], cbad[100001];

void DFS(int v, int pr)
{
	par[v] = pr;
	child[v] = 0;
	cgood[v] = 0, cbad[v] = p[v];

	for (int nv : graph[v])
	{
		if (nv == pr) continue;
		child[v]++;
		DFS(nv, v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 1; i <= n; i++) cin >> h[i];

		for (int i = 1; i <= n; i++) graph[i].clear();
		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		DFS(1, 0);

		bool ans = true;
		queue <int> q;
		for (int i = 1; i <= n; i++) if (child[i] == 0) q.push(i);

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			int ch = cgood[v] - cbad[v];
			int mx = cgood[v] + cbad[v];
			if (h[v] < ch || h[v] > mx || (h[v] - ch) % 2 == 1)
			{
				ans = false;
				break;
			}

			int inv = (h[v] - ch) / 2;
			cgood[v] += inv;
			cbad[v] -= inv;

			if (par[v] && --child[par[v]] == 0) q.push(par[v]);
			cgood[par[v]] += cgood[v];
			cbad[par[v]] += cbad[v];
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}