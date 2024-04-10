
// Problem : D. Jon and Orbs
// Contest : Divide by Zero 2017 and Codeforces Round #399 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/768/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int D = 8000;
long double dp[1005][D+5];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	dp[1][1] = 1;
	for(int d = 1; d<=D; d++){
		for(int o = 1; o<=min(d, k); o++){
			dp[o+1][d+1] += 1.0*(k-o)/k*dp[o][d];
			dp[o][d+1] += 1.0*(o)/k*dp[o][d];
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int v;
		cin >> v;
		long double c = (v-1e-7)/2000;
		for(int d = k; d<=D; d++){
			if(dp[k][d] > c){
				cout << d << "\n";
				break;
			}
			else if(d == D){
				assert(0);
				//cout << dp[k][d] << "\n";
				//cout << "gay\n";
			}
		}
	}
}