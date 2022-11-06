#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
vector <int> graph[200001];

int par[200001];
ll len[200001];
ll child[200001];
ll oq[200001];

priority_queue <pii> pq;

int DFS(int v, int p, ll l)
{
	len[v] = l;
	par[v] = p;
	child[v] = 0;

	oq[v] = graph[v].size();
	if (v != 1) oq[v]--;

	for (auto nv : graph[v])
	{
		if (nv == p) continue;
		child[v] += DFS(nv, v, l + 1);
	}

	if (v != 1 && graph[v].size() == 1) pq.push({ len[v], v });

	return child[v] + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1, 0, 0);
	ll ans = 0;

	for (int i = 0; i < k; i++)
	{
		pll tmp = pq.top(); pq.pop();
		ans += tmp.first;

		int v = tmp.second;
		int p = par[v];

		if (--oq[p] == 0)
		{
			pq.push({ len[p] - child[p] ,p });
		}
	}

	cout << ans;
}