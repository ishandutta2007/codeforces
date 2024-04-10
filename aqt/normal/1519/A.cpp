
// Problem : A. Red and Blue Beans
// Contest : Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1519/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		long long A, B, K;
		cin >> A >> B >> K;
		if(A < B){
			swap(A, B);
		}
		if(B * (K + 1) >= A){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}