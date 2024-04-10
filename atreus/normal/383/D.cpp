#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int a[1000 + 500];
int dp[1000 + 500][20000 + 500];

int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1][10000 - a[1]] = 1;
    dp[1][10000 + a[1]] = 1;
	for (int i = 1; i < n; i++){
        for (int j = 0; j <= 20000; j++){
            if (dp[i][j]){
				dp[i + 1][j + a[i + 1]] += dp[i][j];
				dp[i + 1][j - a[i + 1]] += dp[i][j];
                
				dp[i + 1][j + a[i + 1]] %= MOD;
                dp[i + 1][j - a[i + 1]] %= MOD;
//                cout << i << " " << j << " " << dp[i][j] << " " << endl;
            }
        }
		dp[i + 1][10000 + a[i + 1]] ++;
		dp[i + 1][10000 - a[i + 1]] ++; 
    }
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans += dp[i][10000];
		ans %= MOD;
	}
	cout << ans << endl;
}