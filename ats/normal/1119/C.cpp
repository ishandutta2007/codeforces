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
	int N, M;
	cin >> N >> M;
	vector<vector<int> > A(N, vector<int>(M));
	vector<vector<int> > B(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B[i][j];
		}
	}
	string res = "Yes";
	for (int i = 0; i < N; i++) {
		int c = 0;
		for (int j = 0; j < M; j++) {
			c += (A[i][j] ^ B[i][j]);
		}
		if (c % 2 != 0) {
			res = "No";
		}
	}

	for (int j = 0; j < M; j++) {
		int c = 0;
		for (int i = 0; i < N; i++) {
			c += (A[i][j] ^ B[i][j]);
		}
		if (c % 2 != 0) {
			res = "No";
		}
	}



	cout << res << endl;
}