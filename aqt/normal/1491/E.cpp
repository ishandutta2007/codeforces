
// Problem : E. Fib-tree
// Contest : Codeforces - Codeforces Global Round 13
// URL : https://codeforces.com/contest/1491/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
int sz[200005];
int typ[200005];
int par[200005];
int fib[50];
int c;
vector<int> vec;

void dfs(int n, int p){
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != p && typ[n] == typ[e]){
			par[e] = n;
			dfs(e, n);
			sz[n] += sz[e];
		}
	}
	vec.emplace_back(n);
}

void clr(int n, int p){
	for(int e : graph[n]){
		if(e != p && typ[n] == typ[e]){
			clr(e, n);
		}
	}
	typ[n] = c;
}

bool solve(int n){
	par[n] = 0;
	dfs(n, 0);
	//cout << n << "\n";
	if(sz[n] == 1){
		return 1;
	}
	int idx = -1;
	for(int k = 0; k < 30; k++){
		if(fib[k] == sz[n]){
			idx = k;
			break;
		}
	}
	if(idx == -1){
		return 0;
	}
	int v = 0;
	for(int k : vec){
		if(sz[k] == fib[idx-1] || sz[k] == fib[idx-2]){
			v= k;
		}
	}
	if(!v){
		return 0;
	}
	++c;
	clr(v, par[v]);
	/*
	for(int k = 1; k <= N; k++){
		cout << typ[k] << " ";
	}
	cout << "\n";
	*/
	vec.clear();
	//cout << v << " " << par[v] << "\n";
	return solve(par[v]) && solve(v);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	fib[0] = fib[1] = 1;
	for(int k = 2; k < 30; k++){
		fib[k] = fib[k-1] + fib[k-2];
	}
	cout << (solve(1) ? "YES" : "NO");
}