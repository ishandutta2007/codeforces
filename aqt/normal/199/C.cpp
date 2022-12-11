
// Problem : C. About Bacteria
// Contest : Codeforces - Codeforces Round #125 (Div. 2)
// URL : https://codeforces.com/contest/199/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long K, B, N, T;
	cin >> K >> B >> N >> T;
	long long X = 1;
	for(int i = 1; i<=N; i++){
		if(X*K + B > T){
			cout << N - i + 1 << "\n";
			return 0;
		}
		X *= K;
		X += B;
	}
	cout << 0 << endl;
}