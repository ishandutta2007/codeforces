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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<vector<int>> adjT(n);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adjT[v].push_back(u);
	}

	vector<int> remover(n, -1);

	for (int i = 0; i < n; ++i) {
		if (remover[i] != -1) continue;
		remover[i] = i;
		for (auto &&x : adj[i])
			if (remover[x] == -1)
				remover[x] = i;
	}

	vector<bool> included(n, false);
	for (int i = n - 1; i >= 0; --i) {
		if (remover[i] != i) continue;
		included[i] = true;
		for (auto &&x : adjT[i])
			if (included[x]) {
				included[i] = false;
				break;
			}

	}


	cout << accumulate(included.begin(), included.end(), 0) << '\n';
	for (int i = 0; i < n; ++i)
		if (included[i])
			cout << i + 1 << ' ';
	return 0;
}