
// Problem : F. Ehab's Last Theorem
// Contest : Codeforces Round #628 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1325/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, S;
vector<int> graph[100005];
int dep[100005];
int par[100005];
bool vis[100005];
vector<int> st[100005];

void dfs(int n){
	vis[n] = 1;
	st[dep[n]%(S-1)].push_back(n);
	for(int e : graph[n]){
		if(par[n] != e && !vis[e]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
		else if(vis[e]){
			if(dep[n] - dep[e] + 1 >= S){
				cout << 2 << "\n";
				cout << dep[n] - dep[e] + 1 << "\n";
				while(true){
					cout << n << " ";
					if(n == e){
						exit(0);
					}
					n= par[n];
				}
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	S = sqrt(N);
	if(S*S != N){
		S++;
	}
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	dfs(1);
	for(int k = 0; k<S; k++){
		if(st[k].size() >= S){
			cout << 1 << "\n";
			while(S--){
				cout << st[k].back() << " ";
				st[k].pop_back();
			}
			return 0;
		}
	}
}