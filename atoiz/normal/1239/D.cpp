/*input
4
3 4
1 1
2 2
3 3
1 3
3 7
1 1
1 2
1 3
2 2
3 1
3 2
3 3
1 1
1 1
2 4
1 1
1 2
2 1
2 2


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
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 1e6 + 7;
int N, M;
vector<int> G[MAXN];

int solve()
{
	cin >> N >> M;
	FOR(i, 1, N) G[i].clear();
	FOR(i, 1, M) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
	}

	vector<int> low(N + 1, 0), vis(N + 1, 0);
	int curTime = 0;

	function<int(int)> dfs = [&](int u) {
		low[u] = vis[u] = ++curTime;
		int x;
		for (int v : G[u]) {
			if (!vis[v]) {
				if (x = dfs(v)) return x;
				low[u] = min(low[u], low[v]);
			} else {
				low[u] = min(low[u], vis[v]);
			}
		}

		if (low[u] == vis[u] && u != 1) return u;
		if (u == 1 && count(vis.begin() + 1, vis.end(), 0)) return 1;
		return 0;
	};

	int root = dfs(1);
	if (!root) return cout << "No\n", 0;

	fill(ALL(vis), 0);
	function<void(int)> dfsAssign = [&](int u) {
		vis[u] = 1;
		for (int v : G[u]) {
			if (!vis[v]) dfsAssign(v);
		}
	};
	dfsAssign(root);
	cout << "Yes\n";
	int p = count(vis.begin() + 1, vis.end(), 0);
	cout << N - p << ' ' << p << '\n';
	FOR(i, 1, N) if (vis[i]) cout << i << ' '; cout << '\n';
	FOR(i, 1, N) if (!vis[i]) cout << i << ' '; cout << '\n';
	return 0;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}