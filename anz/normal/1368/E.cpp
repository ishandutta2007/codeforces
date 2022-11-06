#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> graph[200001];
int in[200001];
int mx[200001];
int res[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			graph[i].clear();
			in[i] = 0;
			mx[i] = 0;
		}

		for (int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			in[v]++;
		}

		queue <int> q;
		for (int i = 1; i <= n; i++)
		{
			if (in[i] == 0) q.push(i);
		}

		while (!q.empty())
		{
			int v = q.front(); q.pop();
			if (mx[v] == 2) res[v] = 0;
			else res[v] = mx[v] + 1;

			for (int nv : graph[v])
			{
				mx[nv] = max(mx[nv], res[v]);
				if (--in[nv] == 0) q.push(nv);
			}
		}

		vector <int> ans;
		for (int i = 1; i <= n; i++)
			if (res[i] == 0) ans.push_back(i);

		cout << ans.size() << '\n';
		for (int v : ans) cout << v << ' ';
		cout << '\n';
	}
}