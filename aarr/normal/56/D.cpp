#include <iostream>
using namespace std;

const int N = 1005;

int dp[N][N];
int par[N][N];

int main() {
	string s;
	string t;
	cin >> s >> t;
//	fill(dp[0], dp[N] + N, N);
	dp[0][0] = 0;
	for (int i = 0; i <= s.size(); i++) {
		for (int j = 0; j <= t.size(); j++) {
		//	cout << i << " " << j << " " << dp[i][j] << endl;
			if (i + j > 0) {
				dp[i][j] = N;
			}
			if (i > 0) {
				dp[i][j] = dp[i - 1][j] + 1;
				par[i][j] = 1;
			}
			if (j > 0 && dp[i][j - 1] + 1 < dp[i][j]) {
				dp[i][j] = dp[i][j - 1] + 1;
				par[i][j] = 2;
			}
			if (i > 0 && j > 0 && dp[i - 1][j - 1] <= dp[i][j] && s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
				par[i][j] = 3;
			}
			if (i > 0 && j > 0 && dp[i - 1][j - 1] < dp[i][j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				par[i][j] = 4;
			}
		//	cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	cout << dp[s.size()][t.size()] << endl;
	int x = s.size(), y = t.size();
	while (x != 0 || y != 0) {
	//	cout << x << " " << y << endl;
		int q = par[x][y];
		if (q == 1) {
			cout << "DELETE " << x << endl;
			x--;
		}
		if (q == 2) {
			cout << "INSERT " << x + 1 << " " << t[y - 1] << endl;
			y--;
		}
		if (q >= 3) {
			if (q == 4) {
				cout << "REPLACE " << x << " " << t[y - 1] << endl;
			}
			x--;
			y--;
		}
	}
	return 0;
}