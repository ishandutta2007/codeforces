
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/contest/1166/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, C, Q, K;
set<int> neigh[1000005];
map<pair<int, int>, int> mp;
int par[1000005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void unite(int a, int b){
	a = getrt(a), b = getrt(b);
	if(a != b){
		if(neigh[a].size() > neigh[b].size()){
			swap(neigh[b], neigh[a]);
		}
		for(int n : neigh[a]){
			neigh[b].insert(n);
		}
		par[a] = b;
	}
}

void addedge(int a, int b, int c){
	if(!mp.count({a, c})){
		mp[{a, c}] = ++K;
		par[K] = K;
	}
	if(!mp.count({b, c})){
		mp[{b, c}] = ++K;
		par[K] = K;
	}
	neigh[getrt(a)].insert(b);
	neigh[getrt(b)].insert(a);
	unite(a, mp[{b, c}]);
	unite(b, mp[{a, c}]);	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> C >> Q;
	K = N;
	for(int i = 1; i<=N; i++){
		par[i] = i;
	}
	for(int i =1 ; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	while(Q--){
		char c;
		cin >> c;
		if(c == '?'){
			int a, b;
			cin >> a >> b;
			a = getrt(a);
			if(getrt(b) == a || neigh[a].count(b)){
				cout << "Yes\n";
			}
			else{
				cout << "No\n";
			}
		}
		else{
			int a, b, c;
			cin >> a >> b >> c;
			addedge(a, b, c);
		}
	}	
}