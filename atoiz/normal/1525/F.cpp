/*input
5 4 4
1 2
2 3
4 3
5 3
100 1
200 5
10 10
100 1

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second
const int64_t INF = 1e15;

struct Dinic {
	struct Edge {
		int v;
		int64_t f, c;
		Edge(int _v = 0, int64_t _f = 0, int64_t _c = 0): v(_v), f(_f), c(_c) {};
	};

	int n;
	vector<int> idx, dep, qu;
	vector<vector<int>> adj;
	vector<Edge> edges;

	Dinic(int _n): n(_n), idx(_n), dep(_n), adj(_n), edges(0) {}

	void addEdge(int u, int v, int64_t c) {
		adj[u].push_back((int) edges.size());
		edges.emplace_back(v, 0, c);
		adj[v].push_back((int) edges.size());
		edges.emplace_back(u, 0, 0);
	}

	bool levelGraph(int s, int t) {
		qu.clear();
		fill(dep.begin(), dep.end(), n + 1);
		fill(idx.begin(), idx.end(), 0);

		qu.push_back(s);
		dep[s] = 0;
		for (int qi = 0; qi < (int) qu.size() && qu.back() != t; ++qi) {
			int u = qu[qi];
			for (int i : adj[u]) {
				auto &e = edges[i];
				if (e.f < e.c && dep[u] + 1 < dep[e.v]) {
					dep[e.v] = dep[u] + 1;
					qu.push_back(e.v);
				}
			}
		}
		return dep[t] <= n;
	}

	int64_t sendFlow(int u, int t, int64_t f) {
		if (u == t) return f;
		for (int &i = idx[u]; i < (int) adj[u].size(); ++i) {
			auto &e = edges[adj[u][i]];
			if (e.f < e.c && dep[u] + 1 == dep[e.v]) {
				int64_t g = sendFlow(e.v, t, min(f, e.c - e.f));
				if (g > 0) {
					edges[adj[u][i]].f += g;
					edges[adj[u][i] ^ 1].f -= g;
					return g;	
				}
			}
		}
		return 0;
	}

	int64_t maxFlow(int s, int t) {
		while (levelGraph(s, t)) {
			while (sendFlow(s, t, INF));
		}

		int64_t flow = 0;
		for (int i : adj[s]) {
			flow += edges[i].f;
		}
		return flow;
	}

	int getMatch(int u) {
		for (int i : adj[u]) {
			auto &e = edges[i];
			if (e.f > 0) return e.v;
		}
		return 0;
	}

	vector<bool> partition(int s) {
		vector<bool> vis(n, false);
		vector<int> stk = {s};
		while (!stk.empty()) {
			int u = stk.back();
			stk.pop_back();
			vis[u] = true;
			for (int i : adj[u]) {
				auto &e = edges[i];
				if (e.f < e.c && !vis[e.v]) {
					stk.push_back(e.v);
				}
			}
		}
		return vis;
	}
};

// start of code

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	Dinic dn(2 * n + 2);
	vector<vector<int>> out(n + 1);
	vector<int> in(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;	
		out[u].push_back(v);
		++in[v];
		dn.addEdge(u, n + v, 1);
	}
	vector<ll> X(k + 1), Y(k + 1);
	FOR(i, 1, k) cin >> X[i] >> Y[i];


	FOR(i, 1, n) dn.addEdge(0, i, 1);
	FOR(i, 1, n) dn.addEdge(i + n, 2 * n + 1, 1);
	int maxCnt = n - dn.maxFlow(0, 2 * n + 1);
	vector<bool> partition = dn.partition(0);
	vector<int> cover;
	FOR(u, 1, n) {
		int v = dn.getMatch(u);
		if (!v) continue;
		if (!partition[u]) cover.push_back(u);
		if (partition[v]) cover.push_back(n - v);
	}

	ll bestCost = -1;
	vector<int> ans;

	if (maxCnt > k) {
		bestCost = accumulate(ALL(X), 0ll);
		ans.assign(k, 0);
	} else {
		vector<int> remCost(n + 1, 0);
		FOR(cnt, maxCnt, k) {
			remCost[cnt] = *min_element(Y.begin() + 1, Y.begin() + cnt + 1);
		}

		ll maxSave = 0;
		int saveAt = k + 1;
		FOR(last, 1, k) {
			ll curSave = accumulate(remCost.begin() + last, remCost.end(), 0ll) - X[last];
			if (curSave > maxSave) {
				maxSave = curSave;
				saveAt = last;
			}
		}

		bestCost = accumulate(ALL(X), 0ll) - accumulate(ALL(remCost), 0ll) + maxSave;

		int coverID = 0, remID = maxCnt;
		FOR(i, 1, k) {
			if (saveAt == i) {
				for (; remID <= k; ++remID) ans.push_back(cover[coverID++]);
			}
			for (; remID < saveAt && remID <= k && remCost[remID] == Y[i]; ++remID) ans.push_back(cover[coverID++]);
			ans.push_back(0);
		}
		assert(remID == k + 1);

		// ans.resize(maxCnt - bestCnt);
		// if (bestCnt > k) {
		// 	FOR(i, 1, k) ans.push_back(0);		
		// } else {
		// 	FOR(i, 1, bestCnt - 1) ans.push_back(0);
		// 	vector<bool> flag(n + 1, 0);
		// 	FORA(x, ans) flag[x] = 1;
		// 	FOR(i, 1, n) if (!flag[i]) ans.push_back(i);
		// 	FOR(i, bestCnt, k) ans.push_back(0);
		// }
	}
	// cout << bestCost << endl;

	cout << SZ(ans) << endl;
	FORA(x, ans) cout << x << ' '; cout << endl;

	return 0;
}