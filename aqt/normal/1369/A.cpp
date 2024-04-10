
// Problem : A. FashionabLee
// Contest : Codeforces - Codeforces Round #652 (Div. 2)
// URL : https://codeforces.com/contest/1369/problem/A
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
		int n;
		cin >> n;
		if(n%4){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}