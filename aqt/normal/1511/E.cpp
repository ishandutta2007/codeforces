
// Problem : E. Colorings and Dominoes
// Contest : Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1511/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<char> mp[300005];
long long dp[300005];
const long long MOD = 998244353;
long long pows[300005];

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long mult(long long a, long long b){
	return a * b % MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int cnt = 0;
	pows[0] = 1;
	for(int i = 1; i <= N * M + 1; i++){
		pows[i] = mult(pows[i - 1], 2);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			char c;
			cin >> c;
			mp[i].emplace_back(c);
			cnt += (c == 'o');
		}
	}
	long long tot = 0, inc = 0;
	for(int i = 1; i <= max(N, M) + 1; i++){
		/*
		inc = add(inc, (i - 1) / 2);
		dp[i] = add(tot, inc);
		tot = add(tot, dp[i]);
		*/
		/*
		for(int j = 0; j < i; j++){
			dp[i] = add(dp[i], add(dp[j], mult(pows[max(0, j - 1)], (i - j - 1) / 2)));
		}
		*/
		//cout << dp[i] << " ";
		dp[i] = add(tot, add(inc, (i - 1) / 2));
		inc = mult(inc, 2);
		inc = add(inc, (i - 1) / 2);
		tot = add(tot, dp[i]);
	}
	//cout << "\n";
	long long ans = 0;
	for(int i = 1; i <= N; i++){
		int len = 0;
		for(int j = 0; j < M; j++){
			if(mp[i][j] == 'o'){
				len++;
			}
			else{
				ans = add(ans, mult(pows[cnt - len], dp[len + 1]));
				len = 0;
			}
		}
		ans = add(ans, mult(pows[cnt - len], dp[len + 1]));
	}
	for(int j = 0; j < M; j++){
		int len = 0;
		for(int i = 1; i <= N; i++){
			if(mp[i][j] == 'o'){
				len++;
			}
			else{
				ans = add(ans, mult(pows[cnt - len], dp[len + 1]));
				len = 0;
			}
		}
		ans = add(ans, mult(pows[cnt - len], dp[len + 1]));		
	}
	cout << ans;
}