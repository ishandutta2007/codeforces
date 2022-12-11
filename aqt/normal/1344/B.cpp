
// Problem : B. Monopole Magnets
// Contest : Codeforces - Codeforces Round #639 (Div. 1)
// URL : https://codeforces.com/contest/1344/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
bool mp[1005][1005];
bool vis[1005][1005];
int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int n, int m){
	vis[n][m] = 1;
	for(int mm = 0; mm<4; mm++){
		if(!vis[moves[mm][0]+n][moves[mm][1]+m] && mp[moves[mm][0]+n][moves[mm][1]+m]){
			dfs(moves[mm][0]+n, moves[mm][1]+m);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int tot = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			char c;
			cin >> c;
			mp[i][j] = (c == '#');
			tot += mp[i][j];
		}
	}
	bool emptyr = 0, emptyc = 0;
	for(int i = 1; i<=N; i++){
		int cnt = 0;
		for(int j = 1; j<=M+1; j++){
			if(mp[i][j-1] != mp[i][j]){
				cnt++;
			}
		}
		if(cnt != 2 && cnt != 0){
			cout << -1;
			return 0;
		}
		if(cnt == 0){
			emptyr = 1;
		}
	}
	for(int i = 1; i<=M; i++){
		int cnt = 0;
		for(int j = 1; j<=N+1; j++){
			if(mp[j-1][i] != mp[j][i]){
				cnt++;
			}
		}
		if(cnt != 2 && cnt != 0){
			cout << -1;
			return 0 ;
		}
		if(cnt == 0){
			emptyc = 1;
		}
	}
	if(emptyr && !emptyc){
		cout << -1;
		return 0;
	}
	if(!emptyr && emptyc){
		cout << -1;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			if(mp[i][j] && !vis[i][j]){
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans;
}