
// Problem : G. Double Tree
// Contest : Codeforces - Educational Codeforces Round 62 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1140/G
// Memory Limit : 1024 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<pair<int, long long>> graph[600005];
vector<int> tree[300005];
bool vis[300005];
int sz[300005];
long long dist[2][20][600005];
int lvl[300005];
int cent[20][300005];
int par[300005];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dfs(int n){
	sz[n] = 1;
	for(int e : tree[n]){
		if(!vis[e] && e != par[n]){
			par[e] = n;
			dfs(e);
			sz[n] += sz[e];
		}
	}
}

void dijkstra(int s, int l){
	dist[s&1][l][s] = 0;
	pq.push(make_pair(0LL, s));
	while(pq.size()){
		auto p = pq.top();
		pq.pop();
		if(dist[s&1][l][p.second] < p.first){
			continue;
		}
		int n = p.second;
		cent[l][(n+1)/2] = (s+1)/2;
		for(auto e : graph[n]){
			if(!vis[(e.first+1)/2] && dist[s&1][l][e.first] > dist[s&1][l][n] + e.second){
				dist[s&1][l][e.first] = dist[s&1][l][n] + e.second;
				pq.push(make_pair(dist[s&1][l][e.first], e.first));
			}
		}
	}
}

void solve(int n, int l){
	par[n] = 0;
	dfs(n);
	int S = sz[n];
	while(1){
		int hvy = 0;
		for(int e : tree[n]){
			if(e != par[n] && !vis[e]){
				hvy = (sz[hvy] > sz[e] ? hvy : e);
			}
		}
		if(sz[hvy]*2 > S){
			n = hvy;
		}
		else{
			break;
		}
	}
	lvl[n] = l;
	dijkstra(2*n-1, l);
	dijkstra(2*n, l);
	vis[n] = 1;
	for(int e : tree[n]){
		if(!vis[e]){
			solve(e, l+1);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		long long w;
		cin >> w;
		graph[2*i-1].emplace_back(2*i, w);
		graph[2*i].emplace_back(2*i-1, w);
	}
	for(int i = 1; i<N; i++){
		int x, y;
		long long w, v;
		cin >> x >> y >> w >> v;
		graph[2*x-1].emplace_back(2*y-1, w);
		graph[2*y-1].emplace_back(2*x-1, w);
		graph[2*x].emplace_back(2*y, v);
		graph[2*y].emplace_back(2*x, v);
		tree[x].emplace_back(y);
		tree[y].emplace_back(x);
	}
	for(int l = 0; l<20; l++){
		for(int n = 1; n<=2*N; n++){
			dist[0][l][n] = dist[1][l][n] = LLONG_MAX/3;
		}
	}
	solve(1, 1);
	cin >> Q;
	while(Q--){
		int u, v;
		cin >> u >> v;
		int a = (u+1)/2, b = (v+1)/2;
		long long ans = LLONG_MAX;
		for(int d = min(lvl[a], lvl[b]); d; d--){
			if(cent[d][a] == cent[d][b]){
				ans = min(ans, dist[0][d][u] + dist[0][d][v]);
				ans = min(ans, dist[1][d][u] + dist[1][d][v]);
			}
		}
		cout << ans << "\n";
	}
}