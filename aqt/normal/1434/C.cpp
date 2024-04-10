
// Problem : C. Solo mid Oracle
// Contest : Codeforces - Codeforces Round #679 (Div. 1, based on Technocup 2021 Elimination Round 1)
// URL : https://codeforces.com/contest/1434/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int Q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> Q;
	while(Q--){
		long long A, B, C, D;
		cin >> A >> B >> C >> D;
		if(B*C < A){
			cout << -1 << "\n";
			continue;
		}
		long long l = 1, r = 3000000, ans = 0;
		while(l <= r){
			long long mid = l + r >> 1;
			if(mid * B * D - A < 0){
				l = mid + 1;
			}
			else{
				ans = mid * (mid-1)/2 * B * D - A * mid;
				r= mid - 1;
			}
		}
		cout << -ans << "\n";
	}
}