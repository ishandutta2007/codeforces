
// Problem : C. Three States
// Contest : Codeforces - Codeforces Round #327 (Div. 1)
// URL : https://codeforces.com/contest/590/problem/C
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
char mp[1005][1005];
int dist[4][1005][1005];
queue<pair<int, int>> qu;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int t){
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			if(mp[i][j] == '0' + t){
				qu.push(make_pair(i, j));
			}
			else{
				dist[t][i][j] = INT_MAX/4;
			}
		}
	}
	while(qu.size()){
		auto p = qu.front();
		qu.pop();
		int n = p.first;
		int m = p.second;
		for(int k = 0; k<4; k++){
			if(mp[n+dx[k]][m+dy[k]] != '#' && dist[t][n+dx[k]][m+dy[k]] > dist[t][n][m] + 1){
				//cout << t << " " << n + dx[k] << " " << m + dy[k] << endl;
				//cout << dist[t][n+dx[k]][m+dy[k]] << endl;
				//cout << dist[t][n][m] << endl;
				dist[t][n+dx[k]][m+dy[k]] = dist[t][n][m] + 1;
				//cout << "here" << endl;
				qu.push(make_pair(n+dx[k], m+dy[k]));
				//cout << "t" << endl;
			}
		}
	}
	//cout << "done" << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			cin >> mp[i][j];
		}
	}
	for(int i = 0; i<=N+1; i++){
		mp[i][0] = mp[i][M+1] = '#';
	}
	for(int j = 0; j<=M+1; j++){
		mp[0][j] = mp[N+1][j] = '#';
	}
	bfs(1);
	bfs(2);
	bfs(3);
	int ans = INT_MAX;
	for(int k = 1; k<=3; k++){
		vector<int> bst(4, INT_MAX/4);
		for(int i =1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				if(mp[i][j] != '.' && mp[i][j] != '#'){
					bst[mp[i][j]-'0'] = min(bst[mp[i][j]-'0'], dist[k][i][j]);
				}
			}
		}
		ans = min(ans, bst[1] + bst[2] + bst[3] - 2);
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			ans = min(ans, dist[1][i][j] + dist[2][i][j] + dist[3][i][j] - 2);
		}
	}
	cout << (ans > N*M ? -1 : ans) << "\n";
}