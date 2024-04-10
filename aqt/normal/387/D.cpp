
// Problem : D. George and Interesting Graph
// Contest : Codeforces - Codeforces Round #227 (Div. 2)
// URL : https://codeforces.com/contest/387/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
bool graph[1005][1005];
int lvl[1005];
int ptr[1005];
vector<pair<int, int>> edges;
vector<int> vec[1005];

bool bfs(){
	queue<int> qu;
	qu.push(0);
	fill(lvl, lvl+2*N+2, INT_MAX/2);
	lvl[0] = 0;
	while(qu.size()){
		int n = qu.front();
		//cout << "bfs: " << n << "\n";
		qu.pop();
		for(int e : vec[n]){
			if(graph[n][e] && lvl[e] > lvl[n] + 1){
				lvl[e] = lvl[n] + 1;
				qu.push(e);
			}
		}
	}
	return lvl[2*N+1] < INT_MAX/2;
}

bool dfs(int n){
	//cout << n << "\n";
	if(n == 2*N+1){
		return 1;
	}
	for(int &i = ptr[n]; i<vec[n].size(); i++){
		int e = vec[n][i];
		if(graph[n][e] && lvl[e] > lvl[n]){
			bool k = dfs(e);
			if(!k){
				continue;
			}
			graph[n][e] = 0;
			graph[e][n] = 1;
			return 1;
		}
	}
	return 0;
}

int dinic(){
	int ret = 0;
	while(bfs()){
		fill(ptr, ptr+2*N+2, 0);
		while(dfs(0)){
			ret++;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		edges.emplace_back(a, b);
	}	
	int ans = INT_MAX;
	for(int c = 1; c<=N; c++){
		for(int i = 1; i<=N; i++){
			vec[0].emplace_back(i);
			vec[i].emplace_back(0);
			vec[i+N].emplace_back(2*N+1);
			vec[2*N+1].emplace_back(i+N);
			graph[0][i] = 1;
			graph[i+N][2*N+1] = 1;
			graph[i][0] = 0;
			graph[2*N+1][i+N] = 0;
		}
		int tot = 2*N-1;
		int bad = 0;
		for(auto e : edges){
			if(e.first == c || e.second == c){
				tot--;
			}
			else{
				bad++;
				graph[e.first][e.second+N] = 1;
				vec[e.first].emplace_back(e.second+N);
				vec[e.second+N].emplace_back(e.first);
			}
		}
		int k = dinic();
		//cout << c << " " << k << "\n";
		tot += N-1 - 2*k + bad;
		for(auto e : edges){
			graph[e.first][e.second+N] = 0;
			graph[e.second+N][e.first] = 0;
		}
		for(int i = 0; i<=2*N+1; i++){
			vec[i].clear();
		}
		ans = min(ans, tot);
	}
	cout << ans;
}