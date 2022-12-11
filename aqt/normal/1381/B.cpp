
// Problem : B. Unmerge
// Contest : Codeforces - Codeforces Round #658 (Div. 1)
// URL : https://codeforces.com/contest/1381/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

bool dp[4005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int S = 0;
		int mx = 0;
		vector<int> lst;
		for(int i = 1; i<=2*N; i++){
			int n;
			cin >> n;
			if(n > mx){
				lst.push_back(S);
				S = 1;
				mx = n;
			}
			else{
				S++;
			}
		}
		lst.push_back(S);
		fill(dp, dp+2*N+1, 0);
		dp[0] = 1;
		for(int k : lst){
			for(int n = 2*N; n>=k; n--){
				dp[n] |= dp[n-k];
			}
		}
		cout << (dp[N] ? "YES\n" : "NO\n");
	}
}