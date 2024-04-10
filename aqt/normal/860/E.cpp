
// Problem : E. Arkady and a Nobody-men
// Contest : Codeforces - Codeforces Round #434 (Div. 1, based on Technocup 2018 Elimination Round 1)
// URL : https://codeforces.com/contest/860/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, R;
vector<int> graph[500005];
vector<int> cgraph[500005];
int lft[500005], rht[500005], t;
int par[20][500005];
int dep[500005];
vector<int> lst[500005];
int sz[500005];
long long ans[500005];
long long dp[500005];

bool isanc(int a, int b){
	return lft[a] <= lft[b] && rht[a] >= rht[b];
}

void dfs1(int n){
	lft[n] = ++t;
	lst[dep[n]].emplace_back(n);
	for(int e : graph[n]){
		if(e != par[0][n]){
			dep[e] = dep[n] + 1;
			dfs1(e);
		}
	}
	rht[n] = ++t;
}

void dfs2(int n){
	sz[n] = cgraph[n].empty();
	for(int e : cgraph[n]){
		dfs2(e);
		sz[n] += sz[e];
	}
}

void dfs3(int n, int p){
	dp[n] += 1LL * sz[n] * (dep[n] - dep[p]);
	if(cgraph[n].empty()){
		ans[n] = dp[n] - dep[n];
	}
	for(int e : cgraph[n]){
		dp[e] = dp[n];
		dfs3(e, n);
	}
}

void dfs4(int n){
	for(int e : graph[n]){
		ans[e] += ans[n] + dep[n];
		dfs4(e);
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	if(isanc(v, u)){
		return v;
	}
	for(int d = 19; d >= 0; d--){
		if(!par[d][u] || isanc(par[d][u], v));
		else{
			u = par[d][u];
		}
	}
	return par[0][u];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		int p;
		cin >> p;
		if(!p){
			R = i;
		}
		else{
			par[0][i] = p;
			graph[p].emplace_back(i);
		}
	}
	dep[R] = 1;
	dfs1(R);
	for(int d = 1; d < 20; d++){
		for(int n = 1; n <= N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
		}
	}
	for(int i = 1; i <= N; i++){
		int s = lst[i].size();
		for(int k = 1; k < s; k++){
			int p = lca(lst[i][k-1], lst[i][k]);
			lst[i].emplace_back(p);
		}
		sort(lst[i].begin(), lst[i].end(), [](int a, int b){
			return lft[a] < lft[b];
		});
		lst[i].erase(unique(lst[i].begin(), lst[i].end()), lst[i].end());
		if(lst[i].size()){
			vector<int> stk;
			stk.emplace_back(lst[i][0]);
			for(int k = 1; k < lst[i].size(); k++){
				while(!isanc(stk.back(), lst[i][k])){
					stk.pop_back();
				}
				cgraph[stk.back()].emplace_back(lst[i][k]);
				stk.emplace_back(lst[i][k]);
			}
			dfs2(lst[i][0]);
			dp[lst[i][0]] = 0;
			dfs3(lst[i][0], 0);
			for(int n : lst[i]){
				cgraph[n].clear();
			}
		}
	}
	dfs4(R);
	for(int n = 1; n <= N; n++){
		cout << ans[n] << " ";
	}
}