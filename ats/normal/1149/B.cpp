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
int MOD = 1000000007;
int X[252][252][252];
void amin(int &a, int &b) {
	a = min(a, b);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;
	vector<vector<int> > ne(N + 2, vector<int>(26, N + 1));


	for (int i = N - 1; i >= 0; i--) {
		ne[i] = ne[i + 1];
		ne[i][S[i] - 'a'] = i + 1;
	}

	vector<int> A(N);
	int res = 0;
	int len[3];
	len[0] = len[1] = len[2] = 0;
	char t;
	int col;
	vector<vector<int> > Z(3);
	for (int i = 0; i < Q; i++) {
		cin >> t;
		if (t == '+') {
			cin >> col >> t;
			col--;
			len[col]++;
			int tt = t - 'a';
			Z[col].push_back(tt);
			if (col == 0) {
				for (int i = 0; i <= len[1]; i++) {
					for (int j = 0; j <= len[2]; j++) {
						X[len[0]][i][j] = ne[X[len[0] - 1][i][j]][tt];
						if (i > 0) {
							amin(X[len[0]][i][j], ne[X[len[0]][i - 1][j]][Z[1][i - 1]]);
						}
						if (j > 0) {
							amin(X[len[0]][i][j], ne[X[len[0]][i][j - 1]][Z[2][j - 1]]);
						}
					}
				}
			}
			else if (col == 1) {
				for (int i = 0; i <= len[0]; i++) {
					for (int j = 0; j <= len[2]; j++) {
						X[i][len[1]][j] = ne[X[i][len[1] - 1][j]][tt];
						if (i > 0) {
							amin(X[i][len[1]][j], ne[X[i - 1][len[1]][j]][Z[0][i - 1]]);
						}
						if (j > 0) {
							amin(X[i][len[1]][j], ne[X[i][len[1]][j - 1]][Z[2][j - 1]]);
						}
					}
				}
			}
			else if (col == 2) {
				for (int i = 0; i <= len[0]; i++) {
					for (int j = 0; j <= len[1]; j++) {
						X[i][j][len[2]] = ne[X[i][j][len[2] - 1]][tt];
						if (i > 0) {
							amin(X[i][j][len[2]], ne[X[i - 1][j][len[2]]][Z[0][i - 1]]);
						}
						if (j > 0) {
							amin(X[i][j][len[2]], ne[X[i][j - 1][len[2]]][Z[1][j - 1]]);
						}
					}
				}
			}

		}
		else {
			cin >> col; col--;
			len[col]--;
			Z[col].pop_back();
		}
		if (X[len[0]][len[1]][len[2]] <= N) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


}