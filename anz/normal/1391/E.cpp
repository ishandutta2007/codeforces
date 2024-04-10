#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> graph[500001];
int cache[500001];
int par[500001];
vector <int> lv[500001];
bool isPath;

void PATH(int v)
{
	isPath = 1;
	cout << "PATH\n";
	vector <int> ans;
	while (v)
	{
		ans.push_back(v);
		v = par[v];
	}

	cout << ans.size() << '\n';
	for (int cv : ans) cout << cv << ' ';
	cout << '\n';
}

void DFS(int v, int p, int l)
{
	par[v] = p;
	cache[v] = 1;
	lv[l].push_back(v);

	if (!isPath && l >= (n + 1) / 2)
	{
		PATH(v);
	}

	for (int nv : graph[v])
	{
		if (cache[nv]) continue;
		DFS(nv, v, l + 1);
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
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			lv[i].clear();
			cache[i] = 0;
		}

		isPath = 0;

		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		DFS(1, 0, 1);

		if (isPath) continue;

		cout << "PAIRING\n";
		vector <pii> ans;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j + 1 < lv[i].size(); j += 2)
				ans.push_back({ lv[i][j], lv[i][j + 1] });
		}

		cout << ans.size() << '\n';
		for (pii it : ans) cout << it.first << ' ' << it.second << '\n';
	}
}