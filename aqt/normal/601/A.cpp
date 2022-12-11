
// Problem : A. The Two Routes
// Contest : Codeforces - Codeforces Round #333 (Div. 1)
// URL : https://codeforces.com/contest/601/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct state{
	int a, b; 
	bool t;
};

int N, M;
bool graph[405][405];
int dist[2][405][405];
queue<state> qu;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			dist[0][i][j] = dist[1][i][j] = INT_MAX/2;
		}
	}
	dist[0][1][1] = 0;
	qu.push({1, 1, 0});
	while(qu.size()){
		auto s = qu.front();
		//cout << s.a << " " << s.b << " " << s.t << "\n";
		qu.pop();
		if(s.t == 0){
			if(s.a == N){
				if(dist[1][s.a][s.b] > dist[0][s.a][s.b]+1){
					dist[1][s.a][s.b] = dist[0][s.a][s.b]+1;
					qu.push({s.a, s.b, 1});
				}
			}
			else{
				for(int e = 1; e<=N; e++){
					if(e != s.a && graph[s.a][e] == 0 && dist[1][e][s.b] > dist[0][s.a][s.b] + 1){
						dist[1][e][s.b] = dist[0][s.a][s.b] + 1;
						qu.push({e, s.b, 1});
					}
				}
			}
		}
		else{
			if(s.b == N){
				if(dist[0][s.a][s.b] > dist[1][s.a][s.b]){
					dist[0][s.a][s.b] = dist[1][s.a][s.b];
					qu.push({s.a, s.b, 0});
				}
			}
			else{
				for(int e = 1; e<=N; e++){
					if((e != s.a || e == N) && graph[s.b][e] == 1 && dist[0][s.a][e] > dist[1][s.a][s.b]){
						dist[0][s.a][e] = dist[1][s.a][s.b];
						qu.push({s.a, e, 0});
					}
				}
			}
		}
	}
	int ans = min(dist[0][N][N], dist[1][N][N]);
	cout << (ans == INT_MAX/2 ? -1 : ans) << "\n";
}