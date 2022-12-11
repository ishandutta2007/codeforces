
// Problem : E. Pairs of Pairs
// Contest : Codeforces - Codeforces Round #663 (Div. 2)
// URL : https://codeforces.com/contest/1391/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
vector<int> graph[500005];
vector<int> lst[500005];
int dep[500005];
int par[500005];
bool vis[500005];

void dfs(int n){
	lst[dep[n]].push_back(n);
	vis[n] = 1;
	for(int e : graph[n]){
		if(!vis[e]){
			dep[e] = dep[n] + 1;
			par[e] = n;
			dfs(e);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			lst[i].clear();
			graph[i].clear();
			vis[i] = 0;
		}
		for(int i = 1; i<=M; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dep[1] = 1;
		dfs(1);
		int lim = (N+1)/2;
		bool done = 0;
		for(int i = 1; i<=N; i++){
			if(dep[i] >= lim){
				vector<int> path;
				int c = i;
				while(c){
					path.push_back(c);
					c = par[c];
				}
				cout << "PATH\n";
				cout << path.size() << "\n";
				for(int n : path){
					cout << n << " ";
				}
				cout << "\n";
				done = 1;
				break;
			}
		}
		if(done){
			continue;
		}
		cout << "PAIRING\n";
		vector<pair<int, int>> out;
		for(int i = 1; i<=lim; i++){
			for(int j = 1; j<lst[i].size(); j+=2){
				out.emplace_back(lst[i][j-1], lst[i][j]);
			}
		}
		cout << out.size() << "\n";
		for(auto p : out){
			cout << p.first << " " << p.second << "\n";
		}
	}
}