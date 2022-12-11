
// Problem : B. Array Walk
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> M >> K;
		vector<int> v;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
		}
		long long ans = 0;
		for(int k =0; k<=K; k++){
			long long tot = 0, mx = 0;
			for(int i = 0; i<=M-2*k; i++){
				tot += v[i];
				if(i < N){
					mx = max(mx, 1LL*v[i]+v[i+1]);
				}
			}
			ans = max(ans, tot + k*mx);
		}
		cout << ans << "\n";
	}
}