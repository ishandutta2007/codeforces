
// Problem : A. LCM Problem
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/A
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
		long long l, r;
		cin >> l >> r;
		if(2*l > r){
			cout << -1 << " " << -1 << "\n";
		}
		else{
			cout << l << " " << 2*l << "\n";
		}
	}
}