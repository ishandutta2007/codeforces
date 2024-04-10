#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;

void solve() {
	int n;
	cin >> n;
	int d[n];
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d, d + n, greater<int>());
	int ans = d[0], sum = d[0];
	for(int i = 1; i < n; i++) {
		ans += i * d[i] - sum;
		sum += d[i];
	}
	cout << ans << "\n";
}

signed main() {
    //ignore = freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
		solve();
	}
    return 0;
}