
// Problem : B. AGAGA XOOORRR
// Contest : Codeforces - Codeforces Round #717 (Div. 2)
// URL : https://codeforces.com/contest/1516/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int X = 0;
		vector<bool> dp(N+5);
		vector<int> vec;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			vec.push_back(n);
			X ^= n;
		}
		if(!X){
			cout << "YES\n";
			continue;
		}
		dp[0] = 1;
		for(int i = 1; i<=N; i++){
			int tmpX = 0;
			for(int j = 1; j<=i; j++){
				tmpX ^= vec[j-1];
			}
			if(i == N){
				tmpX ^= vec[0];
			}
			for(int j = (i == N); j<i; j++){
				if(tmpX == X && dp[j]){
					dp[i] = 1;
				}
				tmpX ^= vec[j];
			}
		}
		if(dp[N]){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}