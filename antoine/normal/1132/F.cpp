#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 500 + 9;

int n;
string s;
int dp[MxN + 9][MxN + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;

	for (int diff = 0; diff < n; ++diff)
		for (int i = 0; i + diff < n; ++i) {
			const int j = i + diff;
			int &res = dp[i][j];
			if (i == j)
				res = 1;
			else {
				res = (s[i] != s[i + 1]) + dp[i + 1][j];
				for (int k = i + 2; k <= j; ++k)
					if (s[i] == s[k])
						res = min(res, dp[i + 1][k - 1] + dp[k][j]);
			}
		}

	cout << dp[0][n - 1];
	return 0;
}