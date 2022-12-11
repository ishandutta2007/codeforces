
// Problem : D. Monitor
// Contest : Codeforces - Educational Codeforces Round 28
// URL : https://codeforces.com/contest/846/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K, P;
int pre[505][505];
int x[505*505], y[505*505], t[505*505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K >> P;
	for(int i = 1; i<=P; i++){
		cin >> x[i] >> y[i] >> t[i];
	}
	int l = 0, r = 1000000000, ans = -1;
	while(l <= r){
		int mid = l+r>>1;
		memset(pre, 0, sizeof pre);
		for(int i = 1; i<=P; i++){
			if(t[i] <= mid){
				pre[x[i]][y[i]]++;
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
			}
		}
		bool bad = 0;
		for(int i = K; i<=N; i++){
			for(int j = K; j<=M; j++){
				//cout << pre[i][j] - pre[i-K][j] - pre[i][j-K] + pre[i-K][j-K] << "\n";
				if(pre[i][j] - pre[i-K][j] - pre[i][j-K] + pre[i-K][j-K] == K*K){
					ans = mid;
					bad = 1;
				}
			}
		}
		if(bad){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans;
}