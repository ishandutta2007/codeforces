
// Problem : F. Make k Equal
// Contest : Codeforces - Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1328/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
long long arr[200005];
long long pre[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+1+N);
	long long ans = LLONG_MAX;
	partial_sum(arr, arr+2+N, pre);
	for(int i = 1; i<=N; i++){
		int l = i;
		int cnt = 1;
		while(i < N && arr[i+1] == arr[l]){
			i++;
			cnt++;
		}
		if(cnt >= K){
			ans = 0;
		}
		else{
			long long lft = 1LL*(l-1)*(arr[l]-1)-pre[l-1];
			long long rht = pre[N] - pre[i] - (1LL*(N-i)*(arr[l]+1));
			if(l-1+cnt >= K){
				ans = min(ans, lft + K-cnt);
			}
			if(N-i+cnt >= K){
				ans = min(ans, rht + K-cnt);
			}
			ans = min(ans, lft + rht + K-cnt);
		}
	}
	cout << ans;
}