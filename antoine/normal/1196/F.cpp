#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 2e5 + 9;
vector<pair<int, int>> adj[MxN + 9];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	map<pair<int, int>, ll> dist;
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;

	auto relax = [&](int u, int v, ll w) {
		if(u == v)
		return;
		if(u > v)
		swap(u, v);
		auto it =dist.find( {u, v});
		if(it != dist.end() && it->second <= w)
		return;
		dist[ {u, v}] = w;
		pq.push( {	w, {u, v}});
	};

	{
		vector<pair<ll, pair<int, int>>> vec;
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			vec.push_back( { w, { u, v } });
		}

		if ((int) vec.size() > k) {
			nth_element(vec.begin(), vec.begin() + k, vec.end());
			vec.resize(k);
		}

		for (const pair<ll, pair<int, int>> &entry : vec) {
			const ll w = entry.first;
			const int u = entry.second.first;
			const int v = entry.second.second;
			adj[u].push_back( { v, w });
			adj[v].push_back( { u, w });
			relax(u, v, w);
		}
	}

	for (;;) {
		assert(!pq.empty());
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		// cerr << u << ' ' << v << endl;
		const ll w = pq.top().first;
		pq.pop();
		if (dist.at( { u, v }) != w)
			continue;
		if (--k == 0) {
			cout << w;
			return 0;
		}
		for (int rep = 0; rep < 2; ++rep) {
			for (auto e : adj[u]) {
				const int x = e.first;
				const int w2 = e.second;
				relax(x, v, w + w2);
			}
			swap(u, v);
		}
	}
	return 0;
}