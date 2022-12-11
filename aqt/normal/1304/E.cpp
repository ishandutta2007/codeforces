
// Problem : E. 1-Trees and Queries
// Contest : Codeforces - Codeforces Round #620 (Div. 2)
// URL : https://codeforces.com/contest/1304/problem/E
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int par[20][100005];
int dep[100005];
vector<int> graph[100005];

void dfs(int n){
	for(int e : graph[n]){
		if(e != par[0][n]){
			par[0][e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
}

int lca(int a, int b){
	if(dep[a] < dep[b]){
		swap(a, b);
	}
	for(int d = 19; d>=0; d--){
		if(dep[par[d][a]] >= dep[b]){
			a = par[d][a];
		}
	}
	if(a==b){
		return a;
	}
	for(int d = 19; d>=0; d--){
		if(par[d][a] != par[d][b]){
			a = par[d][a];
			b = par[d][b];
		}
	}
	return par[0][a];
}

int getdis(int a, int b){
	return dep[a] + dep[b] - 2*dep[lca(a,b)];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for(int d = 1; d<20; d++){
		for(int n = 1; n<=N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int a, b, x, y, k;
		cin >> a >> b >> x >> y >> k;
		swap(a, x);
		swap(b, y);
		int d;
		if((d = getdis(a, b))%2 == k%2 && d <= k){
			cout << "YES\n";
		}
		else if((d = getdis(a, x)+getdis(b, y)+1)%2 == k%2 && d <= k){
			cout << "YES\n";
		}
		else if((d = getdis(a, y)+getdis(b, x)+1)%2 == k%2 && d <= k){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}