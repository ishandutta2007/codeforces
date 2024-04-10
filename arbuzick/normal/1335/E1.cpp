#include<bits/stdc++.h>
using namespace std;
int pr[200][200001];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		vector<vector<int>> pos(200);
		for (int x = 0; x < 200; ++x) {
			pr[x][0] = 0;
			for (int i = 0; i < n; ++i) {
				pr[x][i + 1] = pr[x][i];
				if (a[i] == x + 1) {
					pr[x][i + 1] += 1;
					pos[x].push_back(i);
				}
			}
		}
		int ans = 0;
		for (int x = 0; x < 200; ++x) {
			ans = max(ans, pr[x][n]);
			for (int i = 0; i < pos[x].size() / 2; ++i) {
				int l = pos[x][i], r = pos[x][pos[x].size() - 1 - i];
				int m = 0;
				for (int y = 0; y < 200; ++y)
					m = max(m, pr[y][r] - pr[y][l + 1]);
				ans = max(ans, (i + 1) * 2 + m);
			}
		}
		cout << ans << endl;
	}
	return 0;
}