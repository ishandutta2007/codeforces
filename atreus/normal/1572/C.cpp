#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e3 + 10;

vector<int> occ[maxn];
int dp[maxn][maxn], a[maxn];

void solve() {
	int n;
	cin >> n;
	int ptr = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[++ptr];
		if (ptr > 1 and a[ptr] == a[ptr - 1])
			ptr--;
	}
	n = ptr;
	for (int i = 1; i <= n; i++)
		occ[a[i]].push_back(i);
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (len == 1) {
				dp[l][r] = 0;
				continue;
			}
			
//			cout << l << " " << r << " -> " << dp[l][r] << endl;
			dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
			if (a[l] == a[r])
				dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]) + 1;
			
//			cout << l << " " << r << " -> " << dp[l][r] << endl;
			for (auto m : occ[a[l]])
				if (l < m and m < r)
					dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r]);
			for (auto m : occ[a[r]])
				if (l < m and m < r)
					dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r]);
//			cout << l << " " << r << " -> " << dp[l][r] << endl;
		}
	}
	cout << n - 1 - dp[1][n] << '\n';
	for (int i = 1; i <= n; i++)
		occ[a[i]].clear();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}