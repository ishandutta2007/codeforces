#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n; ll s;
vector <pll> graph[100001];
set <pair<pair<ll, pll>, pii> > st;

ll cs = 0;
ll DFS(int v, int p)
{
	if (graph[v].size() == 1 && p)
		return 1;
	
	ll res = 0;
	for (auto it : graph[v])
	{
		int nv = it.first;
		ll w = it.second;

		if (nv == p) continue;

		ll cr = DFS(nv, v);
		st.insert({ {(w - w / 2) * cr, {w, cr}}, {v, nv} });

		res += cr;
		cs += cr * w;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;
		for (int i = 1; i <= n; i++) graph[i].clear();
		st.clear();
		cs = 0;

		for (int i = 0; i < n - 1; i++)
		{
			ll u, v, w; cin >> u >> v >> w;
			graph[u].push_back({ v,w });
			graph[v].push_back({ u,w });
		}

		DFS(1, 0);

		int ans = 0;
		while (!st.empty() && cs > s)
		{
			auto it = --st.end();
			ll dc = it->first.first;
			ll w = it->first.second.first;
			ll cr = it->first.second.second;
			pii eg = it->second;
			w /= 2;

			ans++;
			st.erase(it);
			cs -= dc;

			if(w) st.insert({ {(w - w / 2) * cr, {w, cr}}, eg });
		}

		cout << ans << '\n';
	}
}