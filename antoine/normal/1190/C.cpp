#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	string s;
	cin >> n >> k >> s;
	for (const char c : { '0', '1' })
		if (s.find_last_of(c) - s.find_first_of(c) < k) {
			cout << "tokitsukaze";
			return 0;
		}

	if ((int) s.size() <= 2 * k) {
		const int l = n - k - 1;
		if (s[0] == '1')
			reverse(s.begin(), s.end());
		if (s.substr(0, l) == string(l, '0') && s.substr(n - l) == string(l, '1')) {
			cout << "quailty";
			return 0;
		}
	}

	cout << "once again";
	return 0;
}