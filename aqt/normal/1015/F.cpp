
// Problem : F. Bracket Substring
// Contest : Codeforces - Codeforces Round #501 (Div. 3)
// URL : https://codeforces.com/contest/1015/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
string s;
long long dp[205][205][205];
int lps[205];
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	for(int j = 0, i = 1; i<s.size(); ){
		if(s[j] == s[i]){
			lps[i++] = ++j;
		}
		else if(!j){
			i++;
		}
		else{
			j = lps[j-1];
		}
	}
	dp[0][0][0] = 1;
	for(int i = 0; i<=2*N; i++){
		for(int j = 0; j<=N; j++){
			for(int k = 0; k<s.size(); k++){
				if(dp[i][j][k]){
					//cout << dp[i][j][k] << " " << i << " " << j << " " << k << "\n";
				}
				dp[i][j][k] %= MOD;
				if(j){
					int t = k;
					while(1){
						if(s[t] == ')'){
							t++;
							break;
						}
						if(!t){
							break;
						}
						t = lps[t-1];
					}
					//cout << " " << i << " " << j << " " << k << " " << t << "\n";
					dp[i+1][j-1][t] += dp[i][j][k];
				}	
				int t = k;
				while(1){
					if(s[t] == '('){
						t++;
						break;
					}
					if(!t){
						break;
					}
					t = lps[t-1];
				}
				//cout << " " << i << " " << j << " " << k << " " << t << "\n";
				dp[i+1][j+1][t] += dp[i][j][k];
			}
			dp[i][j][s.size()] %= MOD;
			if(dp[i][j][s.size()]){
				//cout << dp[i][j][s.size()] << " " << i << " " << j << " " << s.size() << "\n";
			}
			if(j){
				dp[i+1][j-1][s.size()] += dp[i][j][s.size()];
			}
			dp[i+1][j+1][s.size()] += dp[i][j][s.size()];
		}
	}
	cout << dp[2*N][0][s.size()] << "\n";
}