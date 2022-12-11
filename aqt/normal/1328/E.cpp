
// Problem : E. Tree Queries
// Contest : Codeforces Round #629 (Div. 3)
// URL : https://codeforces.com/contest/1328/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int lft[200005], rht[200005];
int t;
vector<int> graph[200005];
int par[200005];
int dep[200005];

void dfs(int n){
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
	rht[n] = ++t;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	while(Q--){
		int n;
		vector<int> v;
		cin >> n;
		int deepest = 1;
		while(n--){
			int k;
			cin >> k;
			if(k != 1){
				k = par[k];
			}
			if(dep[k] > dep[deepest]){
				deepest = k;
			}
			v.emplace_back(k);
		}
		bool ans = 1;
		for(int k : v){
			if(lft[k] <= lft[deepest] && rht[k] >= rht[deepest]){
				
			}
			else{
				ans = 0;
			}
		}
		if(ans){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}