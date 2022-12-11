
// Problem : D. Sum
// Contest : Codeforces - Codeforces Round #681 (Div. 1, based on VK Cup 2019-2020 - Final)
// URL : https://codeforces.com/contest/1442/problem/D
// Memory Limit : 512 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long ans = 0;
vector<long long> pre[3005];
long long val[3005];
int wt[3005];

void solve(int l, int r, vector<long long> dp){
	if(l == r){
		for(int i = 0; i<=min(wt[l], K); i++){
			ans = max(ans, dp[K-i] + pre[l][i]);
		}
		return;
	}
	int mid = (l+r)/2;
	vector<long long> lft = dp;
	for(int i = mid+1; i<=r; i++){
		for(int j = K; j >= wt[i]; j--){
			lft[j] = max(lft[j], lft[j-wt[i]] + val[i]);
		}
	}
	solve(l, mid, lft);
	vector<long long> rht = dp;
	for(int i = l; i<=mid; i++){
		for(int j = K; j >= wt[i]; j--){
			rht[j] = max(rht[j], rht[j-wt[i]] + val[i]);
		}
	}
	solve(mid+1, r, rht);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> wt[i];
		pre[i].emplace_back(0);
		for(int j = 1; j<=wt[i]; j++){
			int n;
			cin >> n;
			pre[i].push_back(pre[i].back() + n);
			val[i] += n;
		}
	}
	vector<long long> dp(K+1);
	solve(1, N, dp);
	cout << ans;
}