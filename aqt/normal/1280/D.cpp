
// Problem : D. Miss Punyverse
// Contest : Codeforces - Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1280/D
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
vector<int> graph[3005];
pair<int, long long> dp[3005][3005];
pair<int, long long> tmp[3005];
int sz[3005];
long long val[3005];

pair<int, long long> operator + (const pair<int, long long> a, const pair<int, long long> b) {
	return {a.first + b.first, a.second+b.second};
}

void dfs(int n, int p){
	//cout << "node: " << n << "\n";
	sz[n] = 1;
	dp[n][0] = {0, val[n]};
	for(int e : graph[n]){
		if(e != p){
			dfs(e, n);
			for(int k = 0; k<sz[n]+sz[e]; k++){
				tmp[k] = {0, LLONG_MIN/2};
			}
			for(int a = 0; a<sz[n]; a++){
				for(int b = 0; b<=sz[e]; b++){
					tmp[a+b] = max(tmp[a+b], dp[e][b] + dp[n][a]);
					//cout << (dp[e][b] + dp[n][a]).second << "\n";
				}
			}
			sz[n] += sz[e];
			for(int k = 0; k<sz[n]; k++){
				dp[n][k] = tmp[k];
			}
		}
	}
	dp[n][sz[n]] = {0, LLONG_MIN/2};
	for(int k = sz[n]-1; k>=0; k--){
		dp[n][k+1] = max(dp[n][k+1], {dp[n][k].first+(dp[n][k].second > 0), 0});
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			cin >> val[i];
			graph[i].clear();
		}	
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			val[i] = n - val[i];
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1, 0);
		//cout << dp[1][M-1].first << " " << dp[1][M-1].second << "\n";
		long long ans = dp[1][M-1].first + (dp[1][M-1].second > 0);
		cout << ans << "\n";
	}
}