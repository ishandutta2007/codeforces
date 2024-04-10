#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")
 
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n, m, k;
	cin >> n >> m >> k;
 
	int N = n * m;
 
	vector<vector<pair<int, int>>> G(N);
 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			int w;
			cin >> w;
			// w = rand() % 10;
			G[i * m + j].push_back({i * m + j + 1, w});
			G[i * m + j + 1].push_back({i * m + j, w});
		}
	}
 
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			int w;
			cin >> w;
			// w = rand() % 10;
			G[i * m + j].push_back({i * m + j + m, w});
			G[i * m + j + m].push_back({i * m + j, w});
		}
	}
 
	if (k % 2 == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cout << -1 << ' ';
			cout << '\n';
		}
		return 0;
	}
 	
	vector<int> ans(N, 0);
	int ops = 0;
	for (int t = 0; t < k / 2; ++t) {
		vector<int> nans(N, 1e9);
		for (int v = 0; v < N; ++v) {
			for (auto p : G[v]) {
				int to = p.first;
				int w = p.second;
				nans[v] = min(nans[v], 2 * w + ans[to]);
			}
		}
		ans = nans;
	}
 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << ans[i * m + j] << ' ';
		cout << '\n';
	}
	return 0;
}