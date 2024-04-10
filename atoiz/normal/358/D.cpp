#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX = 3010;
int joy[MAX][3], dp[MAX][2];
// joy[i][noFull], dp[i][rFull]

signed main()
{
	ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
			cin >> joy[i][j];
        }
    }

    if (n == 1) {
		cout << joy[0][0] << endl;
		return 0;
    }

    dp[0][0] = joy[0][0];
    dp[0][1] = joy[0][1];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0] + joy[i][1], dp[i-1][1] + joy[i][0]);
        dp[i][1] = max(dp[i-1][0] + joy[i][2], dp[i-1][1] + joy[i][1]);
//        cerr << i << ": " << dp[i][0] << ' ' << dp[i][1] << endl;
    }

//    cerr << dp[0][1] << ' ' << dp[1][1] << ' ' << dp[2][1] << ' ' << dp[3][0] << endl;

    cout << dp[n-1][0];
}