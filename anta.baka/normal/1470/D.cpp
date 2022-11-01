#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> res(n, -1);
	set<int> q;
	vector<int> ans;
	auto paint = [&](int v) {
		res[v] = 1;
		ans.push_back(v);
		q.erase(v);
		for (int to : g[v]) {
			if (res[to] == -1) {
				res[to] = 0;
				q.erase(to);
				for (int kek : g[to]) {
					if (res[kek] == -1) {
						q.insert(kek);
					}
				}
			}
		}
	};
	q.insert(0);
	while (!q.empty()) {
		paint(*q.begin());
	}
	if (*min_element(res.begin(), res.end()) == -1) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n" << ans.size() << '\n';
		for (int u : ans) {
			cout << u + 1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--) {
		solve();
	}
}