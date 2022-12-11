
// Problem : C. Captains Mode
// Contest : Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/contest/377/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
int dp[1<<20];
bool vis[1<<20];
char act[20];
int who[20];

int solve(int n){
	if(vis[n]){
		return dp[n];
	}
	vis[n] = 1;
	int k = N-__builtin_popcount(n);
	if(who[k] == 1){
		dp[n] = INT_MIN/2;
	}
	else{
		dp[n] = INT_MAX/2;
	}
	for(int i = 0; i<N; i++){
		if(n>>i&1){
			if(act[k] == 'b' && who[k] == 1){
				dp[n] = max(dp[n], solve(n^(1<<i)));
			}
			else if(act[k] == 'b' && who[k] == 2){
				dp[n] = min(dp[n], solve(n^(1<<i)));
			}
			else if(act[k] == 'p' && who[k] == 1){
				dp[n] = max(dp[n], solve(n^(1<<i)) + v[i]);
			}
			else{
				dp[n] = min(dp[n], solve(n^(1<<i)) - v[i]);
			}
		}
	}
	//cout << n << " " << dp[n] << endl;
	return dp[n];
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i<N; i++){
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end(), greater<int>());
	cin >> N;
	v.erase(v.begin()+N, v.end());
	for(int i = 0; i<N; i++){
		cin >> act[i] >> who[i];
	}
	vis[0] = 1;
	cout << solve((1<<N)-1);
}