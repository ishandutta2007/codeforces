#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> s(n);
	vector<int> next(n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	int last_not_one = n;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] != 1)
			last_not_one = i;
		next[i] = last_not_one;
	}
	for (int i = 0; i < n; ++i) {
		if (i + s[i] > n - 1) {
			int want = max((int)1, n - 1 - i);
			ans += s[i] - want;
			s[i] = want;
		}
		while (s[i] > 1) {
			int cur = i;
			while (cur < n) {
				int ccur = cur;
				if (s[cur] != 1)
					cur += s[cur];
				else
					cur = next[cur];
				if (s[ccur] == 2) {
					s[ccur] = 1;
					int nxt = ccur;
					while (nxt < n && s[nxt] == 1)
						nxt++;
					for (int j = ccur; j >= 0 && s[j] == 1; --j)
						next[j] = nxt;
				} else {
					s[ccur] = max((int)1, s[ccur] - 1);
				}
			}
			ans++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}