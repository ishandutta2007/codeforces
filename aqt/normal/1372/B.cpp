
// Problem : B. Omkar and Last Class of Math
// Contest : Codeforces - Codeforces Round #655 (Div. 2)
// URL : https://codeforces.com/contest/1372/problem/B
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
		int N;
		cin >> N;
		long long ans = N-1;
		for(int i = 1; i<=sqrt(N); i++){
			if(N%i == 0){
				int k = i;
				if(k != N){
					ans = min(ans, 1LL*k*(N-k)/__gcd(k, N-k));
				}
				k = N/i;
				if(k != N){
					ans = min(ans, 1LL*k*(N-k)/__gcd(k, N-k));
				}
			}
		}
		cout << ans << " " << N-ans << "\n";
	}
}