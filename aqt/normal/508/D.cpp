
// Problem : D. Tanya and Password
// Contest : Codeforces - Codeforces Round #288 (Div. 2)
// URL : https://codeforces.com/contest/508/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
map<string, vector<string>> graph;
map<string, int> indgr, outdgr;
vector<string> ans;
set<string> st;

void dfs(string n){
	while(graph[n].size()){
		auto k = graph[n].back();
		graph[n].pop_back();
		dfs(k);
	}
	ans.push_back(n);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		string s;
		cin >> s;
		graph[s.substr(0, 2)].emplace_back(s.substr(1, 2));
		outdgr[s.substr(0, 2)]++, indgr[s.substr(1, 2)]++;
		st.insert(s.substr(0, 2)), st.insert(s.substr(1, 2));
	}
	string beg="", ed ="";
	for(auto s : st){
		if(indgr[s] == outdgr[s]){
			
		}
		else if(indgr[s]+1 == outdgr[s]){
			if(beg.size()){
				cout << "NO\n";
				return 0;
			}
			beg = s;
		}
		else if(indgr[s] == outdgr[s]+1){
			if(ed.size()){
				cout << "NO\n";
				return 0;
			}
			ed = s;
		}
		else{
			cout << "NO\n";
			return 0;
		}
	}
	if(!beg.size()){
		beg = ed = *st.begin();
	}
	graph[ed].push_back(beg);
	dfs(beg);
	for(auto s : st){
		if(graph[s].size()){
			cout << "NO\n";
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	ans.pop_back();
	for(int n = 0; n<ans.size(); n++){
		if(ans[n] == ed && ans[n+1] == beg){
			cout << "YES\n";
			cout << beg[0];
			for(int i = n+1; i != n; i = (i + 1)%ans.size()){
				cout << ans[i][1];
			}
			cout << ed[1];
			break;
		}
	}
}