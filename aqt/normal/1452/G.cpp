
// Problem : G. Game On Tree
// Contest : Codeforces - Educational Codeforces Round 98 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1452/G
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
vector<pair<int, int>> lst[200005];
int bdist[200005];
int dist[20][200005]; 
int cent[20][200005];
bool vis[200005];
int par[200005];
int sz[200005];
int hvy[200005];
int sp[200005];
int cdep[200005];

void bfs(){
	queue<int> qu;
	fill(bdist+1, bdist+1+N, INT_MAX/2);
	for(int k = 1; k<=K; k++){
		qu.push(sp[k]);
		bdist[sp[k]] = 0;
	}
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int e : graph[n]){
			if(bdist[e] > bdist[n] + 1){
				bdist[e] = bdist[n] + 1;
				qu.push(e);
			}
		}
	}
}

void dfs1(int n){
	sz[n] = 1;
	hvy[n] = 0;
	for(int e : graph[n]){
		if(!vis[e] && e != par[n]){
			par[e] = n;
			dfs1(e);
			sz[n] += sz[e];
			hvy[n] = sz[hvy[n]] > sz[e] ? hvy[n] : e;
		}
	}
}

void dfs2(int n, int c, int lvl){
	lst[c].emplace_back(bdist[n] - dist[lvl][n] - 1, bdist[n]);
	//cout << c << " " << n << " " << bdist[n]-dist[lvl][n] << " " << bdist[n] << "\n";
	cent[lvl][n] = c;
	for(int e : graph[n]){
		if(par[n] != e && !vis[e]){
			par[e] = n;
			dist[lvl][e] = dist[lvl][n] + 1;
			dfs2(e, c, lvl);
		}
	}
}

void build(int n, int lvl){
	par[n] = 0;
	dfs1(n);
	int S = sz[n];
	while(sz[hvy[n]]*2 > S){
		n = hvy[n];
	}
	par[n] = 0;
	vis[n] = 1;
	dist[lvl][n] = 0;
	cdep[n] = lvl;
	dfs2(n, n, lvl);
	//cout << n << " " << lvl << "\n";
	vector<pair<int, int>> v;
	sort(lst[n].begin(), lst[n].end());
	for(auto p : lst[n]){
		while(v.size() && v.back().second <= p.second){
			v.pop_back();
		}
		v.push_back(p);
	}
	lst[n] = v;
	for(int e : graph[n]){
		if(!vis[e]){
			build(e, lvl+1);
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
	memset(dist, 0x3f, sizeof dist);
	cin >> K;
	for(int i = 1; i<=K; i++){
		cin >> sp[i];
	}
	bfs();
	build(1, 1);
	for(int n = 1; n<=N; n++){
		int ans = 0;
		for(int d = cdep[n]; d; d--){
			auto p = lower_bound(lst[cent[d][n]].begin(), lst[cent[d][n]].end(), make_pair(dist[d][n], 0));
			if(p != lst[cent[d][n]].end()){
				ans = max(ans, (*p).second);
			}
		}
		cout << ans << " ";
	}
}