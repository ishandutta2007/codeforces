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
vector<vector<int> > dp;
string S[3];
int N, K;
int solve(int x, int y) {
	if (y >= N)return 1;
	if (S[x][y] != '.')return 0;
	if (dp[x][y] == -1) {

		dp[x][y] = 0;
		for (int i = -1; i <= 1; i++) {
			if (x + i >= 0 && x + i <= 2) {
				bool ok = true;
				for (int j = 0; j < 3; j++) {
					if (y + j >= N)break;
					if (S[x + i][y + j] != '.') {
						ok = false;
					}
				}
				if (ok) {
					dp[x][y] |= solve(x + i, y + 3);
				}
			}
		}
	}
	return dp[x][y];

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		
		for (int i = 0; i < 3; i++) {
			cin >> S[i];
		}
		dp.clear();
		dp.resize(3, vector<int>(N + 5, -1));
		for (int i = 0; i < 3; i++) {
			if (S[i][0] == 's') {
				if (solve(i, 1) == 1) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
				break;
			}
		}
	}
	
}