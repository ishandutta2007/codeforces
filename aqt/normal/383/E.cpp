
// Problem : E. Vowels
// Contest : Codeforces - Codeforces Round #225 (Div. 1)
// URL : https://codeforces.com/contest/383/problem/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1<<24];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	while(N--){
		string s;
		cin >> s;
		vector<int> v = {1<<s[0]-'a', 1<<s[1]-'a', 1<<s[2]-'a'};
		dp[v[0]]++;
		dp[v[1]]++;
		dp[v[2]]++;
		dp[v[0]|v[1]]--;
		dp[v[1]|v[2]]--;
		dp[v[0]|v[2]]--;
		dp[v[0]|v[1]|v[2]]++;
	}
	for(int b = 0; b<24; b++){
		for(int m = 1; m<1<<24; m++){
			if((1<<b)&m){
				dp[m] += dp[m^(1<<b)];
			}
		}
	}
	int ans = 0;
	for(int m = 1; m<1<<24; m++){
		ans ^= dp[m]*dp[m];
	}
	cout << ans;
}