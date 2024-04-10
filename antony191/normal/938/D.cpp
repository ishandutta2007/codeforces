#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <set>
#include <map>


using namespace std;

#define ll long long

vector<ll> a;

struct po {
	int v;
};

bool operator <(const po & b, const po & c) {
	if (a[b.v] != a[c.v])
		return a[b.v] < a[c.v];
	return b.v < c.v;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> g(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		ll w;
		cin >> v >> u >> w;
		--v; --u;
		g[v].push_back({ u, w });
		g[u].push_back({ v, w });
	}
	a.resize(n);
	set<po> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		q.insert({ i });
	}
	while (!q.empty()) {
		auto v = q.begin()->v;
		q.erase(q.begin());
		for (auto to : g[v]) {
			if (a[v] + 2 * to.second < a[to.first]) {
				q.erase({ to.first });
				a[to.first] = a[v] + 2 * to.second;
				q.insert({ to.first });
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%lld ", a[i]);
	return 0;
}