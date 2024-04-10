
// Problem : D. Maximum Sum of Products
// Contest : Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1519/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[5005];
long long brr[5005];
long long pre[5005];
long long suf[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int j = 1; j<=N; j++){
		cin >> brr[j];
	}
	for(int i = 1; i<=N; i++){
		pre[i] = pre[i-1] + arr[i] * brr[i];
	}
	for(int i = N; i; i--){
		suf[i] = suf[i+1] + arr[i] * brr[i];
	}
	long long ans = 0;
	for(int c = 1; c<=N; c++){
		long long tot = 0;
		for(int l = c, r = c; l > 0 && r <= N; l--, r++){
			tot += arr[l] * brr[r] + (r != l) * arr[r] * brr[l];
			ans = max(ans, tot + pre[l-1] + suf[r+1]);
		}
	}
	for(int c = 1; c<N; c++){
		long long tot = 0;
		for(int l = c, r = c+1; l > 0 && r <= N; l--, r++){
			tot += arr[l] * brr[r] + arr[r] * brr[l];
			ans = max(ans, tot + pre[l-1] + suf[r+1]);
		}
	}
	cout << ans;
}