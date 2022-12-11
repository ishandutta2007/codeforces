
// Problem : E. Maximum Subsequence Value
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	long long ans = 0;
	for(int i = 1; i<=N; i++){
		ans = max(ans, arr[i]);
		for(int j = i+1; j<=N; j++){
			ans = max(ans, arr[i] | arr[j]);
			for(int k = j+1; k<=N; k++){
				ans = max(ans, arr[i] | arr[j] | arr[k]);
			}
		}
	}
	cout << ans;
}