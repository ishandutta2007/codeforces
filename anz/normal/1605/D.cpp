#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[200001];

vector <int> c[2];
void DFS(int v, int p, int f)
{
	c[f].push_back(v);
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v, 1 - f);
	}
}

int ans[200001];

vector <vector <int> > vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		vec.clear(); vec.emplace_back();
		int cur = 2;
		for (int i = 1; i <= n; i++)
		{
			if (i >= cur)
			{
				vec.emplace_back();
				cur *= 2;
			}

			vec.back().push_back(i);
		}

		sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return a.size() < b.size(); });

		for (int i = 1; i <= n; i++) graph[i].clear();
		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		c[0].clear(), c[1].clear();
		DFS(1, 0, 0);

		while(!vec.empty())
		{
			if (c[0].size() > c[1].size()) swap(c[0], c[1]);
			if (c[0].size() >= vec.back().size())
			{
				auto it = vec.back(); vec.pop_back();
				for (int v : it)
				{
					ans[c[0].back()] = v;
					c[0].pop_back();
				}
			}
			else if (c[1].size() >= vec.back().size())
			{
				auto it = vec.back(); vec.pop_back();
				for (int v : it)
				{
					ans[c[1].back()] = v;
					c[1].pop_back();
				}
			}
			else assert(false);
		}

		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}