
// Problem : E. Fox And Dinner
// Contest : Codeforces - Codeforces Round #290 (Div. 2)
// URL : https://codeforces.com/problemset/problem/510/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[205];
int u[100005], v[100005], f[100005];
int lvl[205], ptr[205];
bool vis[205];
vector<int> graph[205];
vector<int> cgraph[205];
vector<vector<int>> vec;

void addedge(int a, int b, int k){
	u[K] = a;
	v[K] = b;
	u[K^1] = b;
	v[K^1] = a;
	f[K] = k;
	graph[a].push_back(K);
	graph[b].push_back(K^1);
	K+=2;
}

bool bfs(){
	queue<int> qu;
	qu.push(0);
	fill(lvl, lvl+N+2, 0);
	lvl[0] = 1;
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int e : graph[n]){
			if(f[e] && !lvl[v[e]]){
				lvl[v[e]] = lvl[u[e]] + 1;
				qu.push(v[e]);
			}
		}
	}
	return lvl[N+1];
}

int dfs(int n, int p){
	//cout << n << " " << p << endl;
	if(n == N+1 || !p){
		return p;
	}
	//cout << "hi" << endl;
	for(int &i = ptr[n]; i<graph[n].size(); i++){
		int e = graph[n][i];
		if(f[e] && lvl[v[e]] > lvl[n]){
			//cout << u[e] << " " << v[e] << endl;
			int k = dfs(v[e], min(f[e], p));
			if(!k){
				continue;
			}
			f[e] -= k;
			f[e^1] += k;
			return k;
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		if(arr[i]%2 == 1){
			addedge(0, i, 2);
		}
		else{
			addedge(i, N+1, 2);
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			if(arr[i]%2 == 1 && arr[j]%2 == 0){
				bool isp = 1;
				for(int k = 2; k<=sqrt(arr[i]+arr[j]); k++){
					if((arr[i]+arr[j])%k == 0){
						isp = 0;
						break;
					}
				}
				if(isp){
					addedge(i, j, 1);
				}
			}
		}
	}
	int ans = 0;
	while(1){
		if(!bfs()){
			break;
		}
		fill(ptr, ptr+2+N, 0);
		int p;
		while((p = dfs(0, INT_MAX/2))){
			ans += p;
		}
	}
	if(ans != N){
		cout << "Impossible\n";
		return 0;		
	}
	for(int e = 1; e<K; e+=2){
		if(f[e] && u[e] != 0 && v[e] != 0 && u[e] != N+1 && v[e] != N+1){
			cgraph[v[e]].push_back(u[e]);
			cgraph[u[e]].push_back(v[e]);
		}
	}
	for(int n = 1; n<=N; n++){
		if(!vis[n]){
			int c = n;
			vector<int> temp;
			while(!vis[c]){
				temp.push_back(c);
				vis[c] = 1;
				for(int e : cgraph[c]){
					if(!vis[e]){
						c = e;
					}
				}
			}
			vec.push_back(temp);
		}
	}
	cout << vec.size() << "\n";
	for(auto k : vec){
		cout << k.size() << " ";
		for(int n : k){
			cout << n << " ";
		}
		cout << "\n";
	}
}