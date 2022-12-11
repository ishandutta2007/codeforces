
// Problem : D. Good Sequences
// Contest : Codeforces Round #162 (Div. 2)
// URL : https://codeforces.com/problemset/problem/265/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		int mx = dp[n];
		for(int p = 2; p<=sqrt(n); p++){
			if(n%p == 0){
				mx = max(mx, dp[p]);
				mx = max(mx, dp[n/p]);
			}
		}
		mx++;
		for(int p = 2; p<=sqrt(n); p++){
			if(n%p == 0){
				dp[p] = dp[n/p] = mx;
			}
		}
		dp[n] = mx;
	}
	cout << *max_element(dp+1, dp+100001) << "\n";
}