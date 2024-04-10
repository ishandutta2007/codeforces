#include<bits/stdc++.h>
using namespace std;

#define int long long
int dp[10003] , tmp[10003] , N , A[103] , B[103] , T;

signed main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		for(int i = 1 ; i <= N ; ++i) cin >> B[i];
		memset(dp , 0x3f , sizeof(dp)); dp[0] = 0; int tot = 0;
		for(int i = 1 ; i <= N ; ++i){
			memset(tmp , 0x3f , sizeof(tmp));
			for(int j = 0 ; j <= (i - 1) * 100 ; ++j){
				int dlt = tot - j; if(dp[j] == tmp[10001]) continue;
				tmp[j + A[i]] = min(tmp[j + A[i]] , dp[j] + A[i] * A[i] * (N - 1) + B[i] * B[i] * (N - 1) + 2 * A[i] * j + 2 * B[i] * dlt);
				tmp[j + B[i]] = min(tmp[j + B[i]] , dp[j] + A[i] * A[i] * (N - 1) + B[i] * B[i] * (N - 1) + 2 * B[i] * j + 2 * A[i] * dlt);
			}
			memcpy(dp , tmp , sizeof(tmp)); tot += A[i] + B[i];
		}
		int mn = tmp[10001];
		for(int i = 0 ; i <= 1e4 ; ++i) mn = min(mn , dp[i]);
		cout << mn << endl;
	}
	return 0;
}