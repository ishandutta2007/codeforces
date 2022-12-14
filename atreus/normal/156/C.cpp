/**
 *    author:  Atreus
 *    created: 06.02.2019 09:53
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;
int dp[105][3000];

int main(){
	ios_base::sync_with_stdio(false);
	int n = 100;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 26 * i; j++){
			for (int k = 1; k <= min(26, j); k++){
				dp[i][j] = dp[i][j] + dp[i - 1][j - k];
				if (dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
		}
	}
	int tc;
	cin >> tc;
	while (tc --){
		string s;
		cin >> s;
		int m = s.size();
		int sum = 0;
		for (int i = 0; i < m; i++)
			sum += int(s[i] - 'a') + 1;
		cout << (dp[m][sum] - 1 + mod) % mod<< endl;
	}
}