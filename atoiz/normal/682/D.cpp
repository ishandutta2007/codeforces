#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);

	int m, n, k;
	cin >> m >> n >> k;
	string a, b;
	cin >> a >> b;

	// Initialize dp
	int dp[2][m][n][k+1];
	for (int i = 0; i < m; ++i) { // Initialize dp[b][i][j][0]
		for (int j = 0; j < n; ++j) {
			dp[0][i][j][0] = 0;
			dp[1][i][j][0] = -1;
		}
	}

	dp[0][0][0][1] = -1;
	dp[1][0][0][1] = (a[0] == b[0] ? 1 : -1);
	for (int c = 2; c <= k; ++c) dp[0][0][0][c] = dp[1][0][0][c] = 0;

	for (int i = 1; i < m; ++i) { // Initialize dp[b][i][0][c];
		dp[0][i][0][1] = max(dp[0][i-1][0][1], dp[1][i-1][0][1]);
		dp[1][i][0][1] = (a[i] == b[0] ? 1 : -1);
		for (int c = 2; c <= k; ++c)
			dp[0][i][0][c] = dp[1][i][0][c] = -1;
	}

	for (int j = 1; j < n; ++j) { // Initialize dp[b][0][j][c];
		dp[0][0][j][1] = max(dp[0][0][j-1][1], dp[1][0][j-1][1]);
		dp[1][0][j][1] = (a[0] == b[j] ? 1 : -1);
		for (int c = 2; c <= k; ++c) {
			dp[0][0][j][c] = dp[1][0][j][c] = -1;
		}
	}

	// Calculate dp[b][i][j][c];

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			for (int c = 1; c <= k; ++c) {
				dp[0][i][j][c] = max({dp[0][i-1][j][c], dp[1][i-1][j][c],
									  dp[0][i][j-1][c], dp[1][i][j-1][c]});

				if (a[i] != b[j]) dp[1][i][j][c] = -1;
				else {
					dp[1][i][j][c] = max({dp[0][i-1][j-1][c-1] + 1,
										  dp[1][i-1][j-1][c-1] + 1,
										  dp[1][i-1][j-1][c]   + 1});
					if (dp[1][i][j][c] == 0) dp[1][i][j][c] = -1;
				}


				/*
				if (i < 3 && j < 9 && j > 5) {
					cout << 0 << ' ' << i << ' ' << j << ' ' << c << ": " << dp[0][i][j][c] << endl;
					cout << 1 << ' ' << i << ' ' << j << ' ' << c << ": " << dp[1][i][j][c] << endl;
				}
				*/
				// if (i == 5 && j == 3 && c == 2) cout << dp[1][1][0][1] << endl;

			}
		}
	}

	int maxRes = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			/*
			cout << 0 << ' ' << i << ' ' << j << ' ' << k << ": " << dp[0][i][j][k] << endl;
			cout << 1 << ' ' << i << ' ' << j << ' ' << k << ": " << dp[1][i][j][k] << endl;
			*/
			maxRes = max({maxRes, dp[0][i][j][k], dp[1][i][j][k]});
		}
	}

	cout << maxRes << endl;
}