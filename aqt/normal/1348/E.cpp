
// Problem : E. Phoenix and Berries
// Contest : Codeforces - Codeforces Round #638 (Div. 2)
// URL : https://codeforces.com/contest/1348/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> dp[505][505];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	for(int i = 0; i<=N; i++){
		for(int j = 0; j<=K; j++){
			dp[i][j] = {LLONG_MIN/4, 0};
		}
	}
	dp[0][0] = {0, 0};
	for(int i = 0; i<N; i++){
		int a, b;
		cin >> a >> b;
		for(int j = 0; j<K; j++){
			if(dp[i][j].first == LLONG_MIN/4){
				continue;
			}
			for(int t = 0; t<min(a+1, K); t++){
				long long amt = dp[i][j].first;
				int rema = t+j;
				if(rema >= K){
					amt++;
					rema %= K;
				}
				int n = a+b-t;
				amt += n/K;
				int remb = min(b, n%K) + dp[i][j].second;
				if(remb >= K){
					amt++;
					remb %= K;
				}
				dp[i+1][rema] = max(dp[i+1][rema], {amt, remb});
			}
		}
	}
	long long ans = 0;
	for(int j = 0; j<K; j++){
		ans = max(ans, dp[N][j].first);
	}
	cout << ans << "\n";
}