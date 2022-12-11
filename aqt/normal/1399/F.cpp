
// Problem : F. Yet Another Segments Subset
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
short dp[2][6005][6005];
vector<int> cmp;
int lft[3005], rht[3005];
vector<int> idx[6005];

int getidx(int n){
	return lower_bound(cmp.begin(), cmp.end(), n) - cmp.begin() + 1;
}

short solve(int t, int l, int r){
	if(l > r){
		return 0;
	}
	if(dp[t][l][r]+1){
		return dp[t][l][r];
	}
	dp[t][l][r] = solve(0, l+1, r);
	for(int n : idx[l]){
		if(rht[n] <= r-t){
			dp[t][l][r] = max(dp[t][l][r], (short) (solve(1, l, rht[n]) + solve(0, rht[n]+1, r) + 1));
		}
	}
	return dp[t][l][r];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		cmp.clear();
		for(int i = 1; i<=N; i++){
			cin >> lft[i] >> rht[i];
			cmp.emplace_back(lft[i]);
			cmp.emplace_back(rht[i]);
		}
		for(int i = 1; i<=2*N+1; i++){
			idx[i].clear();
			for(int j = 1; j<=2*N+1; j++){
				dp[1][i][j] = dp[0][i][j] = -1;
			}
		}
		sort(cmp.begin(), cmp.end());
		cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
		for(int i = 1; i<=N; i++){
			lft[i] = getidx(lft[i]);
			rht[i] = getidx(rht[i]);
			idx[lft[i]].emplace_back(i);
		}
		cout << solve(0, 1, cmp.size()) << "\n";
	}
}