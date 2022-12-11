
// Problem : C. Data Center Drama
// Contest : Codeforces - Codeforces Round #296 (Div. 1)
// URL : https://codeforces.com/contest/528/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dgr[200005];
bool used[500005];
vector<int> ans;
vector<pair<int, int>> graph[100005];
vector<int> odd;

void dfs(int n){
	while(graph[n].size()){
		auto p  = graph[n].back();
		graph[n].pop_back();
		if(!used[p.second]){
			used[p.second] = 1;
			dfs(p.first);
		}
	}
	ans.push_back(n);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		dgr[a]++, dgr[b]++;
		graph[a].push_back({b, i});
		graph[b].push_back({a, i});
	}
	for(int i = 1; i<=N; i++){
		if(dgr[i]&1){
			odd.push_back(i);
		}
	}
	for(int n = 0; n<odd.size(); n+=2){
		graph[odd[n]].push_back({odd[n+1], ++M});
		graph[odd[n+1]].push_back({odd[n], M});
	}
	dfs(1);
	if(M%2){
		ans.push_back(ans.back());
		M++;
	}
	cout << M << "\n";
	for(int i = 1; i<ans.size(); i+=2){
		cout << ans[i] << " " << ans[i-1] << "\n";
		cout << ans[i] << " " << ans[i+1] << "\n";
	}
}