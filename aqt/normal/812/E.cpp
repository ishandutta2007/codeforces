
// Problem : E. Sagheer and Apple Tree
// Contest : Codeforces - Codeforces Round #417 (Div. 2)
// URL : https://codeforces.com/contest/812/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int val[100005];
vector<int> graph[100005];
int clr[100005];
int cnt[5];
map<int, int> fre;

void dfs(int n){
	for(int e : graph[n]){
		clr[e] = clr[n] ^ 1;
		dfs(e);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> val[i];
	}
	for(int i = 2; i<=N; i++){
		int p;
		cin >> p;
		graph[p].push_back(i);
	}
	dfs(1);
	int X = 0;
	int C = 0;
	for(int i = 1; i<=N; i++){
		if(graph[i].empty()){
			C = clr[i];
		}
	}
	for(int i = 1; i<=N; i++){
		if(clr[i] == C){
			X ^= val[i];
			fre[val[i]]++;
		}
		cnt[clr[i]]++;
	}
	long long ans = 0;
	if(!X){
		ans = 1LL * cnt[C] * (cnt[C]-1) / 2 + 1LL * cnt[C^1] * (cnt[C^1]-1) / 2;
	}
	for(int i = 1; i<=N; i++){
		if(clr[i] == (C^1)){
			ans += fre[val[i]^X];
		}
	}
	cout << ans;
}