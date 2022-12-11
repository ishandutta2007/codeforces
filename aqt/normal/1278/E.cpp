
// Problem : E. Tests for problem D
// Contest : Educational Codeforces Round 78 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1278/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[500005];
int nxt;
int lft[500005], rht[500005];

void dfs(int n, int p){
	nxt += (int) (graph[n].size()) + !p;
	int ed = nxt;
	int lst = ed;
	rht[n] = ed;
	for(int e : graph[n]){
		if(e != p){
			lft[e] = --lst;
			dfs(e, n);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	lft[++nxt] = 1;
	dfs(1, 0);
	for(int i = 1; i<=N; i++){
		cout << lft[i] << " " << rht[i] << "\n";
	}
}