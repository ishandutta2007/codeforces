
// Problem : D. Valera and Swaps
// Contest : Codeforces Round #252 (Div. 2)
// URL : https://codeforces.com/contest/441/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K, C, X;
int arr[3005];
int clr[3005];
vector<pair<int, int>> ans;

void dfs(int n){
	while(clr[n] != C){
		clr[n] = C;
		n = arr[n];
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	cin >> K;
	K = N-K;
	for(int i= 1; i<=N; i++){
		if(!clr[i]){
			C++;
			dfs(i);
		}
	}
	X = C;
	for(int i= 1; i<=N; i++){
		for(int j = i+1; j<=N; j++){
			if(X < K && clr[i] == clr[j]){
				ans.push_back({i, j});
				swap(arr[i], arr[j]);
				C++;
				dfs(i);
				C++;
				dfs(j);
				X++;
			}
			if(X > K && clr[i] != clr[j]){
				ans.push_back({i, j});
				swap(arr[i], arr[j]);
				C++;
				dfs(i);
				X--;
			}
		}
	}
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << " ";
	}	
}