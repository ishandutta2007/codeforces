
// Problem : G. Two-Paths
// Contest : Codeforces - Educational Codeforces Round 46 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1000/problem/G
// Memory Limit : 256 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long arr[300005];
vector<pair<int, long long>> graph[300005];
long long dp1[300005], dp2[300005];
int par[20][300005];
long long tbl[20][300005];
int dep[300005];

void dfs1(int n){
	dp1[n] = arr[n];
	for(auto e : graph[n]){
		if(e.first != par[0][n]){
			par[0][e.first] = n;
			dep[e.first] = dep[n] + 1;
			dfs1(e.first);
			dp1[n] += max(0LL, dp1[e.first] - 2*e.second);
		}
	}
}

void dfs2(int n){
	for(auto e : graph[n]){
		if(e.first != par[0][n]){
			dp2[e.first] = dp2[n] + dp1[n] - max(0LL, dp1[e.first] - 2*e.second);
			dp2[e.first] = max(0LL, dp2[e.first] - 2*e.second);
			dfs2(e.first);
			tbl[0][e.first] = dp1[e.first] - e.second;
			tbl[0][e.first] -= max(0LL, dp1[e.first] - 2*e.second);
		}
	}	
}

long long query(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	long long tot = 0;
	for(int d = 19; d>=0; d--){
		if(dep[par[d][u]] >= dep[v]){
			tot += tbl[d][u];
			u = par[d][u];
		}
	}
	if(u == v){
		return tot + dp1[u] + dp2[u];
	}
	for(int d = 19; d>=0; d--){
		if(par[d][u] != par[d][v]){
			tot += tbl[d][v];
			tot += tbl[d][u];
			u = par[d][u];
			v = par[d][v];
		}
	}
	tot += tbl[0][u];
	tot += tbl[0][v];
	u = par[0][u];
	return tot + dp1[u] + dp2[u];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<N; i++){
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	dep[1] = 1;
	dfs1(1);
	dfs2(1);
	for(int d = 1; d<20; d++){
		for(int n = 1; n<=N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
			tbl[d][n] = tbl[d-1][n] + tbl[d-1][par[d-1][n]];
		}
	}
	while(Q--){
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << "\n";
	}
}