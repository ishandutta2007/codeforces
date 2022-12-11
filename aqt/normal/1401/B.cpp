
// Problem : B. Ternary Sequence
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/contest/1401/problem/B
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
		int A, B, C;
		cin >> A >> B >> C;
		int X, Y, Z;
		cin >> X >> Y >> Z;
		int K = min(C, Y);
		C -= K;
		Y -= K;
		int ans = 2*K;
		if(Z > A+C){
			ans -= 2*(Z-A-C);
		}
		cout << ans << "\n";
	}
}