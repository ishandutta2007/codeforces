
// Problem : A. A Variety of Operations
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/0
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
		int A, B;
		cin >> A >> B;
		if(A%2 != B%2){
			cout << -1 << "\n";
		}
		else if(A == 0 && B == 0){
			cout << 0 << "\n";
		}
		else if(A == B){
			cout << 1 << "\n";
		}
		else{
			cout << 2 << "\n";
		}
	}
}