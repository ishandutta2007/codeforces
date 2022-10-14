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
	int q;
	cin >> q;
	while (q--) {
		string s, t;
		cin >> s >> t;
		vector <int> cnt(26);
		for (auto &c : s) {
			cnt[c - 'a']++;
		}
		bool f = false;
		for (auto &c : t) {
			if (cnt[c - 'a'] >= 1) {
				cout << "YES" << "\n";
				f = true;
				break;
			}
		}
		if (!f) {
			cout << "NO" << "\n";
		}
	}
	return 0;
}