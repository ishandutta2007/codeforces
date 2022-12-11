
// Problem : D. BFS Trees
// Contest : Codeforces - Codeforces Round #706 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1495/D
// Memory Limit : 512 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dist[405][405];
vector<int> graph[405];
const long long MOD = 998244353;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			dist[i][j] = (i != j)*10000;
		}
	}
	for(int i =1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for(int k = 1; k<=N; k++){
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int a = 1; a<=N; a++){
		for(int b = 1; b<=N; b++){
			int onpath = 0;
			long long ans = 1;
			for(int n = 1; n<=N; n++){
				if(dist[a][b] == dist[a][n] + dist[b][n]){
					onpath++;	
				}
				else{
					int cnt = 0;
					for(int k : graph[n]){
						if(dist[a][k] + 1 == dist[a][n] && dist[b][k] + 1 == dist[b][n]){
							cnt++;
						}
					}
					ans = (ans * cnt) % MOD;
				}
			}
			ans *= (onpath == dist[a][b] + 1);
			cout << ans << " ";
			//cout << dist[a][b] << " ";
		}
		cout << "\n";
	}
}