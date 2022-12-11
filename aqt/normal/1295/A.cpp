
// Problem : A. Display The Number
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/0
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n%2 == 1){
			cout << '7';
			n -= 3;
		}
		else{
			cout << '1';
			n -= 2;
		}
		while(n){
			n -= 2;
			cout << '1';
		}
		cout << "\n";
	}
}