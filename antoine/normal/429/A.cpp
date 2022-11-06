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

int n;
vector<int> adj[(int)1e5];
int a[(int)1e5];
vector<int> res;

void dfs(const int u, const int parent, array<int, 2> dp) {
	swap(dp[0], dp[1]);
	if (a[u] ^ dp[0]) {
		dp[0] ^= 1;
		res.push_back(u);
	}
	accumulate(adj[u].begin(), adj[u].end(), 0, [&](const int &acc, const int &v) {
		if (v != parent) dfs(v, u, dp);
		return 0;
	});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int rep = 0; rep < 2; ++rep) {
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a[i] ^= x;
		}
	}
	dfs(0, -1, { 0, 0 });
	cout << res.size() << '\n';
	for (auto &&x : res)
		cout << x + 1 << '\n';
	return 0;
}