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
vector<int> X;
void add(int &a, const int &b) {
	a += b;
	if (a >= MOD)a -= MOD;
}
int dp[1000][1000];
int solve(int l, int r) {
	if (l >= r)return 1;
	if (dp[l][r] == -1) {
		int mn = 10000000;
		int p = -1;
		for (int i = l; i <= r; i++) {
			if (mn > X[i]) {
				mn = X[i];
				p = i;
			}
		}
		int L = 0;
		for (int i = l; i <= p; i++) {
			L += (solve(l, i - 1) * solve(i, p - 1)) % MOD;
		}
		L %= MOD;
		int R = 0;
		for (int i = p; i <= r; i++) {
			R += (solve(p + 1, i) * solve(i + 1, r)) % MOD;
		}
		R %= MOD;
		dp[l][r] = (L * R) % MOD;
		//cerr << l << " " << r << " "<<dp[l][r] << endl;
	}
	return dp[l][r];
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; i++) {
		cin >> A[i]; A[i]--;
	}
	X = A;
	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j < X.size(); j++) {
			dp[i][j] = -1;
		}
	}
	cout << solve(0, (int)X.size() - 1) << endl;
}