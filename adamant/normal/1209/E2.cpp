#include<bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x),end(x)

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n][m], at[m][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			at[j][i] = a[i][j];
		}
	}
	vector<pair<int, int>> cols;
	for(int i = 0; i < m; i++) {
		cols.emplace_back(*max_element(at[i], at[i] + n), i);
	}
	sort(all(cols), greater<pair<int, int>>());
	m = min(n, m);
	int p[m];
	for(int i = 0; i < m; i++) {
		p[i] = cols[i].second;
	}
	int sz = 1 << n;
	int dp[m + 1][sz];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < m; i++) {
		for(int z = 0; z < n; z++) {
			int ndp[n + 1][sz];
			memset(ndp, 0, sizeof(ndp));
			for(int mask = 0; mask < sz; mask++) {
				ndp[0][mask] = dp[i][mask];
			}
			int col = z;
			for(int j = 0; j < n; j++) {
				for(int mask = 0; mask < sz; mask++) {
					if((mask >> j) & 1) {
						int nmask = mask ^ (1 << j);
						ndp[j + 1][nmask] = max(ndp[j][nmask], ndp[j][mask] + at[p[i]][col]);
						ndp[j + 1][mask] = ndp[j][mask];
					}
				}
				col++;
				if(col == n) {
				    col = 0;
				}
			}
			for(int mask = 0; mask < sz; mask++) {
				dp[i + 1][mask] = max(dp[i + 1][mask], ndp[n][mask]);
				assert(dp[i + 1][mask] >= dp[i][mask]);
			}
		}
	}
	cout << dp[m][0] << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
		solve();
	}
}