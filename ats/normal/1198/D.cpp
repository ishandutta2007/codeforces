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
vector<string> A;
vector<vector<int> > X;
int dp[51][51][51][51];
int solve(int L, int R, int U, int D) {
	if (L == R || U == D)return 0;
	if (dp[L][R][U][D] == -1) {
		int w = R - L;
		int h = D - U;
		int res;
		if (w < h) {
			res = h;
			for (int i = U; i < D; i++) {
				
				if (X[R][i + 1] - X[L][i + 1] - X[R][i] + X[L][i] == 0) {
					//cerr << i << " " << L << " " << R << endl;
					res = min(res, solve(L, R, U, i) + solve(L, R, i + 1, D));
				}
			}
		}
		else {
			res = w;
			for (int i = L; i < R; i++) {
			//cerr << X[i + 1][D] - X[i + 1][U] - X[i][D] + X[i][U] << endl;
				if (X[i + 1][D] - X[i + 1][U] - X[i][D] + X[i][U] == 0) {
					res = min(res, solve(L, i, U, D) + solve(i + 1, R, U, D));
				}
			}
		}
		dp[L][R][U][D] = res;
	}
	return dp[L][R][U][D];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	A.resize(N);
	X.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		for (int j = 0; j < N; j++) {
			if (A[i][j] == '#') {
				X[i + 1][j + 1] = 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			X[i][j] += X[i - 1][j] + X[i][j - 1] - X[i - 1][j - 1];
		}
	}
	//cerr << X[N][N] << endl;
	for (int i1 = 0; i1 <= 50; i1++) {
		for (int i2 = 0; i2 <= 50; i2++) {
			for (int i3 = 0; i3 <= 50; i3++) {
				for (int i4 = 0; i4 <= 50; i4++) {
					dp[i1][i2][i3][i4] = -1;
				}
			}
		}
	}
	cout << solve(0, N, 0, N) << endl;

}