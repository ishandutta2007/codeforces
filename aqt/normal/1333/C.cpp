
// Problem : C. Eugene and an array
// Contest : Codeforces Round #632 (Div. 2)
// URL : https://codeforces.com/contest/1333/problem/C
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[200005];
long long pre[200005];
long long dp[200005];
map<long long, int> mp;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i =1 ; i<=N; i++){
		pre[i] = pre[i-1] + arr[i];
	}
	int lst = -1;
	long long ans = 0;
	mp[0] = 0;
	for(int i = 1; i<=N; i++){
		if(mp.count(pre[i])){
			lst = max(lst, mp[pre[i]]);
		}
		ans += i - lst - 1;
		mp[pre[i]] = i;
	}
	cout << ans << "\n";
}