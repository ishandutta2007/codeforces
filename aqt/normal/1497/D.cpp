
// Problem : D. Genius
// Contest : Codeforces - Codeforces Round #708 (Div. 2)
// URL : https://codeforces.com/contest/1497/problem/D
// Memory Limit : 32 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
long long dp[5005];
int tag[5005];
long long val[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> tag[i];
			dp[i] = 0;
		}
		for(int i = 1; i<=N; i++){
			cin >> val[i];
		}
		for(int i = 1; i<=N; i++){
			for(int j = i-1; j; j--){
				long long opti = abs(val[i] - val[j]) + dp[j];
				long long optj = abs(val[i] - val[j]) + dp[i];
				if(tag[i] != tag[j]){
					dp[i] = max(dp[i], opti);
					dp[j] = max(dp[j], optj);
				}
			}
		}
		cout << *max_element(dp, dp+1+N) << "\n";	
	}
}