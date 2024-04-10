
// Problem : D. Kindergarten
// Contest : Codeforces - Codeforces Round #276 (Div. 1)
// URL : https://codeforces.com/contest/484/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[1000005];
long long arr[1000005];
deque<pair<long long, long long>> mn, mx;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		dp[i] = dp[i-1];
		while(mn.size() && mn.back().second > arr[i]){
			mn.pop_back();
		}
		while(mx.size() && mx.back().second < arr[i]){
			mx.pop_back();
		}
		if(mn.size()){
			dp[i] = max(dp[i], mn.back().first + arr[i]);
		}
		if(mx.size()){
			dp[i] = max(dp[i], mx.back().first - arr[i]);
		}
		if(mn.empty() || dp[i] - arr[i] > mn.back().first){
			mn.push_back(make_pair(dp[i-1] - arr[i], arr[i]));
		}
		if(mx.empty() || dp[i] + arr[i] > mx.back().first){
			mx.push_back(make_pair(dp[i-1] + arr[i], arr[i]));
		}
	}
	cout << dp[N] << "\n";
}