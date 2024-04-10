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
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	int res = 0;
	for (int i = 0; i < H; i++) {
		cin >> S[i];
	}
	vector<vector<int> > C(H + 1, vector<int>(W + 1, 0));

	for (int i = H - 1; i >= 0; i--) {
		for (int j = W - 1; j >= 0; j--) {
			C[i][j] = C[i + 1][j] + C[i][j + 1] - C[i + 1][j + 1];
			if (S[i][j] == 'B') {
				if (C[i][j] != -1) {
					C[i][j] = -1;
					res++;
				}
			}else if (S[i][j] == 'W') {
				if (C[i][j] != 1) {
					C[i][j] = 1;
					res++;
				}
			}

		}
	}
	cout << res << endl;
}