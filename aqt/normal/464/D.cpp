
// Problem : D. World of Darkraft - 2
// Contest : Codeforces - Codeforces Round #265 (Div. 1)
// URL : https://codeforces.com/contest/464/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long double pr[2][1005];
long double dp[2][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pr[0][1] = 1;
	cin >> N >> K;
	for(int i = 0; i<N; i++){
		for(int k = 1; k<=1000; k++){
			long double f = 1.0/K/(k+1);
			pr[i&1^1][k] += (k * f + (K - 1.0)/K)*pr[i&1][k];
			pr[i&1^1][k+1] += f*pr[i&1][k];
			dp[i&1^1][k] += k*f * ((k+1)*1.0/2*pr[i&1][k]+dp[i&1][k]) + (K-1)*dp[i&1][k]/K;
			//cout << (1.0/K * k / (k+1) * (k+1)*k/2 + (K - 1.0)/K) << "\n";
			/*
			if(i+1 == 2 && k == 2){
				cout << "bang: " << k*f * ((k+1)*k/2*pr[i][k]+dp[i][k]) + (K-1)*dp[i][k]/K << "\n";
				cout << k*f * (1.0*(k+1)/2*pr[i][k]+dp[i][k]) << "\n";
				//cout << (K-1)*dp[i][k]/K << "\n";
			}
			*/
			dp[i&1^1][k+1] += f*(dp[i&1][k] + pr[i&1][k] * k);
			/*
			if(i+1 == 2 && k+1 == 2){
				cout << dp[i+1][k+1] << "\n";
				cout << pr[i][k] << "\n";
			}
			cout << pr[i][k] << " " << dp[i][k] << " " << i << " " << k << "\n";
			*/
			pr[i&1][k] = dp[i&1][k] = 0;
		}
	}
	long double ans = 0;
	for(int k =1; k<=1000; k++){
		//cout << dp[N][k] << "\n";
		//cout << pr[N][k] << "\n";
		ans += dp[N&1][k];
	}
	cout << setprecision(12) << ans*K;
}