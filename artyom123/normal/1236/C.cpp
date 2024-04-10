#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int n;
	cin >> n;
	vector <vector<int>> ans(n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				ans[j].pb(i * n + j);
			}
		} else {
			for (int j = 0; j < n; j++) {
				ans[n - 1 - j].pb(i * n + j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto &c : ans[i]) {
			cout << c + 1 << " ";
		}
		cout << '\n';
	}
	return 0;
}