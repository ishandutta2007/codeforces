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

vector<int> adj[(int)2e5];
int dp[(int)2e5][4];

int f(int u, int d, int parent) {

	assert(1 <= d && d <= 3);
	int &ans = dp[u][d];
	if (ans != -1) return ans;
	ans = (int)1e8;
	if (d != 1)
		ans = min(ans, 1 + f(u, 1, parent));

	const int sum = accumulate(adj[u].begin(), adj[u].end(), 0, [&](const int &acc, const int &v) {
			return acc + (v == parent ? 0 : f(v, min(3, d + 1), u));
	});
	if (d <= 2)
		ans = min(ans, sum);
	else if (!adj[u].empty()) {
		for (const int &v : adj[u])
			if (v != parent)
				ans = min(ans, sum - f(v, 3, u) + 1 + f(v, 1, u));
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);

	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << accumulate(adj[0].begin(), adj[0].end(), 0, [](const int &acc, const int &v) {
		return acc + f(v, 1, 0);
	});
	return 0;
}