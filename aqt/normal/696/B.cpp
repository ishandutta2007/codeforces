
// Problem : B. Puzzles
// Contest : Codeforces Round #362 (Div. 1)
// URL : https://codeforces.com/contest/696/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[100005];
long double dp[100005];
int sz[100005];

void dfs1(int n){
	sz[n] = 1;
	for(int e : graph[n]){
		dfs1(e);
		sz[n] += sz[e];
	}
}

void dfs2(int n){
	dp[n]++;
	for(int e : graph[n]){
		//cout << e << " " << sz[n]-1-sz[e] << "\n";
		dp[e] = dp[n] + (sz[n]-1-sz[e])/2.0;
		dfs2(e);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 2; i<=N; i++){
		int n;
		cin >> n;
		graph[n].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	for(int i =1 ; i<=N; i++){
		cout << dp[i] << " ";
	}
}