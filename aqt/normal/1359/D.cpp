
// Problem : D. Yet Another Yet Another Task
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/D
// Memory Limit : 512 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int par[100005];
int arr[100005];
unordered_map<int, vector<int>> mp;
bool on[100005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1 ; i<=N; i++){
		par[i] = i;
		cin >> arr[i];
		mp[arr[i]].push_back(i);
	}
	int ans = 0;
	for(int x = -30; x<=30; x++){
		for(int n : mp[x]){
			on[n] = 1;
		}
		int sum = 0;
		for(int i = 1; i<=N; i++){
			if(!on[i]){
				sum = 0;
				continue;
			}
			if(on[i]){
				sum += arr[i];
			}
			ans = max(ans, sum - x);			
			if(sum < 0){
				sum = 0;
			}
		}
	}
	cout << ans << "\n";
}