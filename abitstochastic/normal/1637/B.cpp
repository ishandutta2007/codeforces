#include<bits/stdc++.h>
using namespace std;

int A[103] , dp[103];

int main(){
	int T , N;
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
		int ans = 0;
		for(int i = 1 ; i <= N ; ++i){
			memset(dp , 0 , sizeof(dp));
			for(int j = i ; j <= N ; ++j){
				static int vis[103]; memset(vis , 0 , sizeof(vis)); int pos = 0;
				for(int k = j ; k >= i ; --k){
					vis[min(A[k] , 101)] = 1; while(vis[pos]) ++pos;
					dp[j] = max(dp[j] , dp[k - 1] + pos + 1);
				}
				ans += dp[j];
			}
		}
		cout << ans << endl;;
	}
	return 0;
}