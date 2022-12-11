
// Problem : F. Super Jaber
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/F
// Memory Limit : 256.000000 MB 
// Time Limit : 5000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int arr[1005][1005];
int dist[50][1005][1005];
int spd[50][50];
vector<pair<int, int>> typ[50];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		for(int j =1 ; j<=M; j++){
			cin >> arr[i][j];
			typ[arr[i][j]].push_back({i, j});
			for(int k = 1; k<=K; k++){
				dist[k][i][j] = INT_MAX/2;
			}
		}
	}
	for(int k =1 ; k<=K; k++){
		for(int n = 1; n<=K; n++){
			spd[k][n] = INT_MAX/2;
		}
		spd[k][k] = 0;
		queue<pair<int, int>> qu;
		qu.push({0, k});
		while(qu.size()){
			auto p = qu.front();
			qu.pop();
			if(!p.first){
				for(auto q : typ[p.second]){
					if(dist[k][q.first][q.second] > spd[k][p.second] + 1){
						dist[k][q.first][q.second] = spd[k][p.second] + 1;
						qu.push({q.first, q.second});
					}
				}
				continue;
			}
			int x = p.first, y = p.second;
			if(spd[k][arr[x][y]] > dist[k][x][y]){
				//cout << "hi" << "\n";
				qu.push({0, arr[x][y]});
				spd[k][arr[x][y]] = dist[k][x][y];
			}
			for(auto m : moves){
				if(x+m.first && x+m.first <= N && y+m.second && y+m.second <= M
				&& dist[k][x+m.first][y+m.second] > dist[k][x][y] + 1){
					dist[k][x+m.first][y+m.second] = dist[k][x][y] + 1;
					qu.push({x+m.first, y+m.second});
				}
			}
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int ans = abs(sx-ex) + abs(sy-ey);
		//cout << dist[arr[sx][sy]][ex][ey] << "\n";
		for(int k = 1; k<=K; k++){
			//cout << dist[k][ex][ey] << " " << dist[k][sx][sy] << "\n";
			ans = min(ans, dist[k][ex][ey] + dist[k][sx][sy] - 1);
		}
		cout << ans << "\n";
	}
}