#include <iostream>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <tuple>
using namespace std;

vector <int> a, d;
long long ans = 0;

void update(int x) {
	if (d[x - 1] >= 0) ans -= d[x - 1];
	d[x - 1] = a[x] - a[x - 1];
	if (d[x - 1] >= 0) ans += d[x - 1];
	if (x < d.size()) {
		if (d[x] >= 0) ans -= d[x];
		d[x] = a[x + 1] - a[x];
		if (d[x] >= 0) ans += d[x];
	}
}

void solve() {
	int n, q, x, y;
	cin >> n >> q;
	a.assign(n + 1, 0);
	d.assign(n, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) d[i] = a[i + 1] - a[i];
	ans = 0;
	for (int i = 0; i < n; ++i) if (d[i] >= 0) ans += d[i];
	cout << ans << endl;
	while (q--) {
		cin >> x >> y;
		swap(a[x], a[y]);
		update(x), update(y);
		cout << ans << endl;
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	solve();
	}
}