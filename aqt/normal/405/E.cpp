
// Problem : E. Graph Cutting
// Contest : Codeforces - Codeforces Round #238 (Div. 2)
// URL : https://codeforces.com/contest/405/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[100005];
bool vis[100005];
int a[100005], b[100005];
set<int> st;
vector<pair<int, pair<int, int>>> ans;

void dfs(int n, int p){
	vis[n] = 1;
	vector<int> v;
	for(auto e : graph[n]){
		if(e.second != p && !vis[e.first]){
			dfs(e.first, e.second);
			if(!st.count(e.second)){
				v.push_back(e.second);
			}
		}
		else if(e.second != p && vis[e.first] && !st.count(e.second)){
			v.push_back(e.second);
		}
	}
	while(v.size() >= 2){
		int p = v.back();
		v.pop_back();
		int q = v.back();
		v.pop_back();
		st.insert(p);
		st.insert(q);
		ans.push_back({(a[q] == n ? b[q] : a[q]), {n, (a[p] == n ? b[p] : a[p])}});
	}
	if(v.size()){
		int q = v.back();
		ans.push_back({(a[q] == n ? b[q] : a[q]), {n, (a[p] == n ? b[p] : a[p])}});
		st.insert(p);
		st.insert(q);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		cin >> a[i] >> b[i];		
		graph[a[i]].emplace_back(b[i], i);
		graph[b[i]].emplace_back(a[i], i); 
	}
	if(M&1){
		cout << "No solution\n";
		return 0;
	}
	dfs(1, 0);
	for(auto k : ans){
		cout << k.first << " " << k.second.first << " " << k.second.second << "\n";
	} 
}