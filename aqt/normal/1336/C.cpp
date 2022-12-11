
// Problem : C. Kaavi and Magic Spell
// Contest : Codeforces - Codeforces Round #635 (Div. 1)
// URL : https://codeforces.com/contest/1336/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
string s, t;
long long dp[3005][3005];
bool vis[3005][3005];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

/*
long long rec(long long l, long long r){
	if(vis[l][r]){
		return dp[l][r];
	}
	vis[l][r] = 1;
	char c = s[r-l+1];
	if(l != 1){
		if(l <= M){
			if(t[l-1] == c){
				dp[l][r] = add(dp[l][r], rec(l-1, r));
			}
		}
		else{
			dp[l][r] = add(dp[l][r], rec(l-1, r));
		}
	}
	if(r <= N){
		if(r <= M){
			if(t[r-1] == c){
				dp[l][r] = add(dp[l][r], rec(l, r+1));
			}
		}
		else{
			dp[l][r] = add(dp[l][r], rec(l, r+1));
		}
	}
	return dp[l][r];
}
*/

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s >> t;
	N = s.size(), M = t.size();
	//vis[1][N] = 1;
	//dp[1][N] = 1;
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		if(i <= M && s[0] == t[i-1]){
			dp[i][i] = 2;
			//ans = add(ans, rec(i, i));
		}
		else if(i > M){
			dp[i][i] = 2;
			//ans = add(ans, rec(i, i));
		}
	}
	for(int len = 0; len+1<N; len++){
		char c = s[len+1];
		for(int l = 1; l+len <= N; l++){
			int r = l+len;
			//cout << l << " " << r << " " << dp[l][r] << "\n";
			if(l != 1){
				if(l-1 <= M){
					if(t[l-2] == c){
						dp[l-1][r] = add(dp[l-1][r], dp[l][r]);
					}
				}
				else{
					dp[l-1][r] = add(dp[l][r], dp[l-1][r]);
				}				
			}
			if(r < N){
				if(r+1 <= M){
					if(t[r] == c){
						dp[l][r+1] = add(dp[l][r], dp[l][r+1]);
					}
				}
				else{
					dp[l][r+1] = add(dp[l][r], dp[l][r+1]);
				}
			}			
		}
	}
	//cout << dp[1][N] << "\n";
	for(int i = M; i<=N; i++){
		ans = add(ans, dp[1][i]);
	}
	cout << ans << "\n";
}