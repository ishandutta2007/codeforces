
// Problem : D. Nastya and Time Machine
// Contest : Codeforces - Codeforces Round #637 (Div. 1) - Thanks, Ivan Belonogov!
// URL : https://codeforces.com/contest/1340/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, D;
vector<int> graph[100005];
bool done[100005];
int t[100005];
vector<pair<int, int>> ans;

void dfs(int n, int p){
	ans.push_back({n, t[n]});
	int c = t[n];
	for(int e : graph[n]){
		if(e != p){
			if(c == D){
				int cnt = 0;
				for(int k : graph[n]){
					if(k != p){
						cnt += !done[k];
					}
				}
				ans.push_back({n, t[n]-cnt-1});
				c = t[n] - cnt - 1;
			}
			t[e] = ++c;
			dfs(e, n);
			ans.push_back({n, c});
		}
	}
	done[n] = 1;
	if(c >= t[n] && n != 1){
		ans.push_back({n, t[n]-1});
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
		D = max(D, (int) (graph[a].size()));
		D = max(D, (int) (graph[b].size()));
	}
	dfs(1, 0);
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}