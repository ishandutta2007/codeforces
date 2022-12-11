
// Problem : A. The Miracle and the Sleeper
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
		if(l * 2 <= r){
			cout << (r - 1) / 2 << "\n";
		}
		else{
			cout << r % l << "\n";
		}
	}
}