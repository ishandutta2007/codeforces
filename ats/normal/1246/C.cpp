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
const int MOD = 1000000007;
void add(int &a, const int &b) {
	a += b;
	if (a >= MOD)a -= MOD;
}
void sub(int &a, const int &b) {
	a -= b;
	if (a < 0)a += MOD;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	if (N == M && N == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<vector<int> > dp1(N, vector<int>(M, 0));
	vector<vector<int> > dp2(N, vector<int>(M, 0));
	vector<vector<int> > ad1(N + 1, vector<int>(M + 1, 0));
	vector<vector<int> > ad2(N + 1, vector<int>(M + 1, 0));
	vector<vector<int> > cntR(N, vector<int>(M, 0));
	vector<vector<int> > cntD(N, vector<int>(M, 0));
	dp1[0][0] = 1;
	dp2[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = M - 2; j >= 0; j--) {
			cntR[i][j] = cntR[i][j + 1] + ((A[i][j + 1] == 'R') ? 1 : 0);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = N - 2; j >= 0; j--) {
			cntD[j][i] = cntD[j + 1][i] + ((A[j + 1][i] == 'R') ? 1 : 0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i > 0)add(ad1[i][j], ad1[i - 1][j]);
			if (j > 0)add(ad2[i][j], ad2[i][j - 1]);

			add(dp1[i][j], ad1[i][j]);
			add(dp2[i][j], ad2[i][j]);

			//if (i == 0 && j == 0) {
				int R = M - cntR[i][j];
				add(ad2[i][j + 1], dp1[i][j]);
				sub(ad2[i][R], dp1[i][j]);

				int D = N - cntD[i][j];
				add(ad1[i + 1][j], dp2[i][j]);
				sub(ad1[D][j], dp2[i][j]);
			//}
		}
	}
	
	add(res, dp1[N - 1][M - 1]);
	add(res, dp2[N - 1][M - 1]);

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp1[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp2[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << res << endl;
}