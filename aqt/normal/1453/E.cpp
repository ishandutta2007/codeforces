
// Problem : E. Dog Snacks
// Contest : Codeforces - Codeforces Round #688 (Div. 2)
// URL : https://codeforces.com/contest/1453/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
vector<int> graph[200005];
int dp[200005];
int par[200005];
int dep[200005];

bool dfs(int n, int k){
	//cout << n << " " << k << "\n";
	vector<int> v;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			if(!dfs(e, k)){
				return 0;
			}
			v.push_back(dp[e]);
		}
	}
	sort(v.begin(), v.end());
	dp[n] = dep[n];
	if(v.size()){
		if(v.size() == 1){
			dp[n] = v[0];
		}
		else if(1 + v.back() - dep[n] <= k){
			dp[n] = v[0];
		}
		else if(1 + v[v.size()-2] - dep[n] <= k){
			dp[n] = v.back();
		}
		else{
			return 0;
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int l = 1, r = N, ans = N;
		while(l <= r){
			int mid = l + r >> 1;
			bool b = dfs(1, mid) && (dp[1] <= mid);
			if(b){
				r = mid - 1;
				ans = mid;
			}
			else{
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}