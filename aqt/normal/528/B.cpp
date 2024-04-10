
// Problem : B. Clique Problem
// Contest : Codeforces - Codeforces Round #296 (Div. 1)
// URL : https://codeforces.com/contest/528/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[200005];	

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
		int x = arr[i].first - arr[i].second;
		int y = arr[i].first + arr[i].second;
		arr[i].first = y, arr[i].second = x;
	}
	sort(arr+1, arr+1+N);
	long long lst = -LLONG_MAX/2, ans = 0;
	for(int i = 1; i<=N; i++){
		if(arr[i].second >= lst){
			ans++;
			lst = arr[i].first;
		}
	}
	cout << ans;
}