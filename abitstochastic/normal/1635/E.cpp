#include<bits/stdc++.h>
using namespace std;

const int _ = 3e5 + 7; vector < int > nxt[_] , nxt1[_]; int X[_] , Y[_] , T[_] , N , M , col[_] , ans[_] , deg[_];
bool dfs(int x , int c){
	col[x] = c; for(auto t : nxt[x]) if(!col[t]){if(dfs(t , 3 - c)) return 1;}else if(col[t] == col[x]) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M;
	for(int i = 1 ; i <= M ; ++i){cin >> T[i] >> X[i] >> Y[i]; nxt[X[i]].push_back(Y[i]); nxt[Y[i]].push_back(X[i]);}
	for(int i = 1 ; i <= N ; ++i) if(!col[i] && dfs(i , 1)){cout << "NO"; return 0;}
	for(int i = 1 ; i <= M ; ++i){
		if(T[i] != col[X[i]]) swap(X[i] , Y[i]);
		nxt1[Y[i]].push_back(X[i]); ++deg[X[i]];
	}
	int cnt = 0; queue < int > q; for(int i = 1 ; i <= N ; ++i){if(!deg[i]){q.push(i); ans[i] = 1e9;}}
	while(!q.empty()){
		int t = q.front(); q.pop(); ans[t] = 1e9 - cnt++;
		for(auto p : nxt1[t]) if(!--deg[p]) q.push(p);
	}
	if(cnt != N) cout << "NO";
	else{
		cout << "YES\n";
		for(int i = 1 ; i <= N ; ++i){cout << (col[i] == 1 ? 'L' : 'R') << ' ' << ans[i] << '\n';}
	}
	return 0;
}