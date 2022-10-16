#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	auto ask = [&](int x) -> vector<int> {
		vector<int> res(n);
		cout << "? " << x + 1 << endl;
		for (int i = 0; i < n; ++i) {
			cin >> res[i];
		}
		return res;
	};
	vector<vector<int>> dist(n);
	int root = 0;
	dist[root] = ask(root);	
	int even = 0;
	for (int i = 0; i < n; ++i) {
		if (dist[root][i] % 2 == 0) {
			++even;
		}
	}
	if (even > (n + 1) / 2) {
		for (int i = 0; i < n; ++i) {
			if (dist[root][i] % 2 == 1) {
				root = i;
				break;
			}
		}
		dist[root] = ask(root);
	}
	for (int i = 0; i < n; ++i) {
		if (i == root) {
			continue;
		}
		if (dist[root][i] % 2 == 1) {
			continue;
		}
		dist[i] = ask(i);
	}
	vector<array<int, 2>> edges;
	for (int i = 0; i < n; ++i) {
		if (dist[root][i] % 2 == 1) {
			continue;
		}
		for (int j = 0; j < n; ++j) {
			if (dist[i][j] == 1) {
				edges.push_back({i, j});
			}
		}
	}
	cout << "!" << '\n';
	for (int i = 0; i < n - 1; ++i) {
		cout << edges[i][0] + 1 << " " << edges[i][1] + 1 << '\n';
	}
	cout << endl;
	return 0;
}