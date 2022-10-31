#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;

int A[251][501][501];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	int M;
	int Q;
	cin >> N >> M >> Q;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	vector<vector<int> > X[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			X[i][j].resize(N + 1, vector<int>(M + 1, 0));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (S[i][j] == 'R')
				X[0][0][i + 1][j + 1] = 1;
			else if (S[i][j] == 'Y')
				X[1][0][i + 1][j + 1] = 1;
			else if (S[i][j] == 'G')
				X[0][1][i + 1][j + 1] = 1;
			else if (S[i][j] == 'B')
				X[1][1][i + 1][j + 1] = 1;
			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					X[a][b][i + 1][j + 1] +=
						+X[a][b][i + 1][j] + X[a][b][i][j + 1] - X[a][b][i][j];
				}
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			for (int k = 1;; k++) {
				if (i - k < 0 || j - k < 0 || i + k > N || j + k > M) {
					break;
				}
				if (X[0][0][i][j] - X[0][0][i][j - k] - X[0][0][i - k][j] + X[0][0][i - k][j - k] != k * k) {
					break;
				}
				if (X[1][0][i + k][j] - X[1][0][i][j] - X[1][0][i + k][j - k] + X[1][0][i][j - k] != k * k) {
					break;
				}
				if (X[0][1][i][j + k] - X[0][1][i][j] - X[0][1][i - k][j + k] + X[0][1][i - k][j] != k * k) {
					break;
				}
				if (X[1][1][i + k][j + k] - X[1][1][i + k][j] - X[1][1][i][j + k] + X[1][1][i][j] != k * k) {
					break;
				}
				//cerr << k << " " << i << " " << j << endl;
				A[k][i + 1][j + 1] = 1;
			}
		}
	}
	for (int i = 0; i <= 250; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				A[i][j][k] += A[i][j - 1][k] + A[i][j][k - 1] - A[i][j - 1][k - 1];
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		X1--;
		Y1--;
		int ok = 0;
		int ng = 251;
		while (ng - ok > 1) {
			int m = (ok + ng) / 2;
			int x1 = X1 + m;
			int y1 = Y1 + m;
			int x2 = X2 - m + 1;
			int y2 = Y2 - m + 1;
			if (x1 >= x2 || y1 >= y2) {
				ng = m;
			} else {
				if (A[m][x2][y2] - A[m][x2][y1] - A[m][x1][y2] + A[m][x1][y1] > 0) {
					ok = m;
				} else {
					ng = m;
				}
			}
		}
		cout << 4 * ok * ok << "\n";
	}
	return 0;
}