#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

struct Edge {
	int v, c;
};

const int MaxN = (int) 3e5 + 9;
vector<Edge> adj[MaxN + 9];
int w[MaxN + 9];
ll ans = 0;

ll dfs(const int u, const int parent) {
	ll res = w[u];

	priority_queue<ll , vector<ll>, greater<ll>> pq;
	for (auto &&e : adj[u]) {
		if(e.v == parent) continue;
		const ll curr = dfs(e.v, u) - e.c;
		res = max(res, curr + w[u]);
		pq.push(curr);
		while(pq.size() > 2)
			pq.pop();
	}
	if(pq.size() == 2) {
		const ll a = pq.top();
		pq.pop();
		const ll b = pq.top();
		ans = max(ans, a + b + w[u]);
	}

	ans = max(ans, res);
	return res;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];

	for (int i = 1; i < n; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back( { v, c });
		adj[v].push_back( { u, c });
	}

	dfs(1, -1);
	cout << ans << endl;
	return 0;
}