#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;

int hasLoop[400001];
vector <int> graph[400001];
vector <int> rgraph[400001];

vector<vector<int> > SCC;
int SCC_num[400001];

int cache[400001];
vector <int> stk;
void DFS(int v)
{
	cache[v] = 1;
	for (int nv : graph[v])
	{
		if (!cache[nv]) DFS(nv);
	}
	stk.push_back(v);
}

void DFS2(int v)
{
	cache[v] = 1;
	SCC.back().push_back(v);
	SCC_num[v] = SCC.size() - 1;

	for (int nv : rgraph[v])
	{
		if (!cache[nv]) DFS2(nv);
	}
}

int res[400001];
int solve(int s)
{
	int& ret = res[s];
	if (ret != -2) return ret;

	bool curLoop = (SCC[s].size() > 1 || hasLoop[SCC[s].back()]);
	if (SCC_num[1] == s)
	{
		if (curLoop) return ret = -1;
		return ret = 1;
	}

	vector <int> vec;
	for (int v : SCC[s]) for (int nv : rgraph[v])
	{
		int ns = SCC_num[nv];
		vec.push_back(ns);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	ret = 0;
	for (int ns : vec)
	{
		int res = solve(ns);
		if (res == -1) return ret = -1;
		ret = min(2, ret + res);
	}

	if (ret > 0 && curLoop) return ret = -1;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;

		SCC.clear();
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			rgraph[i].clear();
			hasLoop[i] = 0;
			SCC_num[i] = -1;
		}

		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;

			if (u == v) hasLoop[u] = 1;
			else
			{
				graph[u].push_back(v);
				rgraph[v].push_back(u);
			}
		}

		for (int i = 1; i <= n; i++) cache[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!cache[i]) DFS(i);
		}

		for (int i = 1; i <= n; i++) cache[i] = 0;
		while (!stk.empty())
		{
			int v = stk.back(); stk.pop_back();
			if (!cache[v])
			{
				SCC.emplace_back();
				DFS2(v);
			}
		}

		for (int i = 0; i < SCC.size(); i++) res[i] = -2;
		for (int i = 0; i < SCC.size(); i++) solve(i);

		for (int i = 1; i <= n; i++)
			cout << res[SCC_num[i]] << ' ';

		cout << '\n';
	}
}