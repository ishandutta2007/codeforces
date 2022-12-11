
// Problem : C. Orac and Game of Life
// Contest : Codeforces - Codeforces Round #641 (Div. 1)
// URL : https://codeforces.com/contest/1349/problem/C
// Memory Limit : 128 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, T;
bool m[1005][1005];
queue<pair<int, int>> qu;
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
long long dist[1005][1005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> T;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			char c;
			cin >> c;
			m[i][j] = (c == '1');
		}
	}	
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			dist[i][j] = LLONG_MAX/2;
			for(int k = 0; k<4; k++){
				if(i+moves[k][0] > 0 && i+moves[k][0] <= N && j+moves[k][1] > 0 && j+moves[k][1] <=M){
					if(m[i+moves[k][0]][j+moves[k][1]] == m[i][j]){
						dist[i][j] = 1;
					}
				}
			}
			if(1 == dist[i][j]){
				qu.push({i, j});
			}
		}
	}
	while(qu.size()){
		auto q = qu.front();
		qu.pop();
		for(int k=0; k<4; k++){
			if(q.first+moves[k][0] > 0 && q.first+moves[k][0] <= N && q.second+moves[k][1] > 0 && q.second+moves[k][1] <= M){
				if(m[q.first+moves[k][0]][q.second+moves[k][1]] != m[q.first][q.second]){
					if(dist[q.first+moves[k][0]][q.second+moves[k][1]] > dist[q.first][q.second] + 1){
						dist[q.first+moves[k][0]][q.second+moves[k][1]] = dist[q.first][q.second] + 1;
						qu.push({q.first+moves[k][0], q.second+moves[k][1]});
					}
				}
			}
		}
	}
	/*
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	while(T--){
		int x, y;
		long long t;
		cin >> x >> y >> t;
		bool ans = m[x][y];
		if(dist[x][y] <= t && (t-dist[x][y])%2 == 0){
			ans = !ans;
		}
		cout << ans << "\n";
	}
}