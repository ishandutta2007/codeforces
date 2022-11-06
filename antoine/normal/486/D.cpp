#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

const int mod = 1000000007;
int a[2001];
vector<int> adj[2001];

long long f(int u, int p, int bound) {
	if (a[u] < bound)
		return 0;

	long long ans = 1;
	for (auto &&v : adj[u])
		if (v != p)
			ans = (ans * (1 + f(v, u, bound))) % mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int d, n;
	cin >> d >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	vector<pair<int, int>> edges;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		edges.emplace_back(u, v);
	}

	sort(edges.begin(), edges.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
		return max(a[l.first], a[l.second]) < max(a[r.first], a[r.second]);
	});

	long long ans = n;
	for (auto &&e : edges) {
		int bound = max(a[e.first], a[e.second]) - d;
		ans = (ans + f(e.first, -1, bound) * f(e.second, -1, bound)) % mod;
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
	}

	cout << ans;
	return 0;
}