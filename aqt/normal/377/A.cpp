
// Problem : A. Maze
// Contest : Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/contest/377/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
queue<pair<int, int>> qu;
int moves[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
char mp[505][505];
vector<pair<int, int>> v;
bool vis[505][505];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	int sX = 0, sY = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cin >> mp[i][j];
			if(mp[i][j] == '.'){
				sX = i;
				sY = j;
			}
		}
	}
	qu.push(make_pair(sX, sY));
	vis[sX][sY] = 1;
	while(qu.size()){
		auto n = qu.front();
		v.push_back(n);
		qu.pop();
		for(int m = 0; m<4; m++){
			if(mp[n.first+moves[m][0]][n.second+moves[m][1]] == '.' && !vis[n.first+moves[m][0]][n.second+moves[m][1]]){
				vis[n.first+moves[m][0]][n.second+moves[m][1]] = 1;
				qu.push({n.first+moves[m][0], n.second+moves[m][1]});
			}
		}
	}
	reverse(v.begin(), v.end());
	for(int i = 0; i<K; i++){
		mp[v[i].first][v[i].second] = 'X';
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cout << mp[i][j];
		}
		cout << "\n";
	}
}