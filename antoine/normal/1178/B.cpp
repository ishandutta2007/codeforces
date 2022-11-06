#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;
	const int n = (int) s.size();
	int total = 0;
	for (int i = 0; i + 1 < n; ++i)
		total += s[i] == 'v' && s[i + 1] == 'v';
	ll curr = 0, ans = 0;
	for (int i = 0; i + 1 < n; ++i) {
		curr += s[i] == 'v' && s[i + 1] == 'v';
		if (s[i] == 'o')
			ans += curr * (total - curr);
	}
	cout << ans;
	return 0;
}