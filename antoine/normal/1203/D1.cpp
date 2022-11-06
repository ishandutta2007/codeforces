#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s, t;
	cin >> s >> t;

	const int n = (int) s.size(), m = (int) t.size();
	vector<int> first(m), last(m);

	for (int i = 0, j = 0; j < m; ++j) {
		while (s[i] != t[j]) {
			++i;
			assert(i < n);
		}
		first[j] = i++;
	}

	for (int i = n - 1, j = m - 1; j >= 0; --j) {
		while (s[i] != t[j]) {
			--i;
			assert(i >= 0);
		}
		last[j] = i--;
	}

	int ans = max(last[0], n - 1 - first.back());
	DBG(n-1-first.back())
	for (int j = 0; j + 1 < m; ++j) {
		ans = max(ans, last[j + 1] - first[j] - 1);
	}
	cout << ans;
	return 0;
}