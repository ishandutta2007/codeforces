
// Problem : A. Division
// Contest : Codeforces - Codeforces Round #680 (Div. 1, based on Moscow Team Olympiad)
// URL : https://codeforces.com/contest/1444/problem/A
// Memory Limit : 512 MB
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
		long long A, B;
		cin >> A >> B;
		if(A%B){
			cout << A << "\n";
			continue;
		}
		long long ans = 1;
		long long T = B;
		for(int i = 2; i<=sqrt(T); i++){
			if(T%i == 0){
				long long tmp = A;
				while(T%i == 0){
					T /= i;
				}
				while(tmp%B == 0){
					tmp /= i;
				}
				ans = max(ans, tmp);
			}
		}
		if(T > 1){
			while(A%B == 0){
				A /= T;
			}
			ans = max(ans, A);
		}
		cout << ans << "\n";
	}
}