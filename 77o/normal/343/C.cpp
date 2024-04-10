#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> h(n), p(m);
	for (auto& i : h) {
		cin >> i;
	}
	for (auto& i : p) {
		cin >> i;
	}
	ll l = -1, r = LLONG_MAX / 2;
	while (l + 1 < r) {
		ll mid = (l + r) / 2;
		int cur = 0;
		for (int i = 0; i < n && cur < m; i++) {
			int nxt = cur;
			for (int j = cur; j < m; j++) {
				if (p[j] - p[cur] + min(abs(h[i] - p[cur]), abs(h[i] - p[j])) <= mid) {
					nxt = j + 1;
				} else {
					break;
				}
			}
			cur = nxt;
		}
		if (cur == m) {
			r = mid;
		} else {
			l = mid;
		}
	} 
	cout << r << endl;
    return 0;
}