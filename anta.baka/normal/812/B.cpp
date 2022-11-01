/*















*/

#include <bits/stdc++.h>

using namespace std;

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	char a[n][m + 2];
	for(int i = 0; i < n; i++) for(int j = 0; j < m + 2; j++) cin >> a[i][j];
	int c[n][2][2];
	bool go = true;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		c[i][0][1] = c[i][1][0] = m + 1;
		int lf = INT_MAX, rg = INT_MIN;
		for(int j = 0; j < m + 2; j++) if(a[i][j] == '1') lf = min(lf, j), rg = max(rg, j);
		if(lf == INT_MAX) { if(go) cnt++; c[i][0][0] = c[i][1][1] = 0; continue; }
		c[i][0][0] = 2 * rg;
		c[i][1][1] = 2 * (m + 1 - lf);
		go = false;
	}
	if(cnt == n) return cout << 0, 0;
	int lastfloor = cnt;
	int ans = INT_MAX;
	for(int mask = 0; mask < (1 << n); mask++) {
		bitset<15> foo = mask;
		if(foo[n - 1]) continue;
		int curans = 0;
		for(int i = n - 1; i >= 0; i--)
			if(i == lastfloor) {
				if(foo[i] == 0) curans += c[i][0][0] / 2;
				else curans += c[i][1][1] / 2;
				break;
			} else {
				curans++;
				curans += c[i][int(foo[i])][int(foo[i - 1])];
			}
		ans = min(ans, curans);
	}
	cout << ans;
}