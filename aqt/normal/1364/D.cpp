
// Problem : D. Ehab's Last Corollary
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> graph[100005];
int dep[100005];
int par[100005];
bool vis[100005];
int cnt[2];

void dfs(int n){
	//cout << n << endl;
	vis[n] = 1;
	cnt[dep[n]&1]++;
	for(int e : graph[n]){
		if(!vis[e] && e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	/*
	queue<int> qu;
	qu.push(1);
	while(qu.size()){
		int n = qu.front();
		cnt[dep[n]&1]++;
		qu.pop();
		for(int e : graph[n]){
			if(e != par[n]){
				par[e] = n;
				dep[e] = dep[n] + 1;
				qu.push(n);
			}
		}
	}
	*/
	dfs(1);
	if(M == N-1){
		vector<int> ans;
		if(cnt[0] > cnt[1]){
			for(int n = 1; ans.size() < (K+1)/2; n++){
				if(dep[n]%2 == 0){
					ans.push_back(n);
				}
			}
		}
		else{
			for(int n = 1; ans.size() < (K+1)/2; n++){
				if(dep[n]%2 == 1){
					ans.push_back(n);
				}
			}
		}
		cout << 1 << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		return 0;
	}
	for(int n = 1; n<=N; n++){
		for(int e : graph[n]){
			//cout << par[e] << " "
			if(par[e] == n || par[n] == e){
				continue;
			}
			int x = e, y = n;
			if(dep[x] > dep[y]){
				swap(x, y);				
			}
			//cout << x << " " << y << endl;
			if(dep[y] - dep[x] + 1 <= K){
				vector<int> ans;
				while(1){
					ans.push_back(y);
					if(y == x){
						break;
					}
					y = par[y];
				}
				cout << 2 << "\n";
				cout << ans.size() << "\n";
				for(int n : ans){
					cout << n << " ";
				}
				return 0;
			}
		}
	}
	for(int n = 1; n<=N; n++){
		for(int e : graph[n]){
			if(par[e] == n || par[n] == e){
				continue;
			}
			int x = e, y = n;
			if(dep[x] > dep[y]){
				swap(x, y);				
			}
			vector<int> ans;
			while(ans.size() < (K+1)/2){
				ans.push_back(y);
				y = par[y];
				y = par[y];
			}
			cout << 1 << "\n";
			//cout << ans.size() << "\n";
			for(int n : ans){
				cout << n << " ";
			}
			return 0;
		}
	}
	assert(0);
}