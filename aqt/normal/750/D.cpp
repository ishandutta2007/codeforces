
// Problem : D. New Year and Fireworks
// Contest : Codeforces - Good Bye 2016
// URL : https://codeforces.com/contest/750/problem/D
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

bool vis[31][305][305][8][6];
bool done[305][305];
int N;
int arr[35];
vector<pair<int, int>> dir = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};

void dfs(int r, int c, int d, int idx, int lft){
	if(idx == N+1){
		return;
	}
	if(vis[idx][r][c][d][lft]){
		return;
	}
	done[r][c] = vis[idx][r][c][d][lft] = 1;
	if(lft == 1){
		dfs(r+dir[(d+1)%8].first, c+dir[(d+1)%8].second, (d+1)%8, idx+1, arr[idx+1]);
		dfs(r+dir[(d+7)%8].first, c+dir[(d+7)%8].second, (d+7)%8, idx+1, arr[idx+1]);
	}
	else{
		dfs(r+dir[d].first, c+dir[d].second, d, idx, lft-1);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	dfs(151, 151, 0, 1, arr[1]);
	int ans = 0;
	for(int i = 0; i<=303; i++){
		for(int j = 0; j<=303; j++){
			ans += done[i][j];
		}
	}
	cout << ans << "\n";
}