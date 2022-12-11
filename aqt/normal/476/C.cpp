
// Problem : C. Dreamoon and Sums
// Contest : Codeforces - Codeforces Round #272 (Div. 2)
// URL : https://codeforces.com/contest/476/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	long long MOD = 1e9+7;
	for(int i = 1; i<b; i++){
		ans += (a * i + (1+a)*a/2%MOD*b%MOD*i%MOD)%MOD;
		ans %= MOD;
	}
	cout << ans;
}