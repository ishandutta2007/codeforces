
// Problem : G2. Lucky Numbers (Hard Version)
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/problemset/problem/1428/G2
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int K, Q, M = 1e6;
long long cst[10];
long long dp[1000005];

void upd(int d, int t, long long v){
	for(int r = 0; r<d; r++){
		deque<pair<int, long long>> dq;
		for(int c = 0; c*d+r<=M; c++){
			const int n = c*d+r;
			long long old = dp[n] - c*v;
			if(dq.size() && c - dq.front().first > t){
				dq.pop_front();
			}
			if(dq.size()){
				dp[n] = max(dp[n], dq.front().second + v * c);
			}
			while(dq.size() && dq.back().second <= old){
				dq.pop_back();
			}
			dq.push_back(make_pair(c, old));
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K;
	fill(dp+1, dp+1+M, LLONG_MIN/2);
	for(int i = 0; i<6; i++){
		cin >> cst[i];
	}
	int crnt = 3;
	for(int i = 0; i<6; i++){
		upd(crnt, K-1, cst[i]);
		upd(crnt, K-1, cst[i]);
		upd(crnt, K-1, cst[i]);
		crnt *= 10;
	}
	/*
	for(int d = 0; d<10; d++){
		crnt = d;
		for(int i = 0; i<6; i++){
			upd(crnt, 1, cst[i]*(d%3 == 0)*(d/3));
			crnt *= 10;
		}
	}
	*/
	crnt = 1;	
	for(int i = 0; i<6; i++){
		for(int n = M; n>=crnt; n--){
			for(int d = 1; d<10; d++){
				if(crnt*d <= n){
					dp[n] = max(dp[n], dp[n-crnt*d] + cst[i]*(d%3 == 0)*(d/3));
				}
			}
		}
		crnt *= 10;
	}
	cin >> Q;
	while(Q--){
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}