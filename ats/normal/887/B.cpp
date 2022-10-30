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
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > A(N, vector<int>(6, 0));
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> A[i][j];
		}
	}
	vector<int> B(10000, 0);
	if (N == 3) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					B[100 * A[0][i] + 10 * A[1][j] + A[2][k]] = 1;
					B[100 * A[0][i] + 10 * A[2][j] + A[1][k]] = 1;
					B[100 * A[1][i] + 10 * A[2][j] + A[0][k]] = 1;
					B[100 * A[1][i] + 10 * A[0][j] + A[2][k]] = 1;
					B[100 * A[2][i] + 10 * A[1][j] + A[0][k]] = 1;
					B[100 * A[2][i] + 10 * A[0][j] + A[1][k]] = 1;
				}
				B[10 * A[0][i] + A[1][j]] = 1;
				B[10 * A[1][i] + A[0][j]] = 1;
				B[10 * A[2][i] + A[1][j]] = 1;
				B[10 * A[1][i] + A[2][j]] = 1;
				B[10 * A[0][i] + A[2][j]] = 1;
				B[10 * A[2][i] + A[0][j]] = 1;
			}
			B[A[0][i]] = 1;
			B[A[1][i]] = 1;
			B[A[2][i]] = 1;
		}
	}else if (N == 2) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
					B[10 * A[0][i] + A[1][j]] = 1;
					B[10 * A[1][i] + A[0][j]] = 1;
			}
			B[A[0][i]] = 1;
			B[A[1][i]] = 1;
		}
	}
	else {
		for (int i = 0; i < 6; i++) {
			B[A[0][i]] = 1;
		}
	}
	for (int i = 1; i < 10000; i++) {
		if (B[i] == 0) {
			res = i - 1;
			break;
		}
	}
	cout << res << endl;
}