
// Problem : G. Shortest Path Problem?
// Contest : Educational Codeforces Round 27
// URL : https://codeforces.com/contest/845/problem/G
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int basis[50];
vector<pair<int, int>> graph[100005];
bool vis[100005];
int dist[100005];
int u[100005], v[100005], x[100005];

void dfs(int n){
	vis[n] = 1;
	for(auto e : graph[n]){
		if(!vis[e.first]){
			dist[e.first] = dist[n] ^ e.second;
			dfs(e.first);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
		u[i] = a, v[i] = b, x[i] = c;
	}
	dfs(1);
	for(int i = 1; i<=M; i++){
		int k = dist[u[i]] ^ dist[v[i]] ^ x[i];
		for(int b = 30; b>=0; b--){
			if(k>>b&1){
				if(!basis[b]){
					basis[b] = k;
				}
				k ^= basis[b];
			}
		}
	}
	int k = dist[N];
	for(int b = 30; b>=0; b--){
		if(k>>b&1){
			k ^= basis[b];
		}
	}
	cout << k;
}