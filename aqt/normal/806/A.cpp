
// Problem : A. Success Rate
// Contest : Codeforces - Codeforces Round #412 (rated, Div. 1, based on VK Cup 2017 Round 3)
// URL : https://codeforces.com/contest/806/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		int g = __gcd(p, q);
		if(p == q){
			if(x == y){
				cout << 0 << "\n";
			}
			else{
				cout << -1 << "\n";
			}
		}
		else if(p == 0){
			if(x == 0){
				cout << 0 << "\n";
			}
			else{
				cout << -1 << "\n";
			}
		}
		else{
			p /= g;
			q /= g;
			long long l = 1, r = 1000000000, ans = 0;
			while(l <= r){
				long long mid = l+r>>1;
				long long d = mid*q-y;
				long long f = mid*p-x;
				if(d >= f && f >= 0){
					ans = d;
					r = mid - 1;
				}
				else{
					l = mid + 1;
				}
			}
			cout << ans << "\n";
		}
	}
}