
// Problem : C. Rotation Matching
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int fre[200005];
int arr[200005], brr[200005];
int idx[200005];

int solve(){
	fill(fre, fre+1+N, 0);
	for(int i = 1; i<=N; i++){
		idx[arr[i]] = i;
	}
	for(int i = 1; i<=N; i++){
		int k = i - idx[brr[i]];
		if(k < 0){
			k += N;
		}
		fre[k]++;
	}
	return *max_element(fre, fre+1+N);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i= 1; i<=N; i++){
		cin >> brr[i];
	}
	int ans = solve();
	for(int i = 1; i<=N; i++){
		swap(arr[i], brr[i]);
	}
	ans = max(ans, solve());
	cout << ans;
}