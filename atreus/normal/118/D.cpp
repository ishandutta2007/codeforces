#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

const int MOD = 1e8;
int dp[300][300][3];

int main(){
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	for (int i = 1; i <= k1; i++)
		dp[i][0][1] = 1;
	for (int i = 1; i <= k2; i++)
		dp[0][i][0] = 1;
	for (int i = 1; i <= n1; i++){
		for (int j = 1; j <= n2; j++){
			for (int k = 1; k <= min(k1, i); k++)
				dp[i][j][1] += dp[i - k][j][0] % MOD;
			for (int k = 1; k <= min(k2, j); k++)
				dp[i][j][0] += dp[i][j - k][1] % MOD;

		}
	}
	cout << (dp[n1][n2][1] + dp[n1][n2][0]) % MOD << endl;
}