
// Problem : C. Maxim and Matrix
// Contest : Codeforces - Codeforces Round #160 (Div. 1)
// URL : https://codeforces.com/contest/261/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N, K;
int B = 60;
long long mat[65][65];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	if(K != (1LL<<__builtin_ctz(K))){
		cout << 0 << "\n";
		return 0;
	}
	K = __builtin_ctz(K);
	N++;
	mat[0][0] = 1;
	for(int b = 1; b<=B; b++){
		mat[b][0] = 1;
		for(int k = 1; k<=60; k++){
			mat[b][k] = mat[b-1][k-1] + mat[b-1][k];
		}
	}
	long long crnt = 0;
	long long ans = (K ? 0 : -1);
	for(int b = 0; b<=B; b++){
		if((1LL<<b)+crnt <= N){
			crnt += (1LL<<b);
			ans += mat[b][K];
		}
		else{
			//cout << b << endl;
			N = N - crnt;
			for(; b>=0; b--){
				if(N - (1LL<<b) >= 0){
					N -= (1LL<<b);
					ans += mat[b][K];
					K--;					
				}
			}
			break;
		}
	}
	cout << ans << "\n";
}