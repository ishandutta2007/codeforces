
// Problem : F. Financiers Game
// Contest : Codeforces - Technocup 2017 - Elimination Round 2
// URL : https://codeforces.com/contest/729/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp[4005][4005];
int arr[4005];
int pre[4005];

int solveB(short l, short r, short k);

int solveA(short l, short r, short k){
	if(r-l+1 < k){
		return 0;
	}
	while(dp[l][r].size() < k+1){
		dp[l][r].emplace_back(INT_MAX);
	}
	if(dp[l][r][k] != INT_MAX){
		return dp[l][r][k];
	}
	int ret = pre[l+k-1] - pre[l-1] + solveB(l+k, r, k);
	if(r-l+1 >= k+1){
		ret = max(pre[l+k]-pre[l-1]+solveB(l+k+1,r, k+1), ret);
	}
	return dp[l][r][k] = ret;
}

int solveB(short l, short r, short k){
	if(r-l+1 < k){
		return 0;
	}
	int ret = solveA(l, r-k, k) - (pre[r] - pre[r-k]);
	if(r-l+1 >= k+1){
		ret = min(ret, solveA(l, r-k-1, k+1) - (pre[r]-pre[r-k-1]));
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
		pre[i] = pre[i-1] + arr[i];
	}
	cout << solveA(1, N, 1) << "\n";
}