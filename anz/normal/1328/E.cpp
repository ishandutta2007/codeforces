#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> graph[200001];

int par[200001][20];
int lv[200001];
void DFS(int v, int p, int l)
{
	//cout << "V : " << v << '\n';
	par[v][0] = p;
	lv[v] = l;

	for (auto nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v, l + 1);
	}
}

bool comp(int a, int b) { return lv[a] < lv[b]; }

int lca(int v1, int v2)
{
	for (int i = 19; i >= 0; i--)
	{
		if (lv[par[v2][i]] >= lv[v1]) v2 = par[v2][i];
	}

	return v2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, 1, 0);
	for (int j = 1; j < 20; j++) for (int i = 1; i <= n; i++)
		par[i][j] = par[par[i][j - 1]][j - 1];

	while (m--)
	{
		vector <int> v;
		int k; cin >> k;
		while (k--)
		{
			int x; cin >> x;
			x = par[x][0];
			v.push_back(x);
		}

		sort(v.begin(), v.end(), comp);
		v.erase(unique(v.begin(), v.end()), v.end());

		bool ans = true;
		for (int i = 1; i < v.size(); i++)
		{
			int pv = v[i - 1];
			int cv = v[i];
			
			int par = lca(pv, cv);
			if (par != pv)
			{
				ans = false;
				break;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}