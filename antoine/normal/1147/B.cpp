#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n;

inline vector<vector<int>> f(const vector<pair<int, int>> &edges, const int offset) {
	DBG(offset)
	vector<vector<int>> adj(n);
	for (const pair<int, int> &e : edges) {
		int u = e.first;
		int v = e.second;
		u += offset;
		v += offset;
		if (u >= n)
			u -= n;
		if (v >= n)
			v -= n;

		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		if (u > v)
			swap(u, v);
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; ++i)
		sort(adj[i].begin(), adj[i].end());
	return adj;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;

	vector<pair<int, int>> edges(m);
	for (auto &&e : edges)
		cin >> e.first >> e.second;

	const vector<vector<int>> adj = f(edges, 0);

	for (int i = 1; i < n; ++i)
		if (n % i == 0 && f(edges, i) == adj) {
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
}