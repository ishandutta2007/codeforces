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
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;


	vector<vector<int> > R(2, vector<int>(N, N));
	vector<vector<int> > L(2, vector<int>(N, -1));

	for (int i = 0; i < N; i++) {
		int t = S[i] - '0';
		L[t][i] = i;
		if (i > 0)L[t ^ 1][i] = L[t ^ 1][i - 1];
	}

	for (int i = N - 1; i >= 0; i--) {
		int t = S[i] - '0';
		R[t][i] = i;
		if (i < N - 1)R[t ^ 1][i] = R[t ^ 1][i + 1];
	}
	
	if (L[0][N - 1] - R[0][0] < K || L[1][N - 1] - R[1][0] < K) {
		cout << "tokitsukaze" << endl;
		return 0;
	}

	for (int t = 0; t < 2; t++) {
		int l = R[t][0];
		int r = L[t][N - 1];
		for (int i = 0; i + K < N; i++) {
			int nl = l;
			int nr = r;
			if (i <= nl && nl < i + K) {
				if (i + K == N)nl = N;
				else nl = R[t][i + K];
			}
			if (i <= nr && nr < i + K) {
				if (i == 0)nr = -1;
				else nr = L[t][i - 1];
			}
			if (nr - nl >= K) {
				cout << "once again" << endl;
				return 0;
			}
		}
		
	}

	cout << "quailty" << endl;
	return 0;
}