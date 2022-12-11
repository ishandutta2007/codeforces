
// Problem : A. Shovels and Swords
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/A
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
		long long a, b;
		cin >> a >> b;
		/*
		if(b < a){
			swap(a, b);
		}
		*/
		long long ans = max(min(a/2, b), min(b/2, a));
		//ans = max(ans, min(a/3, b/3));
		long long t = (2*a-b)/3;
		if(t > 0 && min((b-t)/2, (a-2*t)) > 0){
			long long opt = t + min((b-t)/2, (a-2*t));
			//cout << t << " " << opt << "\n";
			ans = max(ans, opt);
		}
		t = (2*b-a)/3;
		if(t > 0 && min((a-t)/2, b-2*t) > 0){
			long long opt = t + min((a-t)/2, b-2*t);
			//cout << t << " " << opt << "\n";
			ans = max(ans, opt);
		}
		/*
		long long ans2 = 0;
		for(int i = 0; i<=a; i++){
			for(int j = 0; j<=b; j++){
				if(2*j+i <= a && j+2*i <= b){
					ans2 = max(ans, 1LL*j+i);
				}
			}
		}
		*/
		cout << ans << "\n";
	}
}