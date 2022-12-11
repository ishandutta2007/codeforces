
// Problem : E. Intellectual Inquiry
// Contest : Codeforces - CROC 2016 - Elimination Round
// URL : https://codeforces.com/contest/645/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
string s;
long long dp[2000005];
int lst[30];
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> s;
	dp[0] = 1;
	for(int i = 1; i<=s.size(); i++){
		dp[i] = 2*dp[i-1];
		if(lst[s[i-1]-'a']){
			dp[i] -= dp[lst[s[i-1]-'a']-1];
			dp[i] %= MOD;
			dp[i] += MOD;
		}
		dp[i] %= MOD;
		lst[s[i-1]-'a'] = i;
	}
	for(int i = s.size()+1; i<=N+s.size(); i++){
		dp[i] = dp[i-1] * 2;
		int mn = 0;
		for(int c = 1; c<K; c++){
			if(lst[c] < lst[mn]){
				mn = c;
			}
		}
		if(lst[mn]){
			dp[i] -= dp[lst[mn]-1];
			dp[i] %= MOD;
			dp[i] += MOD;
		}
		dp[i] %= MOD;
		lst[mn] = i;
	}
	/*
	for(int i = 1; i<=N+s.size(); i++){
		cout << dp[i] << "\n";
	}
	*/
	cout << dp[N+s.size()] << "\n";
}