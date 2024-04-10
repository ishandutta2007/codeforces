
// Problem : B. Subsequence Hate
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		vector<int> pre[2];
		pre[0].push_back(0), pre[1].push_back(0);
		string s;
		cin >> s;
		int N = s.size();
		for(char c : s){
			int k = c-'0';
			pre[k].push_back(pre[k].back()+1);
			pre[k^1].push_back(pre[k^1].back());
		}
		int ans = 2*N;
		for(int i = 0; i<=N; i++){
			ans = min(ans, pre[1][i] + pre[0][N] - pre[0][i]);
			ans = min(ans, pre[0][i] + pre[1][N] - pre[1][i]);
		}
		cout << ans << "\n";
	}
}