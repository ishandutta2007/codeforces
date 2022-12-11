
// Problem : A. Potion-making
// Contest : Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1525/problem/A
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
		int K;
		cin >> K;
		int A = 100 - K;
		int G = __gcd(K, A);
		K /= G;
		A /= G;
		cout << A + K << "\n";
	}
}