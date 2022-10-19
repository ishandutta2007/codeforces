#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		string s;
		cin >> s;
		vector<bool> changed(s.size(), 0);
		int ans = 0;

		for (int i = 1; i < s.size(); i++) {
			bool flag = 0;
			if (s[i - 1] == s[i] && changed[i - 1] == false) {
				flag = 1;
			}
			if (i > 1 && s[i - 2] == s[i] && changed[i - 2] == false) {
				flag = 1;
			}
			// cout << i << ' ' << flag << '\n';
			ans += flag;
			changed[i] = flag;
		}

		cout << ans << '\n';
	}

	return 0;
}