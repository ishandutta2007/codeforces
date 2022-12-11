
// Problem : B. AND 0, Sum Big
// Contest : Codeforces - Codeforces Round #716 (Div. 2)
// URL : https://codeforces.com/contest/1514/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, K;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> K;
		long long ans = 1;
		const long long MOD = 1e9+7;
		while(K--){
			ans *= N;
			ans %= MOD;
		}
		cout << ans << "\n";
	}
}