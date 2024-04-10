#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 998244353;
int dp[20][1024][2];
int sum[20][1024][2];
int add(int &a, int b) {
	a += b;
	if (a >= MOD)a -= MOD;
}
int pc(int i) {
	int r = 0;
	while (i > 0) {
		r += (i & 1);
		i >>= 1;
	}
	return r;
}

int solve(int X, int k) {
	if (X == 0)return 0;
	string S;
	while (X > 0) {
		S.push_back((X % 10) + '0');
		X /= 10;
	}
	reverse(S.begin(), S.end());
	int N = S.size();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 1024; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = 0;
				sum[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	int p10[20][10];
	for (int j = 0; j < 10; j++) {
		p10[N][j] = j;
		for (int i = N - 1; i >= 1; i--) {
			p10[i][j] = (p10[i + 1][j] * 10) % MOD;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				if (k == 0 && j == 0) {
					add(dp[i][0][1], dp[i - 1][k][1]); 
					add(sum[i][0][1], sum[i - 1][k][1]);
					add(sum[i][0][1], (dp[i - 1][k][1] * p10[i][j]) % MOD);
				}
				else {
					add(dp[i][k | (1 << j)][1], dp[i - 1][k][1]);
					add(sum[i][k | (1 << j)][1], sum[i - 1][k][1]);
					add(sum[i][k | (1 << j)][1], (dp[i - 1][k][1] * p10[i][j]) % MOD);
				}
			}
		}
		for (int j = 0; j < S[i - 1] - '0'; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				if (k == 0 && j == 0) {
					add(dp[i][0][1], dp[i - 1][k][0]);
					add(sum[i][0][1], sum[i - 1][k][0]);
					add(sum[i][0][1], (dp[i - 1][k][0] * p10[i][j]) % MOD);
				}
				else {
					add(dp[i][k | (1 << j)][1], dp[i - 1][k][0]);
					add(sum[i][k | (1 << j)][1], sum[i - 1][k][0]);
					add(sum[i][k | (1 << j)][1], (dp[i - 1][k][0] * p10[i][j]) % MOD);
				}
			}
		}
		{
			int j = S[i - 1] - '0';
			for (int k = 0; k < (1 << 10); k++) {
				if (k == 0 && j == 0) {
					add(dp[i][0][0], dp[i - 1][k][0]);
					add(sum[i][0][0], sum[i - 1][k][0]);
					add(sum[i][0][0], (dp[i - 1][k][0] * p10[i][j]) % MOD);
				}
				else {
					
					add(dp[i][k | (1 << j)][0], dp[i - 1][k][0]);
					add(sum[i][k | (1 << j)][0], sum[i - 1][k][0]);
					add(sum[i][k | (1 << j)][0], (dp[i - 1][k][0] * p10[i][j]) % MOD);
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < (1 << 10); i++) {
		if (pc(i) <= k) {
			add(ret, sum[N][i][0]);
			add(ret, sum[N][i][1]);
		}
	}
	return ret;

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int L, R;
	int K;
	cin >> L >> R >> K;
	int res = solve(R, K) - solve(L - 1, K);
	res = (res + MOD) % MOD;
	cout << res << endl;
}