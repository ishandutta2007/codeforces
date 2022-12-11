
// Problem : A. Timetable
// Contest : Codeforces - Codeforces Round #507 (Div. 1, based on Olympiad of Metropolises)
// URL : https://codeforces.com/problemset/problem/1039/A
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long T;
long long arr[200005], x[200005];
long long mn[200005], mx[200005];
long long ans[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for(int i= 1; i<=N; i++){
		cin >> arr[i];
		mn[i] = arr[i] + T;
		mx[i] = 3e18;
	}
	for(int i = 1; i<=N; i++){
		cin >> x[i];
		if(x[i] < i){
			cout << "No\n";
			return 0;
		}
		if(x[i] != N){
			mx[x[i]] = arr[x[i]+1] + T;
		}
		if(x[i] > i){
			mn[i] = arr[i+1] + T;
		}
	}
	for(int i = 1; i<=N; i++){
		ans[i] = max(ans[i-1] + 1, mn[i]);
		if(ans[i] >= mx[i]){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for(int i = 1; i<=N; i++){
		cout << ans[i] << " ";
	}
}