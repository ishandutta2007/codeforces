
// Problem : D. Solve The Maze
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, M;
char mp[55][55];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool vis[55][55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		queue<pair<int, int>> qu;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> mp[i][j];
				if(mp[i][j] == 'B'){
					qu.push({i, j});
				}
				vis[i][j] = 0;
			}
		}
		for(int i = 0; i<=N; i++){
			mp[i][0] = mp[i][M+1] = '#';
		}
		for(int j = 0; j<=M; j++){
			mp[0][j] = mp[N+1][j] = '#';
		}
		while(qu.size()){
			auto p = qu.front();
			qu.pop();
			if(mp[p.first][p.second] == '.'){
				mp[p.first][p.second] = '#';
				continue;
			}
			for(int m = 0; m<4; m++){
				if(mp[p.first+dx[m]][p.second+dy[m]] != '#' && !vis[p.first+dx[m]][p.second+dy[m]]){
					qu.push({p.first + dx[m], p.second + dy[m]});
					vis[p.first+dx[m]][p.second+dy[m]] = 1;
				}
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				vis[i][j] = 0;
			}
		}
		qu.push({N, M});
		vis[N][M] = 1;
		while(qu.size()){
			auto p = qu.front();
			qu.pop();
			if(mp[p.first][p.second] == '#'){
				continue;
			}
			for(int m = 0; m<4; m++){
				if(mp[p.first+dx[m]][p.second+dy[m]] != '#' && !vis[p.first+dx[m]][p.second+dy[m]]){
					qu.push({p.first + dx[m], p.second + dy[m]});
					vis[p.first+dx[m]][p.second+dy[m]] = 1;
				}				
			}
		}
		bool ans = 1;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				if(mp[i][j] == 'B'){
					ans &= (vis[i][j] == 0);
				}
				else if(mp[i][j] == 'G'){
					ans &= (vis[i][j] == 1);
				}
			}
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
}