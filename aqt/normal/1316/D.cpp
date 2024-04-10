
// Problem : D. Nash Matrix
// Contest : Codeforces - CodeCraft-20 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1316/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> arr[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char m[4] = {'L', 'U', 'R', 'D'};
char ans[1005][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cin >> arr[i][j].first >> arr[i][j].second;
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			if(arr[i][j].first == i && arr[i][j].second == j){
				queue<pair<int, int>> qu;
				qu.push({i, j});
				ans[i][j] = 'X';
				while(qu.size()){
					auto p = qu.front();
					qu.pop();
					int x = p.first, y = p.second;
					for(int k = 0; k<4; k++){
						if(arr[x+dx[k]][y+dy[k]] == arr[x][y] && ans[x+dx[k]][y+dy[k]] == 0){
							ans[x+dx[k]][y+dy[k]] = m[k];
							qu.push({x+dx[k], y+dy[k]});
						}
					}
				}
			}
			else if(arr[i][j].first == -1 && arr[i][j].second == -1){
				int x = i, y = j;
				bool b = 0;
				for(int k = 0; k<4; k++){
					if(arr[x+dx[k]][y+dy[k]] == make_pair(-1, -1)){
						ans[x][y] = m[(k+2)%4];
						b = 1;
						break;
					}
				}
				if(!b){
					cout << "INVALID\n";
					return 0;
				}
			}
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			if(!ans[i][j]){
				cout << "INVALID\n";
				return 0;
			}
		}
	}
	cout << "VALID\n";
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout << ans[i][j];
		}
		cout << "\n";
	}
}