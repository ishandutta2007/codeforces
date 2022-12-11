
// Problem : A. Dreamoon Likes Coloring
// Contest : Codeforces Round #631 (Div. 1) - Thanks, Denis aramis Shitov!
// URL : https://codeforces.com/contest/1329/problem/0
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int ans[100005];
long long temp[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	long long sum = 0;
	for(int i = 1; i<=M; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum < N){
		cout << -1 << "\n";
		return 0;
	}
	/*
	int lim = N+1;
	for(int i = 1; i<=M; i++){
		ans[arr[i].second] = lim - arr[i].first;
		lim--;
	}
	if(ans[arr[M].second] <= 0){
		cout << -1 << "\n";
	}
	int lst = 1;
	for(int i = M; i; i--){
		if(lst >= ans[arr[i].second]){
			break;
		}
		ans[arr[i].second] = lst;
		lst += arr[i].first;
	}
	*/
	int lst = 0;
	for(int i = M; i; i--){
		int endpt = lst+1;
		if(endpt - arr[i] + 1 <= 0){
			ans[i] = 1;
		}
		else{
			ans[i] = endpt - arr[i] + 1;
		}
		lst = ans[i] + arr[i] - 1;
		temp[i] = lst;
	}
	if(lst > N){
		cout << -1 << "\n";
		return 0;
	}
	/*	
	for(int i = 1; i<=M; i++){
		cout << ans[i] << " ";
	}
	*/
	if(lst != N){
		ans[1] = N - arr[1] + 1;
		for(int i = 2; i<=M; i++){
			if(temp[i] >= ans[i-1]){
				break;
			}
			ans[i] = max(1, ans[i-1] - arr[i]);
		}
	}
	for(int i = 1; i<=M; i++){
		cout << ans[i] << " ";
	}
}