
// Problem : B. Let's Play Osu!
// Contest : Codeforces - Codeforces Round #146 (Div. 1)
// URL : https://codeforces.com/problemset/problem/235/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long double arr[100005];
long double dp[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long double ans = 0;
	for(int i =1 ; i<=N; i++){
		cin >> arr[i];
		dp[i] = (dp[i-1] + arr[i-1]) * arr[i];
		ans += 2*dp[i] + arr[i];
	}
	cout << setprecision(12) << ans << "\n";
}