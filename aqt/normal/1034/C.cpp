
// Problem : C. Region Separation
// Contest : Codeforces - Codeforces Round #511 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1034/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[1000005], val[1000005];
vector<int> graph[1000005];
long long cnt[1000005], dp[1000005];
const long long MOD = 1e9+7;
map<long long, long long> mp;

void dfs(int n){
	val[n] = arr[n];
	for(int e : graph[n]){
		dfs(e);
		val[n] += val[e];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long T = 0;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		T += arr[i];
	}
	for(int i = 2; i<=N; i++){
		int p;
		cin >> p;
		graph[p].push_back(i);
	}
	dfs(1);
	for(int i = 1; i<=N; i++){
		long long g = __gcd(val[i], T);
		mp[g]++;
	}
	long long ans = 0;
	dp[1] = 1;
	for(int n = 1; n<=N; n++){
		if(T%n == 0){
			for(auto p : mp){
				if(p.first%(T/n) == 0){
					cnt[n] += p.second;
				}
			}
			//cout << n << " " << cnt[n] << "\n";
			if(cnt[n] == n){
				for(int j = 2*n; j<=N; j+=n){
					dp[j] += dp[n];
					dp[j] %= MOD;
				}
			}
			else{
				dp[n] = 0;
			}
		}
		else{
			dp[n] = 0;
		}
		ans += dp[n];
		ans %= MOD;
	}
	cout << ans;
}