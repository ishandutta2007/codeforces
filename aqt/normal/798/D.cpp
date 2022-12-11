
// Problem : D. Mike and distribution
// Contest : Codeforces - Codeforces Round #410 (Div. 2)
// URL : https://codeforces.com/contest/798/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<pair<int, int>, int> arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first.first;
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first.second;
		arr[i].second = i;
	}
	sort(arr+1, arr+1+N, greater<pair<pair<int, int>, int>>());
	vector<int> ans;
	ans.push_back(arr[1].second);
	for(int i = 2; i<=N; i+=2){
		if(arr[i].first.second >= arr[i+1].first.second){
			ans.push_back(arr[i].second);
		}
		else{
			ans.push_back(arr[i+1].second);
		}
	}
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}