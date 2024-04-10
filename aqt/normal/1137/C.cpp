#pragma GCC optimize("no-stack-protector")
// Problem : C. Museums Tour
// Contest : Codeforces - Codeforces Round #545 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1137/C
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, D, C;
vector<int> graph[100005];
int low[55][100005], t;
int val[5000005];
int tkn[100005];
int dp[5000005];
int who[55][100005];
vector<pair<int, int>> nd[5000005];
string open[100005];
int idx = 0;
pair<int, int> stk[5000005];
bool instk[55][100005];

inline void dfs1(int n, int d){
	low[d][n] = ++t;
	stk[++idx] = (make_pair(n, d));
	bool rt = 1;
	instk[d][n] = 1;
	for(int e : graph[n]){
		if(!low[(d+1)%D][e]){
			dfs1(e, (d+1)%D);
		}
		if(instk[(d+1)%D][e] && low[d][n] > low[(d+1)%D][e]){
			low[d][n] = low[(d+1)%D][e];
			rt = 0;
		}
	}
	if(rt){
		pair<int, int> p;
		C++;
		do{
			p = stk[idx--];
			nd[C].push_back(p);
			if(open[p.first][p.second] == '1'){
				val[C] += (tkn[p.first] != C);
				tkn[p.first] = C;
			}
			instk[p.second][p.first] = 0;
			who[p.second][p.first] = C;		
		}
		while(p != make_pair(n, d));
	}
}

inline int dfs2(int n){
	if(dp[n] != -1){
		return dp[n];
	}
	dp[n] = 0;
	for(auto p : nd[n]){
		for(int e : graph[p.first]){
			dp[n] = max(dfs2(who[(p.second+1)%D][e]), dp[n]);
		}
	}
	dp[n] += val[n];
	//cout << "dp: " << n << " " << dp[n] << "\n";
	return dp[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> D;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for(int d = 1; d<=N; d++){
		cin >> open[d];
	}
	dfs1(1, 0);
	fill(dp+1, dp+1+C, -1);
	cout << dfs2(C);
}