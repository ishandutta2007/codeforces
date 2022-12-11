
// Problem : D. Almost All
// Contest : Codeforces - Codeforces Round #580 (Div. 1)
// URL : https://codeforces.com/contest/1205/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[1005];
int sz[1005];
int dist[1005];
bool clr[1005];
bool dp[1005][1005];
bool tkn[1005][1005];
int par[1005];
bool st[1005];
vector<int> ord;

void dfs1(int n, int p){
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != p){
			dfs1(e, n);
			sz[n] += sz[e];
		}
	}
}

void dfs2(int n){
	ord.push_back(n);
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs2(e);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(1, 0);
	int C = 0;
	for(int n = 1; n<=N; n++){
		bool iscentroid = N-sz[n] <= N/2;
		for(int e : graph[n]){
			if(sz[e] < sz[n]){
				if(sz[e] > N/2){
					iscentroid = 0;
				}
			}
		}
		if(iscentroid){
			C = n;
			break;
		}
	}
	assert(C);
	for(int e : graph[C]){
		st[e] = 1;
		if(sz[e] > sz[C]){
			sz[e] = N - sz[C];
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		for(int j = 0; j<=(N-1)/2; j++){
			if(dp[i-1][j]){
				dp[i][j] = 1;
				//cout << i << " " << j << "\n";
			}
			else if(st[i] && j >= sz[i] && dp[i-1][j-sz[i]]){
				//cout << i << " " << j << "\n";
				dp[i][j] = 1;
				tkn[i][j] = 1;
			}
		}
	}
	int A = 0;
	for(int k = 0; k<=(N-1)/2; k++){
		if(dp[N][k]){
			A = k;
		}
	}
	int lsti = N, lstj = A;
	while(lsti){
		if(tkn[lsti][lstj]){
			clr[lsti] = 1;
			lstj -= sz[lsti];
		}
		lsti--;
	}
	for(int e : graph[C]){
		if(clr[e]){
			par[e] = C;
			dfs2(e);
		}
	}
	assert(ord.size() == A);
	for(int i = 1; i<=A; i++){
		dist[ord[i-1]] = i;
	}
	ord.clear();
	for(int e : graph[C]){
		if(!clr[e]){
			par[e] = C;
			dfs2(e);
		}
	}
	for(int i = 1; i<=N-1-A; i++){
		dist[ord[i-1]] = i*(A+1);
	}
	for(int n = 1; n<=N; n++){
		if(n != C){
			cout << par[n] << " " << n << " " << dist[n] - dist[par[n]] << "\n";
		}
	}
}