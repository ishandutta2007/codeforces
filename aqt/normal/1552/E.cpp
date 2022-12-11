
// Problem : E. Colors and Intervals
// Contest : Codeforces - Codeforces Global Round 15
// URL : https://codeforces.com/contest/1552/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int cnt[105 * 105];
int lst[105];
bool have[105];
pair<int, int> ans[105];
int arr[105 * 105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i <= N * K; i++){
		cin >> arr[i];
		if(!have[arr[i]] && lst[arr[i]]){
			int mx = 0;
			for(int j = lst[arr[i]]; j <= i; j++){
				mx = max(mx, cnt[j]);
			}
			if(mx < (N + K - 2) / (K - 1)){
				for(int j = lst[arr[i]]; j <= i; j++){
					cnt[j]++;
				}
				ans[arr[i]] = make_pair(lst[arr[i]], i);
				have[arr[i]] = 1;
			}
		}
		lst[arr[i]] = i;
	}
	for(auto p : ans){
		if(p.first){
			cout << p.first << " " << p.second << "\n";
		}
	} 
}