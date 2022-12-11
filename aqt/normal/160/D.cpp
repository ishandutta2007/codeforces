
// Problem : D. Edges in MST
// Contest : Codeforces - Codeforces Round #111 (Div. 2)
// URL : https://codeforces.com/contest/160/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> edges[1000005];
vector<int> graph[100005];
int dsu[100005];
int u[100005], v[100005];
int ans[100005];
int dfn[100005], low[100005], t;

inline int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

inline void dfs(int n, int p){
	dfn[n] = low[n] = ++t;
	for(int e : graph[n]){
		if(e == p){
			continue;
		}
		if(v[e] == n){
			swap(u[e], v[e]);
		}
		if(!dfn[v[e]]){
			dfs(v[e], e);
		}
		low[n] = min(low[n], low[v[e]]);		
	}
	if(dfn[n] == low[n]){
		ans[p] = 3;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edges[c].emplace_back(i);
		u[i] = a, v[i] = b;
	}
	for(int i = 1; i<=N; i++){
		dsu[i] = i;
	}
	for(int k = 1; k<=1000000; k++){
		for(int e : edges[k]){
			u[e] = getrt(u[e]), v[e] = getrt(v[e]);
			if(u[e] == v[e]){
				ans[e] = 1;
			}
			else{
				int x = u[e], y = v[e];
				graph[x].emplace_back(e);
				graph[y].emplace_back(e);
				dfn[x] = dfn[y] = 0;
				low[x] = low[y] = 0;
			}
		}
		t = 0;
		for(int e : edges[k]){
			if(!dfn[u[e]]){
				dfs(u[e], 0);
			}
		}
		for(int e : edges[k]){
			if(!ans[e]){
				ans[e] = 2;
			}
			if(getrt(u[e]) != getrt(v[e])){
				dsu[getrt(u[e])] = getrt(v[e]);
			}
			graph[u[e]].clear();
			graph[v[e]].clear();
		}
	}
	for(int i = 1; i<=M; i++){
		if(ans[i] == 1){
			cout << "none\n";
		}
		else if(ans[i] == 2){
			cout << "at least one\n";
		}
		else{
			cout << "any\n";
		}
	}
}