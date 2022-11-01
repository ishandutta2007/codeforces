#include<bits/stdc++.h>
using namespace std;
int num[101][101];
int ans[100001];
int cnt = 0;
void solve(int x, int y) {
	bool vis[4] = {0,0,0,0};
	int tot = 0;
	if (num[x][y]) tot ^= 1, vis[0] ^= 1;
	if (num[x+1][y]) tot ^= 1, vis[1] ^= 1;
	if (num[x][y+1]) tot ^= 1, vis[2] ^= 1;
	if (num[x+1][y+1]) tot ^= 1, vis[3] ^= 1;
	if (tot)
		for (int i = 0; i < 4; i++) vis[i] ^= 1;
	if (vis[0]) ans[++cnt] = x + 1, ans[++cnt] = y, ans[++cnt] = x, ans[++cnt] = y+1, ans[++cnt] = x+1, ans[++cnt] = y+1;
	if (vis[1]) ans[++cnt] = x, ans[++cnt] = y, ans[++cnt] = x, ans[++cnt] = y+1, ans[++cnt] = x+1, ans[++cnt] = y+1;
	if (vis[2]) ans[++cnt] = x + 1, ans[++cnt] = y, ans[++cnt] = x, ans[++cnt] = y, ans[++cnt] = x+1, ans[++cnt] = y+1;
	if (vis[3]) ans[++cnt] = x + 1, ans[++cnt] = y, ans[++cnt] = x, ans[++cnt] = y+1, ans[++cnt] = x, ans[++cnt] = y;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m, cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				num[i][j] = c - '0';
			}
		if ((n & 1) && (m & 1) && num[n][m]) {
			ans[++cnt] = n, ans[++cnt] = m, ans[++cnt] = n-1, ans[++cnt] = m, ans[++cnt] = n, ans[++cnt] = m-1;
			num[n][m-1] ^= 1, num[n-1][m] ^= 1;
		}
		if (n & 1) {
			for (int i = 1; i <= m/2*2; i++)
				if (num[n][i]) {
					cout, ans[++cnt] = n, ans[++cnt] = i, ans[++cnt] = n-1, ans[++cnt] = i;
					if (i == m/2*2) cout, ans[++cnt] = n-1, ans[++cnt] = i-1, num[n-1][i-1] ^= 1;
					else cout, ans[++cnt] = n-1, ans[++cnt] = i+1, num[n-1][i+1] ^= 1;
					num[n-1][i] ^= 1;
				}
		}
		if (m & 1) {
			for (int i = 1; i <= n/2*2; i++)
				if (num[i][m]) {
					cout, ans[++cnt] = i, ans[++cnt] = m, ans[++cnt] = i, ans[++cnt] = m-1;
					if (i == n/2*2) cout, ans[++cnt] = i-1, ans[++cnt] = m-1, num[i-1][m-1] ^= 1;
					else cout, ans[++cnt] = i+1, ans[++cnt] = m-1, num[i+1][m-1] ^= 1;
					num[i][m-1] ^= 1;
				}
		}
		for (int i = 1; i <= n/2*2; i += 2)
			for (int j = 1; j <= m/2*2; j += 2)
				solve(i, j);
		cout << cnt/6 << endl;
		for (int i = 1; i <= cnt; i++) {
			cout << ans[i];
			if (i % 6 == 0) cout << endl;
			else cout << ' ';
		}
		cout << endl;
	}
}