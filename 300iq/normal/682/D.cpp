#include <bits/stdc++.h>

using namespace std;	

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define pb push_back
#define endl '\n'

const int MAXN = 1007, MAXK = 17;

int dp[MAXN][MAXN][MAXK][2];

int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("input.txt");
	//ofstream cout("out.txt");
	int n, m, k;
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	s = "0" + s;
	t = "0" + t;
	for (int p = 1; p <= k; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
			    dp[i][j][p][1] = 0;
				int a = max(dp[i - 1][j][p][0], dp[i - 1][j][p][1]), b = max(dp[i][j - 1][p][0], dp[i][j - 1][p][1]);
				dp[i][j][p][0] = max(a, b);
				if (s[i] == t[j]) {
					dp[i][j][p][0] = max(dp[i][j][p][0], 1 + max(dp[i - 1][j - 1][p - 1][0], dp[i - 1][j - 1][p][1]));
					dp[i][j][p][1] = max(dp[i][j][p][1], 1 + max(max(dp[i - 1][j - 1][p - 1][0], dp[i - 1][j - 1][p - 1][1]), dp[i - 1][j - 1][p][1]));
				}
			}
		}
	}
	cout << max(dp[n][m][k][0], dp[n][m][k][1]) << endl;
}