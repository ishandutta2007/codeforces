
// Problem : F. Yet Another Minimization Problem
// Contest : Codeforces - Codeforces Round #438 by Sberbank and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL : https://codeforces.com/problemset/problem/868/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[100005];
int fre[100005];
long long dp[25][100005];
long long tot = 0;
int rngl = 1, rngr = 0;

void solve(int lvl, int l, int r, int optl, int optr){
	if(l > r){
		return;
	}
	int idx = l+r>>1;
	while(rngr > idx){
		fre[arr[rngr]]--;
		tot -= fre[arr[rngr]];
		rngr--;
	}
	while(rngr < idx){
		rngr++;
		tot += fre[arr[rngr]];
		fre[arr[rngr]]++;
	}
	//cout << tot << "\n";
	while(rngl > optl){
		rngl--;
		tot += fre[arr[rngl]];
		fre[arr[rngl]]++;
	}
	while(rngl < optl){
		fre[arr[rngl]]--;
		tot -= fre[arr[rngl]];
		rngl++;
	}
	int opt = rngl;
	dp[lvl][idx] = tot + dp[lvl-1][optl-1];
	while(rngl <= min(idx, optr)){
		//cout << idx << " " << rngl << " " << dp[lvl-1][rngl-1] << " " << tot << "\n";
		if(tot + dp[lvl-1][rngl-1] < dp[lvl][idx]){
			dp[lvl][idx] = tot + dp[lvl-1][rngl-1];
			opt = rngl;
		}
		fre[arr[rngl]]--;
		tot -= fre[arr[rngl]];
		rngl++;
	}
	solve(lvl, l, idx-1, optl, opt);
	solve(lvl, idx+1, r, opt, optr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		tot += fre[arr[i]];
		fre[arr[i]]++;
		dp[1][i] = tot;
	}
	for(int k = 2; k<=K; k++){
		fill(fre, fre+1+N, 0);
		rngr = 0, rngl = 1;
		tot = 0;
		solve(k, k, N, k, N);
		/*
		for(int i = 1; i<=N; i++){
			cout << dp[k][i] << " ";
		}
		cout << "\n";
		*/
	}
	cout << dp[K][N] << "\n";
}