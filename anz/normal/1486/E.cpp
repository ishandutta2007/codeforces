#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;

int n, m;
vector <pll> graph[100001];
ll dist[51][100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= 50; i++) for (int j = 1; j <= n; j++)
		dist[i][j] = INF;

	for (int i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	priority_queue<pair<ll, pii> > pq;
	dist[0][1] = 0; pq.push({ 0,{0,1} });

	while (!pq.empty())
	{
		auto it = pq.top(); pq.pop();
		int k = it.second.first;
		int v = it.second.second;
		ll cd = -it.first;

		if (cd > dist[k][v]) continue;

		for (auto to : graph[v])
		{
			int nv = to.first;
			ll d = to.second;
			int nk = (!k ? d : 0);
			ll nd = (!k ? 0 : (k + d) * (k + d));

			if (dist[nk][nv] > cd + nd)
			{
				dist[nk][nv] = cd + nd;
				pq.push({ -dist[nk][nv],{nk,nv} });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[0][i] == INF) cout << "-1 ";
		else cout << dist[0][i] << ' ';
	}
}