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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

void dfs(int u, int p, vector<vector<int>> &adj) {
	assert(adj[u].size() <= 2);
	if (adj[u].size() == 1) {
		assert(adj[u][0] == p);
		cout << ' ' << u + 1;
	}
	for (auto &&v : adj[u])
		if (v != p)
			dfs(v, u, adj);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> deg(n, 0);
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		++deg[a];
		++deg[b];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int count = 0;
	for (auto &&x : deg)
		count += x >= 3;
	if (count >= 2) {
		cout << "No";
		return 0;
	}

	int root = 0;
	while (root + 1 < n && deg[root] <= 2)
		++root;
	cout << "Yes\n" << adj[root].size();
	for (auto &&x : adj[root]) {
		cout << '\n' << root + 1;
		dfs(x, root, adj);
	}
	return 0;
}