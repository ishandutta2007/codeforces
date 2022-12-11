
// Problem : D. Kuroni and the Celebration
// Contest : Codeforces - Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)
// URL : https://codeforces.com/problemset/problem/1305/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[1005];
bool vis[1005];
int par[1005];
int dgr[1005];
int sz[1005];

void dfs(int n){
	sz[n] = 1;
	dgr[n] = 0;
	for(int e : graph[n]){
		if(e != par[n] && !vis[e]){
			par[e] = n;
			dfs(e);
			sz[n] += sz[e];
			dgr[n]++;
			dgr[e]++;
		}
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
	int c = 1;
	while(1){
		par[c] = 0;
		dfs(c);
		if(!dgr[c]){
			cout << "! " << c << endl;
			return 0;
		}
		int opt = 0;
		for(int n = 1; n<=N; n++){
			if(dgr[n] == 1 && !vis[n]){
				if(opt){
					cout << "? " << n << " " << opt << endl;
					cin >> c;
					if(c == n || c == opt){
						cout << "! " << c << endl;
						return 0;
					}
					vis[n] = vis[opt] = 1;
					break;
				}
				else{
					opt = n;
				}
			}
		}
	}
}