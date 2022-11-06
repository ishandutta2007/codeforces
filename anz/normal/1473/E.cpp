#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e12;

int n, m;
vector <pll> graph[200001];

ll dist[200001][4];
map <pair<int, pll>, ll> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++) dist[i][j] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;

		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>> > pq;
	dist[1][0] = 0;
	pq.push({ 0,{1,0} });
	
	while (!pq.empty())
	{
		auto it = pq.top(); pq.pop();
		ll cd = it.first;
		int v = it.second.first;
		int t = it.second.second;

		if (dist[v][t] < cd) continue;

		for (auto jt : graph[v])
		{
			int nv = jt.first;
			ll nd = jt.second;

			if (dist[nv][t] > cd + nd)
			{
				dist[nv][t] = cd + nd;
				pq.push({ cd + nd,{nv, t} });
			}

			if ((t & 1) == 0 && dist[nv][t | 1] > cd + nd + nd)
			{
				dist[nv][t | 1] = cd + nd + nd;
				pq.push({ cd + nd + nd,{nv,t | 1} });
			}

			if ((t & 2) == 0 && dist[nv][t | 2] > cd)
			{
				dist[nv][t | 2] = cd;
				pq.push({ cd,{nv,t | 2} });
			}

			if ((t & 3) == 0 && dist[nv][t | 3] > cd + nd)
			{
				dist[nv][t | 3] = cd + nd;
				pq.push({ cd + nd,{nv,t | 3} });
			}
		}
	}

	for (int i = 2; i <= n; i++) cout << dist[i][3] << ' ';
}