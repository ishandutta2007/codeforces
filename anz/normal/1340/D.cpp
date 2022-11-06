#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[100001];
vector <int> tree[100001];

void pre_DFS(int v, int p)
{
	for (auto nv : graph[v])
	{
		if (nv == p) continue;
		tree[v].push_back(nv);
		pre_DFS(nv, v);
	}
}

vector <pii> ans;
int DFS(int v, int p, int tm)
{
	ans.push_back({ v,tm });

	int ctm = tm;

	int rm = tm - 1;

	for (int i = 0; i < tree[v].size(); i++)
	{
		int nv = tree[v][i];

		int bk = tree[v].size() - i;
		if (bk <= rm)
		{
			if (ctm != rm - bk)
			{
				ctm = rm - bk;
				ans.push_back({ v, ctm });
			}
			
			ctm = DFS(nv, v, ctm + 1);
		}
		else
		{
			ctm = DFS(nv, v, ctm + 1);
		}

		ans.push_back({ v, ctm });
	}

	if (ctm != tm - 1)
	{
		ctm = tm - 1;
		if (v != 1) ans.push_back({ v,ctm });
	}

	return ctm + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	pre_DFS(1, 0);
	DFS(1, 0, 0);

	cout << ans.size() << '\n';
	for (auto it : ans) cout << it.first << ' ' << it.second << '\n';
}