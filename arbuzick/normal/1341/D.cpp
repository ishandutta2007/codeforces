#include<bits/stdc++.h>
using namespace std;
vector<string> c = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
int c1(string s, int n) {
	int ans = 0;
	for (int i = 0; i < 7; ++i) {
		if (s[i] == '1' && c[n][i] == '0')
			return -1;
		if (s[i] == '0' && c[n][i] == '1')
			ans += 1;
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<string> t(n);
	for (int i = 0; i < n; ++i) 
		cin >> t[i];
	vector<vector<bool>> dp(n+1, vector<bool>(k + 1));
	dp[n][0] = true;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 10; ++j) {
			int a = c1(t[i], j);
			if(a != -1)
				for (int x = a; x <= k; ++x)
					dp[i][x] = dp[i][x] || dp[i + 1][x - a];
		}
	}
	vector<int> ans(n);
	int x = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 9; j >= 0; --j) {
			int a = c1(t[i], j);
			if (k - a - x >= 0&&a != -1) {
				if (dp[i + 1][k - a - x]) {
					x += a;
					ans[i] = j;
					break;
				}
			}
			if (j == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i];
	return 0;
}