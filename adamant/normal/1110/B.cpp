#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int b[n];
    int d[n - 1];
    for(int i = 0; i < n; i++) {
		cin >> b[i];
		if(i > 0) {
			d[i - 1] = b[i] - b[i - 1] - 1;
		}
	}
	sort(d, d + n - 1);
	int ans = n;
	for(int i = 0; i < n - k; i++) {
		ans += d[i];
	}
	cout << ans << endl;
    return 0;
}