#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[200001];

int mnd[200001];
int mxd[200001];

void DFS(int v, int p, int cd)
{
	mxd[v] = cd;
	mnd[v] = 987654321;

	bool flag = true;
	for (int nv : graph[v])
	{
		if (nv == p) continue;

		flag = false;
		DFS(nv, v, cd + 1);
		mnd[v] = min(mnd[v], mnd[nv]);
		mxd[v] = max(mxd[v], mxd[nv]);
	}

	if (flag) mnd[v] = cd;
}

bool comp(int u, int v)
{
	return mnd[u] < mnd[v];
}

bool comp2(int u, int v)
{
	return mnd[u] > mnd[v];
}

int ans;
int DFS2(int v, int p)
{
	for (int i = 0; i < graph[v].size(); i++)
	{
		if (graph[v][i] == p)
		{
			graph[v].erase(graph[v].begin() + i);
			break;
		}
	}

	if (v == 1) sort(graph[v].begin(), graph[v].end(), comp);
	else sort(graph[v].begin(), graph[v].end(), comp2);

	for (int i = 0; i < graph[v].size(); i++)
	{
		int nv = graph[v][i];

		int cur = DFS2(nv, v);

		if (i == graph[v].size() - 1)
		{
			if (v == 1)
			{
				ans = max(ans, cur);
				return 0;
			}
			else
			{
				return cur + 1;
			}
		}
		else
		{
			ans = max(ans, cur + 1);
		}
	}

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) graph[i].clear();

		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		DFS(1, 0, 0);

		ans = 1;
		DFS2(1, 0);

		//cout << "ANS :";
		cout << ans << '\n';
	}
}