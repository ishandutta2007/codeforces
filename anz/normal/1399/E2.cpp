#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n; ll s;
struct Node
{
	ll nv;
	ll w;
	ll c;
};

vector <Node> graph[100001];
set <pair<pair<ll, pll>, pii> > st1, st2;

ll cs = 0;
ll DFS(int v, int p)
{
	if (graph[v].size() == 1 && p)
		return 1;

	ll res = 0;
	for (auto it : graph[v])
	{
		int nv = it.nv;
		ll w = it.w;
		ll c = it.c;

		if (nv == p) continue;

		ll cr = DFS(nv, v);

		if (c == 1) st1.insert({ {(w - w / 2) * cr, {w, cr}}, {v, nv} });
		else if (c == 2) st2.insert({ {(w - w / 2) * cr, {w, cr}}, {v, nv} });

		res += cr;
		cs += cr * w;
	}

	return res;
}

vector <ll> s_all;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;
		for (int i = 1; i <= n; i++) graph[i].clear();
		st1.clear(), st2.clear();
		cs = 0;
		s_all.clear();
		s_all.push_back(0);

		for (int i = 0; i < n - 1; i++)
		{
			ll u, v, w, c; cin >> u >> v >> w >> c;
			graph[u].push_back({ v,w,c });
			graph[v].push_back({ u,w,c });
		}

		DFS(1, 0);

		while (!st1.empty())
		{
			auto it = --st1.end();
			ll dc = it->first.first;
			ll w = it->first.second.first;
			ll cr = it->first.second.second;
			pii eg = it->second;
			w /= 2;

			st1.erase(it);
			s_all.push_back(s_all.back() + dc);

			if (w) st1.insert({ {(w - w / 2) * cr, {w, cr}}, eg });
		}

		ll ans = numeric_limits<ll>::max();
		
		int idx = lower_bound(s_all.begin(), s_all.end(), cs - s) - s_all.begin();
		if (idx != s_all.size()) ans = idx;

		ll cur_cost = 0;

		while (!st2.empty() && cs > s)
		{
			auto it = --st2.end();
			ll dc = it->first.first;
			ll w = it->first.second.first;
			ll cr = it->first.second.second;
			pii eg = it->second;
			w /= 2;

			cur_cost += 2;
			st2.erase(it);
			cs -= dc;

			ll remain = cs - s;
			int idx = lower_bound(s_all.begin(), s_all.end(), remain) - s_all.begin();

			if (idx != s_all.size())
			{
				ll res = cur_cost + idx;
				ans = min(ans, res);
			}

			if (w) st2.insert({ {(w - w / 2) * cr, {w, cr}}, eg });
		}

		cout << ans << '\n';
	}
}