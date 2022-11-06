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

void No() {
	cout << "No\n";
	exit(0);
}

int n;
set<int> adj[(int)2e5 + 2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	adj[0].insert(1);

	auto it = a.begin();
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		const int u = q.front();
		if (adj[u].empty()) {
			q.pop();
			continue;
		}
		assert(it != a.end());
		if (!adj[u].count(*it))
			No();

		adj[u].erase(*it);
		adj[*it].erase(u);
		q.push(*it);
		it++;
	}

	assert(it == a.end());
	cout << "Yes\n";
	// erase parent
	return 0;
}