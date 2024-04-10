
// Problem : B. Igor and his way to work
// Contest : Codeforces - Tinkoff Challenge - Elimination Round
// URL : https://codeforces.com/contest/793/problem/B
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dist[4][1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char mp[1005][1005];
queue<pair<pair<int,int>, int>> qu;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int j = 0; j<=M+1; j++){
		mp[N+1][j] = mp[0][j] = '*';
	}
	for(int i = 0; i<=N+1; i++){
		mp[i][0] = mp[i][M+1] = '*';
	}
	int sx = 0, sy = 0, ex = 0, ey = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cin >> mp[i][j];
			if(mp[i][j] == 'S'){
				sx = i, sy = j;
				for(int m = 0; m<4; m++){
					qu.push({{i, j}, m});
				}
				continue;
			}
			for(int m = 0; m<4; m++){
				dist[m][i][j] = 3;
			}
			if(mp[i][j] == 'T'){
				ex = i, ey = j;
			}
		}
	}
	while(qu.size()){
		auto p = qu.front();
		qu.pop();
		int x = p.first.first, y = p.first.second, m = p.second;
		if(mp[x+dx[m]][y+dy[m]] != '*' && dist[m][x+dx[m]][y+dy[m]] > dist[m][x][y]){
			dist[m][x+dx[m]][y+dy[m]] = dist[m][x][y];
			qu.push({{x+dx[m], y+dy[m]}, m});
		}
		if(dist[(m+1)%4][x][y] > dist[m][x][y] + 1){
			dist[(m+1)%4][x][y] = dist[m][x][y] + 1;
			qu.push({{x, y}, (m+1)%4});
		}
		if(dist[(m+3)%4][x][y] > dist[m][x][y] + 1){
			dist[(m+3)%4][x][y] = dist[m][x][y] + 1;
			qu.push({{x, y}, (m+3)%4});
		}
	}
	int ans = 3;
	for(int m = 0; m<4; m++){
		ans = min(ans, dist[m][ex][ey]);
	}
	cout << (ans != 3 ? "YES\n" : "NO\n");
}