#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
vector <pii> graph[200001];
set <pii> st[200001];
bool no[10][10][10][10];

int cmp(pii a, pii b) { return a.second < b.second; }

int solve(int deg, set<pii>& cst)
{
	if (deg > k)
	{
		return 1;
	}

	int res = 0;
	for (int i = 1; i <= deg; i++)
	{
		if (no[deg][i][deg][i]) continue;

		bool flag = true;
		for (auto it : cst)
		{
			int a = it.first;
			int b = it.second;

			if (no[deg][i][a][b])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			cst.insert({ deg, i });
			//tmp.push_back(i);
			res += solve(deg + 1, cst);
			//tmp.pop_back();
			cst.erase({ deg, i });
		}
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end(), cmp);
		for (int j = 0; j < graph[i].size(); j++)
		{
			int nv = graph[i][j].first;
			if (st[nv].find({ graph[i].size(), j + 1 }) != st[nv].end())
			{
				no[graph[i].size()][j + 1][graph[i].size()][j + 1] = 1;
			}
			else st[nv].insert({ graph[i].size(), j + 1 });
		}
	}

	for (int i = 1; i <= n; i++)
	{
		auto it = st[i].begin();
		while (it != st[i].end())
		{
			int a = it->first;
			int b = it->second;
			auto jt = next(it);
			while (jt != st[i].end())
			{
				int c = jt->first;
				int d = jt->second;

				no[a][b][c][d] = 1;
				no[c][d][a][b] = 1;
				jt++;
			}
			it++;
		}
	}

	
	int ans = 0;
	set <pii> cst;
	vector <int> tmp;
	ans += solve(1, cst);

	cout << ans;
}