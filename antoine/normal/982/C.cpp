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


int n;
vector<int> adj[(int)1e5];
int sz[(int)1e5] = { 0 };

int ans = 0;

void dfs(int u, int p) {
	sz[u] = 1;
	for (int &v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
			if (~sz[v] & 1)
				++ans;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	if (n & 1) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, -1);
	cout << ans;

	return 0;
}