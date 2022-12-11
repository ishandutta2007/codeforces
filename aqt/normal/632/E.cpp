
// Problem : E. Thief in a Shop
// Contest : Educational Codeforces Round 9
// URL : https://codeforces.com/contest/632/problem/E
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[1000005];
set<int> st;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	fill(dp+1, dp+1+1000000, 1000000);
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		st.insert(n);
	}
	for(int n : st){
		n -= *st.begin();
		for(int i = n; i<=1000000; i++){
			dp[i] = min(dp[i], dp[i-n] + 1);
		}		
	}
	for(int i = 0; i<=1000000; i++){
		if(dp[i] <= K){
			cout << i+K*(*st.begin()) << " ";
		}
	}
}