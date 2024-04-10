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
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	vector<vector<int> > A(N, vector<int>(M, 0));

	A[N - 1][M - 1] = 1;

	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (S[i][j] == '#')continue;
			if (i < N - 1) {
				if (A[i + 1][j] == 1)A[i][j] = 1;
			}
			if (j < M - 1) {
				if (A[i][j + 1] == 1)A[i][j] = 1;
			}
		}
	}
	if (A[0][0] == 0) {
		cout << 0 << endl;
		return 0;
	}
	int X = 0;
	int Y = 0;
	int res = 1;
	while (true) {
		if (X < N - 1 && A[X + 1][Y] == 1) {
			X++;
		}
		else if (Y < M - 1 && A[X][Y + 1] == 1) {
			Y++;
		}
		else {
			cerr << "ha?" << endl;
		}
		if (X == N - 1 && Y == M - 1) {
			break;
		}
		else {
			A[X][Y] = 0;
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cerr << A[i][j] << " ";
		}
		cerr << endl;
	}*/
	X = 0;
	Y = 0;
	while (true) {
		if (Y < M - 1 && A[X][Y + 1] == 1) {
			Y++;
		}
		else if (X < N - 1 && A[X + 1][Y] == 1) {
			X++;
		}
		else {
			break;
		}
		if (X == N - 1 && Y == M - 1) {
			res = 2;
			break;
		}
	}



	cout << res << endl;
}