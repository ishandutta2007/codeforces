
// Problem : C. New Game Plus!
// Contest : Codeforces - Codeforces Round #687 (Div. 1, based on Technocup 2021 Elimination Round 2)
// URL : https://codeforces.com/contest/1456/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long arr[500005];
long long sum[500005];
long long pre[500005];
long long suf[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N, greater<long long>());
	for(int i = 1; i<=N; i++){
		sum[i] = sum[i-1] + arr[i];
		pre[i] = pre[i-1] + sum[i];
	}
	K++;
	for(int i = N; i; i--){
		suf[i] = arr[i]*((N-i)/K) + suf[i+1];
	}
	long long ans = LLONG_MIN;
	for(int i = 0; i<N; i++){
		ans = max(ans, sum[i]*((N-i-1)/K) + pre[i] + suf[i+1]);
	}
	cout << ans;
}