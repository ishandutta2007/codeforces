#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

typedef vector<vector<int>> matrix;

matrix mul(matrix a, matrix b) {
	matrix c(a.size(), vector<int>(b[0].size(), 0));
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b[0].size(); j++)
			for(int k = 0; k < b.size(); k++)
				c[i][j] = (c[i][j] + ll(a[i][k]) * b[k][j]) % mod;
	return c;
}

matrix pw(matrix a, int b) {
	assert(b);
	if(b == 1) return a;
	if(b & 1) return mul(pw(a, b - 1), a);
	a = pw(a, b / 2);
	return mul(a, a);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> ko(100, 0);
	for(int i = 0; i < n; i++) {
		int d; cin >> d; ko[d - 1]++;
	}
	matrix M(101, vector<int>(101, 0));
	for(int i = 0; i < 99; i++) M[i][i + 1] = 1;
	for(int i = 0; i < 100; i++) M[99][99 - i] = M[100][99 - i] = ko[i];
	M[100][100] = 1;
	vector<int> dp(100, 0);
	dp[0] = 1;
	for(int i = 1; i < 100; i++)
		for(int j = 0; j < i; j++)
			dp[i] = (dp[i] + ll(dp[i - j - 1]) * ko[j]) % mod;
	if(x < 100) {
		int ans = 0;
		for(int i = 0; i <= x; i++) ans = (ans + dp[i]) % mod;
		return cout << ans, 0;
	}
	matrix A(101, vector<int>(1, 0));
	for(int i = 0; i < 100; i++) A[i][0] = dp[i], A[100][0] = (A[100][0] + dp[i]) % mod;
	M = pw(M, x - 99);
	cout << mul(M, A)[100][0];
}