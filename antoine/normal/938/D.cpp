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

using namespace std;

long long a[(int)2e5];
vector<pair<int, long long>> adj[(int)2e5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	typedef pair<long long, int> plli;
	priority_queue<plli, vector<plli>, greater<plli>> pq;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pq.push({ a[i], i });
	}

	while (!pq.empty()) {
		int u = pq.top().second;
		long long w = pq.top().first;
		pq.pop();
		if (w != a[u])
			continue;
		for (auto &&other : adj[u]) {
			int v = other.first;
			w = other.second;
			long long newAV = a[u] + 2 * w;
			if (newAV < a[v]) {
				a[v] = newAV;
				pq.push({ a[v], v});
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
 	return 0;
}