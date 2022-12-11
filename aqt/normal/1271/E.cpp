
// Problem : E. Common Number
// Contest : Codeforces - Codeforces Round #608 (Div. 2)
// URL : https://codeforces.com/contest/1271/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long K, N;

long long solve(long long n){
	long long ret = 0;
	long long lim = n;
	for(int b = 63 - __builtin_clzll(n); b<=59; b++, n<<=1, lim <<= 1, lim++){
		ret += max(0LL, min(lim, N) - n+1);
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	long long ans = 1;
	long long l = 1, r = N/2;
	while(l <= r){
		long long mid = (l+r)/2*2;
		long long t = solve(mid+1);
		//cout << mid << " " << solve(mid) << " " << t << "\n";
		if(t >= K){
			l = mid/2+1;
			ans = mid+1;
		}
		else if(t + solve(mid) >= K){
			l = mid/2+1;
			ans = mid;
		}
		else{
			r = mid/2 - 1;
		}
	}
	cout << ans << "\n";
}