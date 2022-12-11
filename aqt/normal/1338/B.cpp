
// Problem : B. Edge Weight Assignment
// Contest : Codeforces Round #633 (Div. 1)
// URL : https://codeforces.com/contest/1338/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100005];
int rt;
int dist[100005];
int par[100005];
int cnt[100005];
bool isleaf[100005];

void dfs(int n){
	for(int e : graph[n]){
		if(e == par[n]){
			continue;
		}
		par[e] = n;
		dist[e] = dist[n] + 1;
		dfs(e);
		cnt[n] += isleaf[e];
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i<=N; i++){
		if(graph[i].size() > 1){
			rt = i;
		}
		else{
			isleaf[i] = 1;
		}
	}
	dfs(rt);
	int mn = 0, mx = N-1;
	set<int> st;
	for(int i = 1; i<=N; i++){
		if(cnt[i] >= 2){
			mx -= cnt[i] - 1;
		}
		else if(isleaf[i]){
			st.insert(dist[i]%2);
		}
	}
	if(st.size() == 2){
		mn = 3;
	}
	else{
		mn = 1;
	}
	cout << mn << " " << mx << "\n";
}