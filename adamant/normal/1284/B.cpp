#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 1e5 + 42;

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> s[n];
	int srt[n];
	vector<int> mx;
	int ans = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		int m;
		cin >> m;
		s[i].resize(m);
		for(int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
		srt[i] = is_sorted(begin(s[i]), end(s[i]), greater<int>());
		if(srt[i]) {
			mx.push_back(s[i][0]);
		} else {
			cnt++;
		}
	}
	sort(begin(mx), end(mx), greater<int>());
	for(int i = 0; i < n; i++) {
		if(!srt[i]) {
			ans += n;
		} else {
			ans += cnt + (lower_bound(begin(mx), end(mx), s[i].back(), greater<int>()) - begin(mx));
		}
	}
	cout << ans << endl;
	return 0;
}