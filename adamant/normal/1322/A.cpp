#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(count(all(s), '(') != count(all(s), ')')) {
		cout << -1 << endl;
	} else {
		int st = 0, bal = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			char c = s[i];
			if(c == '(') {
				bal++;
			} else {
				bal--;
			}
			if(c == ')' && bal == -1) {
				st = i;
			} else if(c == '(' && bal == 0) {
				ans += i - st + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}