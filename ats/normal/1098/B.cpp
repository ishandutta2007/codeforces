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
int solve(int N, int M, vector<string> &A, vector<string> &res) {
	vector<string> B(N, string(M, 'A'));

	string X = "AGCT";
	sort(X.begin(), X.end());

	int mn = N * M * 2;
	string T1;
	string T2;
	do {
		//cerr << X << endl;
		T1 = string(M, 'A');
		T2 = string(M, 'A');
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int cnt1 = 0;
			for (int j = 0; j < M; j++) {
				T1[j] = X[2 * (i % 2) + j % 2];
				if (A[i][j] != T1[j]) cnt1++;
			}
			int cnt2 = 0;
			for (int j = 0; j < M; j++) {
				T2[j] = X[2 * (i % 2) + (1 - (j % 2))];
				if (A[i][j] != T2[j]) cnt2++;
			}
			if (cnt1 < cnt2) {
				B[i] = T1;
				ans += cnt1;
			}
			else {
				B[i] = T2;
				ans += cnt2;
			}
		}
		/*for (int i = 0; i < N; i++) {
			cerr << B[i] << endl;
		}*/
		if (mn > ans) {
			mn = ans;
			res = B;
		}
	} while (next_permutation(X.begin(), X.end()));

	return mn;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	vector<string> B(M, string(N, 'A'));
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<string> res1;
	vector<string> res2;
	vector<string> res3(N, string(M, 'A'));
	vector<string> res;
	int ans1 = solve(N, M, A, res1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			B[j][i] = A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			B[j][i] = A[i][j];
		}
	}
	int ans2 = solve(M, N, B, res2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			res3[i][j] = res2[j][i];
		}
	}
//	cerr << min(ans1, ans2) << endl;

	if (ans1 < ans2) res = res1;
	else res = res3;
	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
}