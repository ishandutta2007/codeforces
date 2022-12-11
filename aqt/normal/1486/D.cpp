
// Problem : D. Max Median
// Contest : Codeforces - Codeforces Round #703 (Div. 2)
// URL : https://codeforces.com/contest/1486/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[200005];
int pre[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	int l = 1, r = N, ans = 0;
	while(l <= r){
		int mid = l+r>>1;
		int mn = INT_MAX/2;
		bool good = 0;
		for(int i= 1; i<=N; i++){
			pre[i] = 2*(arr[i] - mid >= 0)-1;
			pre[i] += pre[i-1];
			if(i >= K){
				mn = min(mn, pre[i-K]);
			}
			if(pre[i] - mn > 0){
				good = 1;
			}
		}
		if(good){
			l = mid + 1;
			ans = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
}