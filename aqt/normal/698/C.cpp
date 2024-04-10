
// Problem : C. LRU
// Contest : Codeforces - Codeforces Round #363 (Div. 1)
// URL : https://codeforces.com/contest/698/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long double arr[25];
long double dp[1<<20];
long double ans[25];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	dp[0] = 1;
	int cnt0 = 0;
	for(int i = 0; i<N; i++){
		cin >> arr[i];
		cnt0 += (arr[i] == 0.0);
	}
	if(N - cnt0 <= K){
		for(int i = 0; i<N; i++){
			cout << (arr[i] == 0.0 ? 0 : 1) << " ";
		}
		return 0;
	}
	for(int m = 1; m<1<<N; m++){
		if(__builtin_popcount(m) <= K){
			long double den = 0;
			for(int n = 0; n<N;n++){
				if(!(m>>n&1)){
					den += arr[n];
				}
			}
			for(int n = 0;n <N; n++){
				if(m>>n&1){
					dp[m] += dp[m^(1<<n)] * (arr[n])/(den + arr[n]);
				}
			}
		}
	}
	for(int m = 1; m<1<<N; m++){
		if(__builtin_popcount(m) == K){
			for(int n = 0; n<N; n++){
				if(m>>n&1){
					ans[n] += dp[m];
				}
			}
		}
	}
	for(int n = 0; n<N; n++){
		cout << setprecision(12) << " " << ans[n] << " ";
	}
}