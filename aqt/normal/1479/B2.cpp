
// Problem : B2. Painting the Array II
// Contest : Codeforces - Codeforces Round #700 (Div. 1)
// URL : https://codeforces.com/contest/1479/problem/B2
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100005];
int dp[100005];
int mn[100005];
vector<int> pos[100005];

int getnxt(int k, int v){
	auto ptr = upper_bound(pos[v].begin(), pos[v].end(), k);
	if(ptr == pos[v].end()){
		return N + 1;
	}
	else{
		return *ptr;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/*
	cin >> N;
	for(int i = 1; i <= N; i++){
		int n;
		cin >> n;
		arr.emplace_back(n);
	}
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	N = arr.size();
	fill(mn + 1, mn + 1 + N, INT_MAX / 2);
	int globalmn = 0;
	for(int i = 1; i <= N; i++){
		int n = arr[i - 1];
		dp[i] = INT_MAX / 2;
		dp[i] = min(dp[i], globalmn + i);
		dp[i] = min(dp[i], mn[n] + i - 1);
		mn[n] = min(dp[i] - i, mn[n]);
		globalmn = min(globalmn, dp[i] - i);
	}
	cout << dp[N];
	*/
	cin >> N;
	for(int i = 1; i <= N; i++){
		int n;
		cin >> n;
		arr[i] = n;
		pos[arr[i]].push_back(i);
	}
	pair<int, int> bst;
	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(arr[i] == bst.first || arr[i] == bst.second){
			
		}
		else if(getnxt(i, bst.first) > getnxt(i, bst.second)){
			bst.first = arr[i];
			ans++;
		}
		else{
			bst.second = arr[i];
			ans++;
		}
	}
	cout << ans;
}