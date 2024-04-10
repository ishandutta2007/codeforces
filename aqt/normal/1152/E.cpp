
// Problem : E. Neko and Flashback
// Contest : Codeforces - Codeforces Round #554 (Div. 2)
// URL : https://codeforces.com/contest/1152/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
map<int, vector<pair<int, int>>> graph;
int mn[100005];
int mx[100005];
bool tkn[100005];
vector<int> ans;
vector<int> out;

void dfs(int n){
	while(graph[n].size()){
		auto p = graph[n].back();
		graph[n].pop_back();
		if(!tkn[p.second]){
			tkn[p.second] = 1;
			dfs(p.first);
			ans.push_back(p.second);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1 ; i<N; i++){
		cin >> mn[i];
	}	
	for(int i = 1; i<N; i++){
		cin >> mx[i];
		if(mx[i] < mn[i]){
			cout << -1;
			return 0;
		}
		graph[mn[i]].emplace_back(mx[i], i);
		graph[mx[i]].emplace_back(mn[i], i);
	}
	int st = 0, ed = 0;
	for(auto e : graph){
		if(e.second.size()%2 == 1){
			if(ed){
				cout << -1;
				return 0;
			}
			else if(st){
				ed = e.first;
			}
			else{
				st = e.first;
			}
		}
	}
	if(st){
		graph[st].emplace_back(ed, 0);
		graph[ed].emplace_back(st, 0);
		dfs(st);
		if(ans.size() != N){
			cout << -1 << "\n";
			return 0;
		}
		rotate(ans.begin(), find(ans.begin(), ans.end(), 0), ans.end());
		ans.erase(ans.begin(), ans.begin()+1);
		out.push_back(st);
	}
	else{
		dfs(mn[1]);
		if(ans.size() != N-1){
			cout << -1 << "\n";
			return 0;
		}
		out.push_back(mn[1]);
	}
	for(int i = 0; i<ans.size(); i++){
		if(out.back() == mn[ans[i]]){
			out.push_back(mx[ans[i]]);
		}
		else{
			out.push_back(mn[ans[i]]);
		}
	}
	for(int n : out){
		cout << n << " ";
	}
}