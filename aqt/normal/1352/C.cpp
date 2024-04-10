
// Problem : C. K-th Not Divisible by n
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		long long l = 1, r = 1e16, ans = 0;
		while(l <= r){
			long long mid = l+r>>1;
			long long cnt = mid - mid/N;
			if(cnt >= K){
				r = mid - 1;
				ans = mid;
			}
			else{
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}