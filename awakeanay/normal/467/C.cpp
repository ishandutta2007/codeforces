#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <string>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    long long arr[n+1];
    arr[0] = 0;
    for (int i = 1; i < n+1; i++) {
		cin >> arr[i];
		arr[i] += arr[i-1];
    }

    //for (int i = 0; i < n+1; i++) cout << arr[i] << " ";
    //cout << endl;

    long long dp[n+1][k+1];

    for (int i = 0; i < n+1; i++) dp[i][0] = 0;
    for(int i = 0; i < n+1; i++) dp[0][i] = 0;
    for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < k+1; j++) {
		    dp[i][j] = 0;
            if ((i == 0) || (i < j * m)) dp[i][j] = 0;
            else {
                dp[i][j] = dp[i-1][j];
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i-m][j-1] + arr[i] - arr[i-m]);
            }
		}
    }

    /*
    for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < k+1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
    }
    */

    cout << dp[n][k] << endl;

	return 0;
}