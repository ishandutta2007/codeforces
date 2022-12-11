
// Problem : B. Invariance of Tree
// Contest : Codeforces - Codeforces Round #319 (Div. 1)
// URL : https://codeforces.com/contest/576/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
bool done[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int rt = 0;
	set<pair<int, int>> ans;	
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(!rt && arr[i] == i){
			rt = i;
			done[i] = 1;
		}
	}
	for(int i= 1; !rt && i<=N; i++){
		if(i == arr[arr[i]]){
			rt = i;
			done[i] = 1;
			done[arr[i]] = 1;
			ans.insert(make_pair(i, arr[i]));
		}
	}
	if(!rt){
		cout << "NO\n";
		return 0;
	}
	for(int i = 1; i<=N; i++){
		int n = i, c = rt;
		while(!done[n]){
			ans.insert(make_pair(c, n));
			c = arr[c];
			done[n] = 1;
			n = arr[n];
		}
	}
	for(auto p : ans){
		if(!ans.count(make_pair(arr[p.first], arr[p.second])) && !ans.count(make_pair(arr[p.second], arr[p.first]))){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}