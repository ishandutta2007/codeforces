#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> tag(n), s(n);
		for (int i = 0; i < n; ++i) cin >> tag[i];
		for (int i = 0; i < n; ++i) cin >> s[i];
		vector <int> dp(n);
		for (int i = 0; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (tag[i] == tag[j]) continue;
				int l = abs(s[i] - s[j]);
				int vi = dp[j] + l;
				int vj = dp[i] + l;
				dp[i] = max(dp[i], vi);
				dp[j] = max(dp[j], vj);
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << "\n";
	}
}