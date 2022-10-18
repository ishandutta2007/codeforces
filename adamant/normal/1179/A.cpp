#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	deque<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m[q];
	int t = *max_element(begin(a), end(a));
	pair<int, int> ans[3 * n];
	int cur = 0;
	while(a[0] != t) {
		int x, y;
		tie(x, y) = tie(a[0], a[1]);
		ans[cur++] = {x, y};
		a.pop_front();
		a.pop_front();
		a.push_back(min(x, y));
		a.push_front(max(x, y));
	}
	for(int i = 0; i < q; i++) {
		cin >> m[i];
		m[i]--;
		if(m[i] < cur) {
			cout << ans[m[i]].first << ' ' << ans[m[i]].second << "\n";
		} else {
			cout << a[0] << ' ' << a[1 + (m[i] - cur) % (n - 1)] << "\n";
		}
	}
	return 0;
}