
// Problem : E. Calendar Ambiguity
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long M, D, W;
		cin >> M >> D >> W;
		long long X = min(M, D);
		long long C = W;
		for(long long k = 1; k<=sqrt(W); k++){
			if(W%k == 0 && k*(D-1)%W == 0){
				C = min(C, k);
			}
			if(W%k == 0 && W/k*(D-1)%W == 0){
				C = min(C, W/k);
			}			
		}
		long long ans = 0;
		long long N = X/C+1;
		//cout << " " << C << "\n";
		//cout << "   " <<  N << "\n";
		ans += (X%C) * (N) * (N-1) / 2;
		ans += (C - X%C) * (N-1) * (N-2) / 2;
		cout  << ans << "\n";
	}
}