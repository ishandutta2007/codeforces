
// Problem : D. Segment Intersections
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/D
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
		long long N, K;
		cin >> N >> K;
		long long l1, r1;
		cin >> l1 >> r1;
		long long l2, r2;
		cin >> l2 >> r2;
		if(r2 < r1){
			swap(r1, r2);
			swap(l1, l2);
		}
		long long rng = max(r2 - l1, r2 - l2);
		long long ans = LLONG_MAX/2;
		if(l2 > r1){
			for(long long i = 1; i<=N; i++){
				long long tot = 1LL*(l2-r1)*i;
				if(1LL*rng*i >= K){
					tot += K;
				}
				else{
					tot += 1LL*rng*i;
					tot += 2LL*(K-1LL*rng*i);
				}
				ans = min(tot, ans);
			}
		}
		else{
			K -= 1LL*N*(r1 - max(l1, l2));
			if(K < 0){
				ans = 0;
			}
			else{
				long long x = 1LL*r2-r1 + 1LL*abs(l1-l2);
				for(long long i = 1; i<=N; i++){
					long long tot = 0;
					if(1LL*x*i >= K){
						tot += K;
					}
					else{
						tot += 1LL*x*i;
						tot += 2LL*(K-1LL*x*i);
					}
					ans = min(tot, ans);
				}
				//ans = max(ans, 0LL);
			}
		}
		cout << ans << "\n";
	}
}