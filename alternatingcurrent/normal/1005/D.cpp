#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;

string s;
int sum[200200];
int dp[100100];

signed main(){
	cin >> s;
	int n = s.size();
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + (s[i - 1] - '0');
	}
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		int j = i - 1;
		if(!((sum[i] - sum[j]) % 3)){
			dp[i] = dp[j] + 1;
			continue;
		}
		dp[i] = dp[j];
		while(((sum[i] - sum[j]) % 3) && j >= 0) j--;
		if(j == -1) continue;
		dp[i] = max(dp[i], dp[j] + 1);
	}
	cout << dp[n] << endl;
	return 0;
}