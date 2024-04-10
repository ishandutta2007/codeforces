
// Problem : A. Bear and Colors
// Contest : VK Cup 2016 - Round 3
// URL : https://codeforces.com/contest/643/problem/A
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int arr[5005];
int cnt[5005];
int ans[5005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i =1 ; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=N; i++){
		int mx = 0;
		for(int j = 1; j<=N; j++){
			cnt[j] = 0;
		}
		for(int j = i; j<=N; j++){
			cnt[arr[j]]++;
			if(cnt[mx] == cnt[arr[j]] && arr[j] < mx){
				mx = arr[j];
			}		
			else if(cnt[mx] < cnt[arr[j]]){
				mx = arr[j];
			}
			ans[mx]++;
		}
	}
	for(int i = 1; i<=N; i++){
		cout << ans[i] << " ";
	}
}