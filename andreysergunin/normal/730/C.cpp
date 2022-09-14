#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int INF = 1e9;

vector<vector<int>> g;

struct Store {
	long long c, k, p;
};


vector<int> bfs(int v) {
	int n = sz(g);
	vector<int> dist(n, INF);
	queue<int> q;
	dist[v] = 0;
	q.push(v);

	for (; !q.empty(); ) {
		int u = q.front();
		for (int i = 0; i < sz(g[u]); ++i) {
			if (dist[g[u][i]] > dist[u] + 1) {
				dist[g[u][i]] = dist[u] + 1;
				q.push(g[u][i]);
			}
		}
		q.pop();
	}
	return dist;
}

int main() {
	// freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int t;
	cin >> t;
	vector<Store> store(t);
	vector<pair<long long, int>> v;
	store.resize(t);

	for (int i = 0; i < t; ++i) {
		long long c, k, p;
		cin >> c >> k >> p;
		--c;
		store[i] = {c, k, p};
		v.push_back({p, i});
	}

	// for (int i = 0; i < t; ++i)
	// 	cout << store[i].c << " " << store[i].k << " " << store[i].p <<  endl;

	sort(all(v));

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		long long g, r, a;
		cin >> g >> r >> a;
		--g;
		vector<int> dist = bfs(g);
		// for (int j = 0; j < n; ++j)
		// 	cout << dist[j] << " ";
		// cout << endl;

		int ll = -1, rr = n + 1;
		while (rr - ll > 1) {
			long long mid = (ll + rr) / 2;
			long long cur = r;
			long long cost = 0;

			for (int j = 0; j < t; ++j) {
				int id = v[j].second;
				if (dist[store[id].c] <= mid) {
					long long x = min(cur, store[id].k);
					cur -= x;
					cost += x * store[id].p;
				}
			}

			// cout << mid << endl;
			// cout << cur << " " << cost << endl;

			if (cur == 0 && cost <= a)
				rr = mid;
			else 
				ll = mid;
		}

		if (rr == n + 1)
			cout << -1 << endl;
		else
			cout << rr << endl;

	}
	

}