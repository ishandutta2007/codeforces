#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> > A(N, vector<int>(M));
	if (N == 1 && M == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (N == 1) {
		for (int i = 0; i < M; i++) {
			A[0][i] = i + 2;
		}
	} else if (M == 1) {
		for (int i = 0; i < N; i++) {
			A[i][0] = i + 2;
		}
	} else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				A[i][j] = (i + 1) * (1 + N + j);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j > 0) cout << " ";
			cout << A[i][j];
		}
		cout << endl;
	}
}