#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int mul(int a, int b) {
	return a * b % mod;
}
int add(int a, int b) {
	return (a + b) % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int c[m];
	vector<int> rev[n];
	for(int i = 0; i < m; i++) {
		cin >> c[i];
		rev[c[i] - 1].push_back(i);
	}
	int dp[n + 1][n + 1][2];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++) {
		dp[i][i][0] = 1;
		dp[i][i][1] = 0;
	}
	for(int ln = 1; ln < n; ln++) {
		for(int i = 0; i + ln < n; i++) {
			int j = i + ln;
			int t = min_element(c + i, c + j + 1) - c;
			for(int k = i; k < j; k++) {
				dp[i][j][1] = add(dp[i][j][1], mul(dp[i][k][0], add(dp[k + 1][j][1], dp[k + 1][j][0])));
			}
			if(t == i) {
				dp[i][j][0] = add(dp[i + 1][j][1], dp[i + 1][j][0]);
			} else if(t == j) {
				dp[i][j][0] = add(dp[i][j - 1][1], dp[i][j - 1][0]);
			} else {
				dp[i][j][0] = mul(add(dp[i][t - 1][1], dp[i][t - 1][0]), 
								  add(dp[t + 1][j][1], dp[t + 1][j][0]));
			}
		}
	}
	cout << add(dp[0][n - 1][1], dp[0][n - 1][0]) << endl;
	return 0;
}