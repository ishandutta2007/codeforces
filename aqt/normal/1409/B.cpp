
// Problem : B. Minimum Product
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/B
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
		long long A, B, X, Y, N;
		cin >> A >> B >> X >> Y >> N;
		if(A > B){
			swap(A, B);
			swap(X, Y);
		}
		long long opt1 = 0, opt2 = 0;
		if(N > A-X){
			opt1 = X * max(Y, B-(N-A+X));
		}
		else{
			opt1 = (A-N) * B;
		}
		if(N > B-Y){
			opt2 = Y * max(X, A - (N-B+Y));
		}
		else{
			opt2 = (B-N) * A;
		}
		cout << min(opt1, opt2) << "\n";
	}
}