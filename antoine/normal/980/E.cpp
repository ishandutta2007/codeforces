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

// 4:18

int n, k;
vector<int> adj[(int)1e6];
array<int, 20> parents[(int)1e6];
bool ans[(int)1e6] = { 0 };

bool canInc(int u) {
	int cnt = 1;
	for (int i = 19; i >= 0; --i)
		if (parents[u][i] != -1 && !ans[parents[u][i]]) {
			u = parents[u][i];
			cnt += 1 << i;
		}
	return cnt <= k;
}

void inc(int u) {
	while (u != -1 && !ans[u]) {
		ans[u] = true;
		assert(--k >= 0);
		u = parents[u][0];
	}
}

void dfs(int u) {
	for (int i = 1; i < 20; ++i)
		parents[u][i] = parents[u][i - 1] == -1 ? -1 : parents[parents[u][i - 1]][i - 1];
	for (int &v : adj[u])
		if (v != parents[u][0]) {
			parents[v][0] = u;
			dfs(v);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> k;
	k = n - k;
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	parents[n - 1][0] = -1;
	dfs(n - 1);

	for (int i = n - 1; i >= 0; --i) {
		if (canInc(i)) {
			inc(i);
		}
	}
	assert(!k);
	for (int i = 0; i < n; ++i)
		if (!ans[i])
			cout << i + 1 << ' ';

	return 0;
}