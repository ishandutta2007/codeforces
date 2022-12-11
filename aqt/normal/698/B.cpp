
// Problem : B. Fix a Tree
// Contest : Codeforces - Codeforces Round #363 (Div. 1)
// URL : https://codeforces.com/contest/698/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, R;
int arr[200005];
int brr[200005];
bool incyc[200005], vis[200005];

void dfs(int n){
	incyc[n] = vis[n] = 1;
	if(incyc[arr[n]]){
		if(!R){
			brr[n] = n;
			R = n;
		} 
		else{
			brr[n] = R;
		}
		incyc[n] = 0;
		return;
	}
	brr[n] = arr[n];
	if(!vis[arr[n]]){
		dfs(arr[n]);
	}
	incyc[n] = 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(i == arr[i]){
			R = i;
		}		
	}
	for(int i = 1; i<=N; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	int ans = 0;
	for(int i = 1; i<=N; i++){
		ans += (arr[i] != brr[i]);
	}
	cout << ans << "\n";
	for(int i = 1; i<=N; i++){
		cout << brr[i] << " ";
	}
}