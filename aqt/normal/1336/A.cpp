
// Problem : A. Linova and Kingdom
// Contest : Codeforces - Codeforces Round #635 (Div. 1)
// URL : https://codeforces.com/contest/1336/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
int par[200005];
int sz[200005];
int dep[200005];
bool istourism[200005];
long long ans = 0;

void dfs(int n){
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
			sz[n] += sz[e];
		}
	}
}

void dfs2(int n, int c){
	if(!istourism[n]){
		ans += c;
	}
	for(int e : graph[n]){
		if(e != par[n]){
			dfs2(e, c+istourism[n]);
		}
	}
}
/*
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1 ;i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	vector<pair<int, int>> v;
	for(int i = 1; i<=N; i++){
		v.push_back({sz[i], i});
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	for(int i = 1; i<=N-K; i++){
		cout << v[i-1].second << "\n";
		istourism[v[i-1].second] = 1;
	}
	dfs2(1, 0);
	cout << ans << "\n";
}
*/

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1 ;i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	/*
	queue<int> qu;
	qu.push(1);
	vector<int> ord;
	while(qu.size()){
		int n = qu.front();
		ord.push_back(n);
		qu.pop();
		for(int e : graph[n]){
			if(e != par[n]){
				par[e] = n;
				qu.push(e);
			}
		}
	}
	*/
	vector<pair<int, int>> v;
	for(int i = 1; i<=N; i++){
		v.push_back(make_pair(dep[i]-sz[i]+1, i));
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	for(int i = 1; i<=K; i++){
		ans += v[i-1].first;
	}
	cout << ans << "\n";
}