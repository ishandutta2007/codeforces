
// Problem : D. It's a bird! No, it's a plane! No, it's AaParsa!
// Contest : Codeforces - Codeforces Round #722 (Div. 1)
// URL : https://codeforces.com/contest/1528/problem/D
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dist[2][605][605];
vector<pair<int, int>> graph[605];
bool vis[2][605][605];
const int inf = INT_MAX-5;

void dijkstra(int n){
	dist[0][n][n] = 0;
	while(1){
		pair<int, int> idx = make_pair(0, 696969);
		for(int i = 0; i < N; i++){
			if(!vis[0][n][i] && dist[0][n][i] != inf && (idx.second == 696969 || dist[0][n][i] < dist[idx.first][n][idx.second])){
				idx = make_pair(0, i);
			}
			if(!vis[1][n][i] && dist[1][n][i] != inf && (idx.second == 696969 || dist[1][n][i] < dist[idx.first][n][idx.second])){
				idx = make_pair(1, i);
			}
		}
		if(idx.second == 696969){
			break;
		}
		//cout << idx.first << " " << n << " " << idx.second << "\n";
		vis[idx.first][n][idx.second] = 1;
		int k = idx.second;
		for(auto e : graph[k]){
			int nxt = (e.first + dist[idx.first][n][k]) % N;
			if(dist[1][n][nxt] > dist[idx.first][n][k] + e.second){
				dist[1][n][nxt] = dist[idx.first][n][k] + e.second;
			}
		}
		if(idx.first && dist[1][n][(k + 1) % N] > dist[idx.first][n][k] + 1){
			dist[1][n][(k + 1) % N] = dist[idx.first][n][k] + 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			dist[0][i][j] = dist[1][i][j] = inf;
		}
	}
	while(M--){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
	}
	for(int i = 0; i <N; i++){
		dijkstra(i);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i == j){
				cout << 0 << " ";
			}
			else{
				cout << dist[1][i][j] << " ";
			}
		}
		cout << "\n";
	}
}