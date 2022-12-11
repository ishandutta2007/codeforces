
// Problem : E. Graph Coloring
// Contest : Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1354/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int cnt[3];
vector<int> graph[5005];
int ans[5005];
int clr[5005];
bool dp[5005][5005];
int par[5005][5005];
bool vis[5005];
int sz[2][5005];
bool used[5005];
int comp[5005];
int rt[5005];

void dfs1(int n){
	vis[n] = 1;
	comp[n] = K;
	sz[clr[n]][n]++;
	for(int e : graph[n]){
		if(!vis[e]){
			clr[e] = clr[n] ^ 1;
			dfs1(e);
			sz[0][n] += sz[0][e];
			sz[1][n] += sz[1][e];
		}
		else if(clr[e] == clr[n]){
			cout << "NO\n";
			exit(0);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cin >> cnt[0] >> cnt[1] >> cnt[2];
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		if(!vis[i]){
			K++;
			dfs1(i);
			rt[K] = i;
			for(int m = 0; m<=N; m++){
				if(m >= sz[0][i] && dp[K-1][m-sz[0][i]]){
					dp[K][m] = 1;
					par[K][m] = sz[0][i];
				}
				else if(m >= sz[1][i] && dp[K-1][m-sz[1][i]]){
					dp[K][m] = 1;
					par[K][m] = sz[1][i];
				}
			}
		}
	}
	if(dp[K][cnt[1]]){
		int crnt = cnt[1];
		for(int k = K; k; k--){
			if(par[k][crnt] == sz[0][rt[k]]){
				used[k] = 1;
			}
			crnt -= par[k][crnt];
		}
		cout << "YES\n";
		for(int i = 1; i<=N; i++){
			if(used[comp[i]]){
				if(clr[i] == 0){
					cout << 2;
				}
				else if(cnt[0]){
					cout << 1;
					cnt[0]--;
				}
				else{
					cout << 3;
				}
			}
			else{
				if(clr[i] == 1){
					cout << 2;
				}
				else if(cnt[0]){
					cout << 1;
					cnt[0]--;
				}
				else{
					cout << 3;
				}
			}
		}
	}
	else{
		cout << "NO\n";
	}
}