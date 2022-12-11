#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
// Problem : D. You Are Given a Tree
// Contest : Codeforces - Codeforces Round #507 (Div. 1, based on Olympiad of Metropolises)
// URL : https://codeforces.com/contest/1039/problem/D
// Memory Limit : 512 MB
// Time Limit : 7000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const int B = 700;
vector<int> graph[100005];
int par[100005];
pair<int, int> dp[100005];
int ans[100005];
int ord[100005], idx;

inline void dfs(int n){
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs(e);
		}
	}
	if(n != 1){
		graph[n].erase(find(graph[n].begin(), graph[n].end(), par[n]));
	}
	ord[++idx] = n;
}

inline void solve(int k){
	if(ans[k] != -1){
		dp[1].first = ans[k];
		return;
	}
	for(int i = 1; i<=N; i++){
		const int n = ord[i];
		int mx1 = 0, mx2 = 0, tot = 0;
		for(int e : graph[n]){
			tot += dp[e].first;
			if(dp[e].second >= mx1){
				mx2 = mx1;
				mx1 = dp[e].second;
			}
			else if(dp[e].second > mx2){
				mx2 = dp[e].second;
			}
		}
		mx1++;
		if(mx1+mx2 >= k){
			tot++;
			mx1 = 0;
		}
		dp[n].first = tot;
		dp[n].second = mx1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1 ; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	fill(ans+1, ans+1+N, -1);
	dfs(1);
	for(int i= 1; i<=B; i++){
		solve(i);
		ans[i] = dp[1].first;
	}
	for(int i = B+1; i<=N; ){
		solve(i);
		int k = dp[1].first;
		int l = i, r = N, j = i;
		while(l <= r){
			int mid = l+r>>1;
			solve(mid);
			if(dp[1].first == k){
				l = mid + 1;
				j = mid;
			}
			else{
				r = mid - 1;
			}
		}
		do{
			ans[i] = k;
		}
		while(++i <= j);
	}
	for(int i = 1; i<=N; i++){
		cout << ans[i] << "\n";
	}
}