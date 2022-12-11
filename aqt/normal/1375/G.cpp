
// Problem : G. Tree Modification
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/G
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
int clr[200005];

void dfs(int n, int p){
	for(int e : graph[n]){
		if(e != p){
			clr[e] = 1 - clr[n];
			dfs(e, n);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);
	int cnt = accumulate(clr+1, clr+1+N, 0);
	cout << min(N-1-cnt, cnt-1);
}