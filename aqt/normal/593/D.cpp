
// Problem : D. Happy Tree Party
// Contest : Codeforces - Codeforces Round #329 (Div. 2)
// URL : https://codeforces.com/contest/593/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<pair<int, pair<long long, int>>> graph[200005];
int dep[200005];
long long wt[200005];
int par[200005];
int lft[200005];
int rht[200005];
int id[200005];
int t;

void dfs(int n){
	lft[n] = ++t;
	for(auto p : graph[n]){
		int e = p.first;
		if(e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			wt[e] = p.second.first;
			id[p.second.second] = e;
			dfs(e);
		}
	}
	rht[n] = ++t;
}

int getpar(int n){
	if(!n){
		return 0;
	}
	if(wt[n] == 1){
		return par[n] = getpar(par[n]);
	}
	return n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<N; i++){
		int a, b;
		long long c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, make_pair(c, i));
		graph[b].emplace_back(a, make_pair(c, i));
	}
	dfs(1);
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int x, y;
			long long w;
			cin >> x >> y >> w;
			while(w && !(lft[x] <= lft[y] && rht[x] >= rht[y])){
				//cout << x << " " << wt[x] << endl;				
				w /= wt[x];
				x = getpar(par[x]);	
			}
			while(w && !(lft[y] <= lft[x] && rht[y] >= rht[x])){
				//cout << y << " " << wt[y] << endl;
				w /= wt[y];
				y = getpar(par[y]);
			}
			cout << w << "\n";
		}
		else{
			int n;
			long long w;
			cin >> n >> w;
			wt[id[n]] = w;
		}
	}
}