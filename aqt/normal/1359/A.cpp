
// Problem : A. Berland Poker
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M, K;
		cin >> N >> M >> K;
		int C = N/K;
		if(M < C){
			cout << M << "\n";
		}
		else{
			cout << C - (M-C+K-2)/(K-1) << "\n";
		}
	}
}