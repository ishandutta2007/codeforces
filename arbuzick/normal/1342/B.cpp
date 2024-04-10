#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string t;
		cin >> t;
		bool flag = true;
		for (int j = 1; j < t.size(); ++j) 
			if (t[j] != t[j - 1])
				flag = false;
		if (flag)
			cout << t << "\n";
		else {
			string ans = "";
			ans += t[0];
			for (int j = 1; j < t.size(); ++j) {
				if (t[j] == ans[ans.size() - 1]) {
					if (t[j] == '0')
						ans += "10";
					else
						ans += "01";
				}
				else
					ans += t[j];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}