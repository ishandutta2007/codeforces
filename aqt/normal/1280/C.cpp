
// Problem : C. Jeremy Bearimy
// Contest : Codeforces - Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/contest/1280/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<pair<int, int>> graph[200005];
int sz[200005];
long long G, B;

void dfs(int n, int p){
	sz[n] = 1;
	for(auto e : graph[n]){
		if(e.first != p){
			dfs(e.first, n);
			sz[n] += sz[e.first];
			if(sz[e.first]%2 == 1){
				G += e.second;
			}
			B += 1LL * min(N - sz[e.first], sz[e.first]) * e.second; 
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		N *= 2;
		G = B = 0;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
		}
		for(int i = 1; i<N; i++){
			int a, b, t;
			cin >> a >> b >>t;
			graph[a].push_back({b, t});
			graph[b].push_back({a, t});
		}
		dfs(1, 0);
		cout << G << " " << B << "\n";
	}
}