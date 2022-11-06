#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 250001;

int n, m, k;
vector <int> graph[N];

bool isLeaf[N];
int cache[N];
int par[N];
int lv[N];

void PATH(int v)
{
	vector <int> ans;
	while (v)
	{
		ans.push_back(v);
		v = par[v];
	}

	cout << "PATH\n";
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
	exit(0);
}

void DFS(int v, int p, int l)
{
	cache[v] = 1;
	par[v] = p;
	lv[v] = l;

	if (l == (n - 1) / k + 1)
	{
		PATH(v);
		return;
	}

	bool flag = true;
	for (int nv : graph[v])
	{
		if (cache[nv]) continue;
		flag = false;
		DFS(nv, v, l + 1);
	}

	if (flag) isLeaf[v] = 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1, 0, 1);

	int cnt = 0;
	cout << "CYCLES\n";
	for (int i = 1; i <= n && cnt < k; i++)
	{
		if (!isLeaf[i]) continue;

		vector <int> rv;
		for (int nv : graph[i])
		{
			if (nv == par[i]) continue;
			rv.push_back(nv);
			if (rv.size() == 2) break;
		}

		if (lv[rv[0]] > lv[rv[1]]) swap(rv[0], rv[1]);

		vector <int> ans;
		if ((lv[i] - lv[rv[0]] + 1) % 3)
		{
			int v = i;
			while (true)
			{
				ans.push_back(v);
				if (v == rv[0]) break;
				v = par[v];
			}
		}
		else if ((lv[i] - lv[rv[1]] + 1) % 3)
		{
			int v = i;
			while (true)
			{
				ans.push_back(v);
				if (v == rv[1]) break;
				v = par[v];
			}
		}
		else
		{
			int v = rv[1];
			while (true)
			{
				ans.push_back(v);
				if (v == rv[0]) break;
				v = par[v];
			}
			ans.push_back(i);
		}

		cout << ans.size() << '\n';
		for (int i : ans) cout << i << ' ';
		cout << '\n';

		cnt++;
	}
}