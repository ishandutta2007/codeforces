
// Problem : D. Felicity's Big Secret Revealed
// Contest : Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL : https://codeforces.com/contest/757/problem/D
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100];
int dp[80][1<<20];
const int MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		arr[i] = c-'0';
	}
	int ans = 0;
	for(int i = 0; i<=N; i++){
		vector<pair<int, int>> vec;
		dp[i][0] = 1;
		int v = 0;
		for(int k = i+1; k<=N; k++){
			v <<= 1;
			v += arr[k];
			if(v > 20){
				break;
			}
			else if(v){
				vec.emplace_back(v-1, k);
			}
		}
		for(int m = 0; m<1<<20; m++){
			for(auto p : vec){
				dp[p.second][m|(1<<p.first)] += dp[i][m];
				dp[p.second][m|(1<<p.first)] %= MOD;
			}
		}
		for(int m = 2; m<=(1<<20); m<<=1){
			ans += dp[i][m-1];
			ans %= MOD;
		}
	}
	cout << ans;
}