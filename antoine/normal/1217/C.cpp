#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {
	int c0 = 0, ans = 0;
	string s;
	cin >> s;
	const int n = (int) s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0')
			c0++;
		else {
			int x = 0;
			for (int j = i; j < n && x <= n; ++j) {
				x = x << 1 | (s[j] - '0');
				ans += x <= j - i + 1 + c0;
			}
			c0 = 0;
		}
	}
	return ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}