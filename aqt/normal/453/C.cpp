
// Problem : C. Little Pony and Summer Sun Celebration
// Contest : Codeforces - Codeforces Round #259 (Div. 1)
// URL : https://codeforces.com/problemset/problem/453/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[100005];
bool bad[100005];
vector<int> ans;
bool vis[100005];

void dfs(int n){
	vis[n] = 1;
	bad[n] ^= 1;
	ans.push_back(n);
	for(int e : graph[n]){
		if(!vis[e]){
			dfs(e);
			bad[n] ^= 1;
			ans.push_back(n);
			if(bad[e]){
				ans.push_back(e);
				ans.push_back(n);
				bad[n] ^= 1;
				bad[e] ^= 1;
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i<=N; i++){
		cin >> bad[i];
	}
	for(int i = 1; i<=N; i++){
		if(bad[i]){
			dfs(i);
			if(bad[i]){
				ans.pop_back();
				bad[i] = 0;
			}
			break;
		}
	}
	for(int i = 1; i<=N; i++){
		if(bad[i]){
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}