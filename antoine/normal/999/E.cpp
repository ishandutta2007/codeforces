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
bool visited[5000] = { false };
vector<int> adj[5000];
bool removed[5000] = { false };

void dfs(int u, int &count, const bool rem) {
	visited[u] = true;
	count++;
	if (rem) removed[u] = true;
	for(int &v:  adj[u])
		if (!visited[v]) {
			dfs(v, count, rem);
			// cout << "test\n";
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, s;
	cin >> n >> m >> s;
	--s;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}

	int count = 0;
	dfs(s, count, true);

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		if (removed[i]) continue;
		count = 0;
		memset(visited, false, sizeof visited);
		dfs(i, count, false);
		v.emplace_back(count, i);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	memset(visited, false, sizeof visited);

	int ans = 0;
	for (auto &&x : v)
		if (!removed[x.second] && !visited[x.second]) {
			dfs(x.second, count, false);
			ans++;
		}
	cout << ans;
	return 0;
}