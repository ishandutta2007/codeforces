#include<bits/stdc++.h>
using namespace std;

long long T , N , A[50003] , dp[50003][5];

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		int x; cin >> x; for(int i = 1 ; i <= N ; ++i) A[i] -= x;
		for(int i = 1 ; i <= N ; ++i) A[i] += A[i - 1];
		memset(dp , -0x3f , sizeof(dp)); dp[0][0] = 0;
		for(int i = 1 ; i <= N + 1 ; ++i){
			long long mx = 0; for(int j = 0 ; j < 5 ; ++j) mx = max(mx , dp[i - 1][j]);
			dp[i][0] = mx; dp[i][1] = dp[i - 1][0] + 1;
			for(int j = 1 ; j <= 4 ; ++j)
				if(j < i && A[i] - A[i - j - 1] >= 0)
					dp[i][min(4 , j + 1)] = max(dp[i][min(4 , j + 1)] , dp[i - 1][j] + 1);
				else break;
		}
		cout << dp[N + 1][0] << endl;
	}
	return 0;
}