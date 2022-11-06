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
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 3>> edges;
	for (int i = 0; i < m; ++i) {
		int u, v, l;
		cin >> u >> v >> l;
		edges.push_back({ u, v, l });
	}

	set<int> storages;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		storages.insert(x);
	}

	int ans = 2e9;

	for (auto &&e : edges)
		if (e[2] < ans && (storages.count(e[0]) != storages.count(e[1]))) {
			ans = storages.count(e[0]) ? e[1] : e[0];
			ans = e[2];
		}
	cout << (ans == 2e9 ? -1 : ans);
	return 0;
}