
// Problem : A. Web of Lies
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> st[200005];
int ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int empty = N;
	for(int i = 1; i <= M; i++){
		int u, v;
		cin >> u >> v;
		if(u < v){
			swap(u, v);
		}
		if(st[v].empty()){
			empty--;
		}
		if(st[u].empty()){
			empty--;
		}
		if(st[v].size() >= 1 && *(st[v].rbegin()) < v){
			ans--;
		}
		if(st[u].size() >= 1 && *(st[u].rbegin()) < u){
			ans--;
		}
		st[v].insert(u);
		st[u].insert(v);
		if(st[v].size() >= 1 && *(st[v].rbegin()) < v){
			ans++;
		}
		if(st[u].size() >= 1 && *(st[u].rbegin()) < u){
			ans++;
		}
	}
	int Q;
	cin >> Q;
	while(Q--){
		int typ;
		cin >> typ;
		if(typ == 1){
			int u, v;
			cin >> u >> v;
			if(u < v){
				swap(u, v);
			}
			if(st[v].empty()){
				empty--;
			}
			if(st[u].empty()){
				empty--;
			}
			if(st[v].size() >= 1 && *(st[v].rbegin()) < v){
				ans--;
			}
			if(st[u].size() >= 1 && *(st[u].rbegin()) < u){
				ans--;
			}
			st[v].insert(u);
			st[u].insert(v);
			if(st[v].size() >= 1 && *(st[v].rbegin()) < v){
				ans++;
			}
			if(st[u].size() >= 1 && *(st[u].rbegin()) < u){
				ans++;
			}
		}
		else if(typ == 2){
			int u, v;
			cin >> u >> v;
			if(u < v){
				swap(u, v);
			}
			if(st[v].size() >= 1 && *(st[v].rbegin()) < v){
				ans--;
			}
			if(st[u].size() >= 1 && *(st[u].rbegin()) < u){
				ans--;
			}
			st[v].erase(u);
			st[u].erase(v);
			if(st[v].size() >= 1 && *(st[v].rbegin()) < v){
				ans++;
			}
			if(st[u].size() >= 1 && *(st[u].rbegin()) < u){
				ans++;
			}
			if(st[v].empty()){
				empty++;
			}
			if(st[u].empty()){
				empty++;
			}
		}
		else{
			cout << ans+empty << "\n";
		}
	}
}