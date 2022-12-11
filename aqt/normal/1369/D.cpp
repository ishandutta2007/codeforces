
// Problem : D. TediousLee
// Contest : Codeforces - Codeforces Round #652 (Div. 2)
// URL : https://codeforces.com/contest/1369/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long dp[2000005];
long double cmp[2000005];
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	const int M = 2e6;
	dp[3] = 4;
	for(int i = 4; i<=M; i++){
		//dp[i] = max(4*dp[i-3]+dp[i-2]+4+dp[i-4]*4, 2*dp[i-2]+dp[i-1]);
		if(i%3 == 0){
			dp[i] = (4*dp[i-3]+dp[i-2]+4+dp[i-4]*4)%MOD;
		}
		else{
			dp[i] = (2*dp[i-2]+dp[i-1])%MOD;
		}
		//cout << (4*dp[i-3]+dp[i-2]+4+dp[i-4]*4 > (2*dp[i-2]+dp[i-1])) << "\n";
	}
	while(T--){
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}