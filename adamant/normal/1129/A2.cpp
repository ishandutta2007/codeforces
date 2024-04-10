#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define int int64_t
const double pi = acos(-1);

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    vector<int> from[n], to[n];
    for(int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		from[a[i]].push_back(i);
		to[b[i]].push_back(i);
	}
	int ans = 0;
	size_t mx = 0;
	for(int i = 0; i < n; i++) {
		mx = max(mx, from[i].size());
		if(from[i].size() > 1) {
			ans = max(ans, int(from[i].size() - 1) * n);
		}
	}
	for(int i = 0; i < n; i++) {
		int add = 0;
		for(int j = 0; j < n; j++) {
			int L = (i + j) % n;
			int mx1 = 2 * n, mx2 = 2 * n;
			for(auto it: from[L]) {
				int tt = j + (b[it] > a[it] ? b[it] - a[it] : n - (a[it] - b[it]));
				if(tt <= mx1) {
					mx2 = mx1;
					mx1 = tt;
				} else if(tt <= mx2) {
					mx2 = tt;
				}
			}
			mx1 = mx1 == 2 * n ? 0 : mx1;
			mx2 = mx2 == 2 * n ? 0 : mx2;
			if(from[L].size() == mx) {
				add = max({add, mx1});
			} else if(from[L].size() == mx - 1) {
				//cout << "!! " << mx1 << endl;
				add = max(add, mx1 - n);
			}
		}
		cout << ans + add << " ";
	}
    return 0;
}