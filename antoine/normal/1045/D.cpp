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

ll p[(int)1e5 + 1];
vector<int> adj[(int)1e5 + 1];
int parent[(int)1e5 + 1];
ll dp[(int)1e5 + 1];

inline ll getLL() {
	float x;
	cin >> x;
	return (ll)(x*100.0 + 1e-3);
}

void bfs(const int start) {
	static int q[(int)1e5 + 1];
	int head = 0, tail = 1;
	q[0] = start;
	
	while (head != tail) {
		const int u = q[head++];
		
		for (const int &v : adj[u])
			if (v != parent[u]) {
				parent[v] = u;
				q[tail++] = v;
			}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		p[i] = getLL();

	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	p[n] = 100;
	adj[n].push_back(0);
	adj[0].push_back(n);
	parent[n] = -1;
	bfs(n);

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (100 - p[i]) * p[parent[i]];
		dp[parent[i]] += 100 - p[i];
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int i;
		cin >> i;
		const ll x = getLL();

		ans += (p[i] - x) * p[parent[i]];
		ans += dp[i] * (x - p[i]);
		dp[parent[i]] += p[i] - x;

		p[i] = x;

		cout << ans / 1e4 << '\n';
	}
	return 0;
}