#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<vector<int>> a((k + 1) / 2);
		for (int j = 0; j < a.size(); ++j)
			for (int l = 0; l < 26; ++l)
				a[j].push_back(0);
		for (int j = 0; j < n / k; ++j) {
			for (int l = 0; l < k / 2; ++l) {
				a[l][s[j * k + l] - 'a'] += 1;
				a[l][s[(j+1) * k - l - 1] - 'a'] += 1;
			}
			if (k % 2 == 1)
				a[k / 2][s[j * k + k / 2] - 'a'] += 1;
		}
		int ans = 0;
		for (int j = 0; j < a.size(); ++j) {
			int m = 0;
			for (int l = 0; l < 26; ++l)
				m = max(m, a[j][l]);
			if (k % 2 == 0 || j != a.size() - 1)
				ans = ans + (n / k * 2 - m);
			else
				ans = ans + (n / k - m);
		}
		cout << ans << endl;
	}
	return 0;
}