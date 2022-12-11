
// Problem : C. Love Triangles
// Contest : Codeforces - Codeforces Round #309 (Div. 1)
// URL : https://codeforces.com/contest/553/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[100005];
bool clr[100005];
bool vis[100005];

void dfs(int n){
	vis[n] = 1;
	for(auto e : graph[n]){
		if(!vis[e.first]){
			clr[e.first] = clr[n] ^ e.second;
			dfs(e.first);
		}
		else if(clr[e.first] != clr[n] ^ e.second){
			cout << 0 << endl;
			exit(0);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		c ^= 1;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	int C = 0;
	for(int i = 1; i<=N; i++){
		if(!vis[i]){
			C++;
			dfs(i);
		}
	}
	C--;
	long long ans = 1;
	while(C--){
		ans *= 2;
		ans %= 1000000007;
	}
	cout << ans;
}