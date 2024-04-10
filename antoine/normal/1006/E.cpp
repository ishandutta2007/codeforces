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


const int MaxN = 2e5;
vector<int> adj[MaxN];
vector<int> inOrder;
int indexOf[MaxN];
int sizeOf[MaxN];

void dfs(int u) {
	indexOf[u] = inOrder.size();
	inOrder.push_back(u);
	sizeOf[u] = 1;
	sort(adj[u].begin(), adj[u].end());
	for (int &v : adj[u]) {
		dfs(v);
		sizeOf[u] += sizeOf[v];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, q;
	cin >> n >> q;

	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		adj[p].push_back(i);
	}

	dfs(0);

	while (q--) {
		int u, k;
		cin >> u >> k;
		--u;
		--k;
		if (k >= sizeOf[u])
			cout << -1;
		else
			cout << inOrder[indexOf[u] + k] + 1;
		cout << '\n';
	}

	return 0;
}