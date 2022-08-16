#include <bits/stdc++.h>

using namespace std;

int n, m, a[105], b[105], dp[105][105];

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		cin >> m;
		for(int i = 1; i <= m; i++) cin >> b[i];
		int ans = 0;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				if(i == 0 && j == 0) dp[i][j] = 0;
				else if(i == 0) dp[i][j] = dp[i][j - 1] + b[j];
				else if(j == 0) dp[i][j] = dp[i - 1][j] + a[i];
				else dp[i][j] = max(dp[i - 1][j] + a[i], dp[i][j - 1] + b[j]);
				ans = max(ans, dp[i][j]);
			}
		}
		cout << ans << "\n";
	}
}