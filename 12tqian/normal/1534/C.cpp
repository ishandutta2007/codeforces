#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

void solve_case(int tc = 0) {
	int n;
	cin >> n;
	vector<vector<int>> p(2, vector<int>(n));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> p[i][j];
			--p[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (p[0][i] == p[1][i]) {
			cout << 0 << '\n';
			return;
		}
	}
	vector<int> go(n);
	for (int i = 0; i < n; ++i) {
		go[p[0][i]] = p[1][i];
	}
	vector<bool> vis(n);
	int num = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) {
			continue;
		}
		vector<int> path;
		int cur = i;
		while (!vis[cur]) {
			vis[cur] = true;
			path.push_back(cur);
			cur = go[cur];
		}
		bool ok = false;
		for (int x : path) {
			if (x == cur) {
				ok = true;
				break;
			}
		}
		num += ok;
	}
	int ans = 1;
	for (int i = 0; i < num; ++i) {
		ans = ans + ans;
		if (ans >= P) {
			ans -= P;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; 
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc); 
	}
	return 0;
}