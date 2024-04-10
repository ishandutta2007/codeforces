#include <bits/stdc++.h>
#define int long long

using namespace std;

main() {
	vector <pair <int, int> > ans;
	int n, k;
	cin >> n >> k;
	vector <vector <int> > g(n + 1);
	int v;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		g[v].push_back(i);
	}
	if (g[0].size() != 1) {
		cout << -1 << endl;
		return 0;
	}
	int counter = 1;
	for (int i = 1; i < n; i++) {
		int x = g[i - 1].size();
		int y = g[i].size();
		if (i == 1 && y > k) {
			cout << -1 << endl;
			return 0;
		} else if (i != 1) {
			if (k == 1 || (x * (k - 1) < y)) {
				cout << -1 << endl;
				return 0;
			}
		}
		for (int j = 0; j < y; j++) {
			if (i == 1) ans.push_back({g[0][0], g[i][j]});
			else ans.push_back({g[i - 1][j / (k - 1)], g[i][j]});
		}
		counter += y;
		if (counter == n)
			break;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}