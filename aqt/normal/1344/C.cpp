
// Problem : C. Quantifier Question
// Contest : Codeforces - Codeforces Round #639 (Div. 1)
// URL : https://codeforces.com/contest/1344/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[200005], rgraph[200005];
bool vis[200005], visr[200005];
bool instk[200005];
//bool ans[200005];
bool typ[200005];
string out;

bool iscyclic(int n){
	vis[n] = instk[n] = 1;
	for(int e : graph[n]){
		if(!vis[e] && iscyclic(e)){
			return 1;
		}	
		else if(instk[e]){
			return 1;
		}
	}
	instk[n] = 0;
	return 0;
}

void dfs(int n){
	if(vis[n]){
		return;
	}
	vis[n] = 1;
	for(int e : graph[n]){
		if(!vis[e]){
			dfs(e);
		}
	}
}

void dfsr(int n){
	if(visr[n]){
		return;
	}
	visr[n] = 1;
	for(int e : rgraph[n]){
		if(!visr[e]){
			dfsr(e);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	for(int i = 1; i<=N; i++){
		if(!vis[i]){
			if(iscyclic(i)){
				cout << -1;
				return 0;
			}
		}
	}
	fill(vis+1, vis+1+N, 0);
	int cnt = 0;
	for(int i = 1; i<=N; i++){
		if(!vis[i] && !visr[i]){
			out.push_back('A');
			cnt++;
		}
		else{
			out.push_back('E');
		}
		dfs(i);
		dfsr(i);
	}
	cout << cnt << "\n" << out << "\n";
}