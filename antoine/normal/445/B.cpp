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

int n, m;
vector<int> adj[50];
int visited[50] = { 0 };

void dfs(int u, int &cnt) {
	++cnt;
	visited[u] = 1;
	for(auto &&v : adj[u])
		if (!visited[v]) {
			dfs(v, cnt);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll ans = 1;
	for (int i = 0; i < n; ++i)
		if(!visited[i]) {
			int count = 0;
			dfs(i, count);
			ans <<= (count - 1);
		}
	cout << ans;
	return 0;
}