/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 105;

int n, doone[N];
vector<pii>g[N];
int dis[N];
pii mx;

void dfs(int at, int par){
	mx = max(mx, {dis[at], at});
	for(auto u : g[at]){
		if(u.first == par) continue;
		dis[u.first] = dis[at] + u.second;
		dfs(u.first, at);
	}
}

int main(){
	int x, y, c;
	scanf("%d", &n);
	for(int i=0;i<n-1;i++){
		scanf("%d %d %d", &x, &y, &c);
		g[x].push_back({y, c});
		g[y].push_back({x, c});
	}
	mx = {-1, 0};
	dis[1] = 0;
	dfs(1, 1);
	mx = {-1, 0};
	dis[mx.second] = 0;
	dfs(mx.second, mx.second);
	cout << mx.first << endl;
	return 0;
}