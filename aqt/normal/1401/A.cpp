
// Problem : A. Distance and Axis
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/A
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
		int A, K;
		cin >> A >> K;
		if(A > K){
			cout << (A%2 != K%2) << "\n";
		}
		else{
			cout << K-A << "\n";
		}
	}
}