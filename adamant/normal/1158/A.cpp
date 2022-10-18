#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int b[n], g[m];
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		ans += b[i] * m;
	}
	for(int i = 0; i < m; i++) {
		cin >> g[i];
	}
	sort(b, b + n, greater<int>());
	sort(g, g + m);
	if(g[0] < b[0	]) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i < m; i++) {
		ans += g[i] - b[0];
	}
	ans += (b[0] != g[0]) * (g[0] - b[1]);
	cout << ans << endl;
	return 0;
}