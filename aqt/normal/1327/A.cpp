
// Problem : A. Sum of Odd Integers
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/0
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
		long long n, k;
		cin >> n >> k;
		if(n%2 == k%2 && k*k <= n){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}