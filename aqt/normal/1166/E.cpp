
// Problem : E. The LCMs Must be Large
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/contest/1166/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<bitset<10005>> v;
unordered_map<bitset<10005>, vector<bitset<10005>>> graph;
unordered_map<bitset<10005>, bool> vis;
unordered_map<bitset<10005>, bool> instk;

bool isCyclic(bitset<10005> n){
	vis[n] = 1;
	instk[n] = 1;
	for(auto e : graph[n]){
		if(!vis[e] && isCyclic(e)){
			return 1;
		}
		else if(instk[e]){
			return 1;
		}
	}
	instk[n] = 0;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		int K;
		cin >> K;
		bitset<10005> t;
		while(K--){
			int n;
			cin >> n;
			t[n] = 1;
		}
		bitset<10005> c;
		for(int i = 1; i<=M; i++){
			if(!t[i]){
				c[i] = 1;
			}
		}
		graph[t].push_back(c);
		v.push_back(t);
		v.push_back(c);
	}
	for(int i = 0; i<v.size(); i++){
		for(int j = 0; j<v.size(); j++){
			if(v[i] != v[j]){
				if((v[i]&v[j]) == v[j]){
					graph[v[i]].push_back(v[j]);
				}
			}
		}
	}
	bool ans = 1;
	for(int i = 0; i<v.size(); i++){
		if(!vis[v[i]] && isCyclic(v[i])){
			ans = 0;
		}
	}
	cout << (ans ? "possible" : "impossible");
}