
// Problem : F2. Long Colorful Strip
// Contest : Codeforces Global Round 4
// URL : https://codeforces.com/contest/1178/problem/F2
// Memory Limit : 256 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long dp[1005][1005];
int lft[505];
int rht[505];
int arr[1000005];
vector<int> v;
vector<int> idx[505];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long solve(int l, int r){
	if(l > r){
		return 1;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	int val = v[l];
	for(int i = l; i<=r; i++){
		val = min(val, v[i]);
	}
	long long lftsum = 0, rhtsum = 0;
	for(int i = lft[val]; i>=l; i--){
		lftsum = add(lftsum, mult(solve(l, i-1), solve(i, lft[val]-1)));
	}
	for(int i = rht[val]; i<=r; i++){
		rhtsum = add(rhtsum, mult(solve(rht[val]+1, i), solve(i+1, r)));
	}
	long long midsum = 1;
	for(int i = 1; i<idx[val].size(); i++){
		midsum = mult(midsum, solve(idx[val][i-1]+1, idx[val][i]-1));
	}
	//cout << l << " " << r << " " << lftsum << " " << rhtsum << " " << midsum << "\n";	
	return dp[l][r] = mult(mult(lftsum, rhtsum), midsum);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	v.emplace_back(0);
	for(int i = 1; i<=M; i++){
		int n;
		cin >> n;
		arr[i] = n;
		v.emplace_back(n);
	}
	v.erase(unique(v.begin(), v.end()), v.end());
	M = v.size()-1;
	for(int i = 1; i<=M; i++){
		if(!lft[v[i]]){
			lft[v[i]] = i;
		}
		rht[v[i]] = i;
		idx[v[i]].emplace_back(i);
	}	
	for(int i = 1; i<=N; i++){
		for(int j = i+1; j<=N; j++){
			if(lft[j] <= lft[i] && lft[i] <= rht[j]){
				cout << 0;
				return 0;
			}
			if(lft[j] <= rht[i] && rht[i] <= rht[j]){
				cout << 0;
				return 0;
			}
		}
	}
	if(M > 2*N){
		cout << 0 << "\n";
		return 0;
	}
	for(int i = 1; i<=M; i++){
		fill(dp[i]+1, dp[i]+M+1, -1);
	}
	solve(1, M);
	cout << dp[1][M] << "\n";
}