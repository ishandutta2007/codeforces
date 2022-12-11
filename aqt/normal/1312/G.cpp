
// Problem : G. Autocompletion
// Contest : Educational Codeforces Round 83 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1312/problem/G
// Memory Limit : 512.000000 MB 
// Time Limit : 7000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N;
int nxt[30][1000005];
bool wrd[1000005];
int mn[1000005];
int dist[1000005];
int t = 0;
vector<int> v;

void dfs(int n){
	if(wrd[n]){
		t++;
		dist[n] = min(dist[n], mn[n] + t);
		mn[n] = min(mn[n], dist[n]-t+1);
	}
	else{
		mn[n] = min(mn[n], dist[n]-t);
	}
	for(int c = 0; c<26; c++){
		if(nxt[c][n]){
			mn[nxt[c][n]] = mn[n];
			dist[nxt[c][n]] = dist[n] + 1;
			dfs(nxt[c][n]);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		int p;
		char c;
		cin >> p >> c;
		nxt[c-'a'][p] = i;
	}
	int K;
	cin >> K;
	while(K--){
		int n;
		cin >> n;
		wrd[n] = 1;
		v.push_back(n);
	}
	dfs(0);
	for(int n : v){
		cout << dist[n] << " ";
	}
}