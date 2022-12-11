
// Problem : E. One-Way Reform
// Contest : Codeforces - Codeforces Round #375 (Div. 2)
// URL : https://codeforces.com/contest/723/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, idx;
vector<pair<int, int>> graph[205];
bool done[100000];
vector<pair<int, int>> ans;

void dfs(int n){
	while(graph[n].size()){
		auto p = graph[n].back();
		graph[n].pop_back();
		if(done[p.second]){
			continue;
		}
		done[p.second] = 1;
		dfs(p.first);
		if(p.second <= M){
			ans.emplace_back(n, p.first);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> N >> M;
		memset(done, 0, sizeof done);
		for(int i = 1; i<=N; i++){
			graph[i].clear();
		}
		ans.clear();
		for(int i = 1; i<=M; i++){
			int a, b;
			cin >> a >> b;
			graph[a].emplace_back(b, i);
			graph[b].emplace_back(a, i);
		}
		int cnt = 0;
		vector<int> o;
		for(int i = 1; i<=N; i++){
			if(graph[i].size()%2 == 0){
				cnt++;
			}
			else{
				o.push_back(i);
			}
		}
		idx = M;
		for(int i = 0; i<o.size(); i+=2){
			int a = o[i], b = o[i+1];
			graph[a].emplace_back(b, ++idx);
			graph[b].emplace_back(a, idx);
		}
		for(int i = 1; i<=N; i++){
			dfs(i);
		}
		cout << cnt << "\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
	}
}