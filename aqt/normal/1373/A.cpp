
// Problem : A. Donut Shops
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1373/problem/A
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
		long long A, B, C;
		cin >> A >> B >> C;
		if(A < C){
			cout << 1 << " ";
		}
		else{
			cout << -1 << " ";
		}
		if(A*B > C){
			cout << B << "\n";
		}
		else{
			cout << -1 << "\n";
		}
	}
}