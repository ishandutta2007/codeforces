
// Problem : D1. Mocha and Diana (Easy Version)
// Contest : Codeforces - Codeforces Round #738 (Div. 2)
// URL : https://codeforces.com/contest/1559/problem/D1
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct DSU{
	vector<int> dsu;
	
	DSU(){}
	
	DSU(int N){
		dsu.resize(N+1);
		iota(dsu.begin(), dsu.end(), 0);
	}
	
	int getrt(int n){
		return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
	}
	
	bool unite(int a, int b){
		a = getrt(a);
		b = getrt(b);
		if(a != b){
			dsu[a] = b;
			return 1;
		}
		return 0;
	}
};

int N, A, B;
DSU agraph;
DSU bgraph;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> A >> B;
	agraph = DSU(N);
	bgraph = DSU(N);
	while(A--){
		int a, b;
		cin >> a >> b;
		agraph.unite(a, b);
	}
	while(B--){
		int a, b;
		cin >> a >> b;
		bgraph.unite(a, b);
	}
	vector<pair<int, int>> ans;
	vector<int> u, v;
	for(int j = 1; j <= N; j++){
		if(agraph.getrt(1) != agraph.getrt(j) && bgraph.getrt(1) != bgraph.getrt(j)){
			agraph.unite(1, j);
			bgraph.unite(1, j);
			ans.emplace_back(1, j);
		}
		/*
		else if(agraph.getrt(1) != agraph.getrt(j)){
			u.emplace_back(agraph.getrt(j));
		}
		else if(bgraph.getrt(1) != bgraph.getrt(j)){
			v.emplace_back(bgraph.getrt(j));
		}
		*/
	}
	for(int j = 1; j <= N; j++){
		if(agraph.getrt(1) != agraph.getrt(j)){
			u.emplace_back(agraph.getrt(j));
		}
		else if(bgraph.getrt(1) != bgraph.getrt(j)){
			v.emplace_back(bgraph.getrt(j));
		}
	}
	sort(u.begin(), u.end());
	u.erase(unique(u.begin(), u.end()), u.end());
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	/*
	for(int i : u){
		for(int j : v){
			if(agraph.getrt(i) != agraph.getrt(j) && bgraph.getrt(i) != bgraph.getrt(j)){
				agraph.unite(i, j);
				bgraph.unite(i, j);
				ans.emplace_back(i, j);
			}
		}
		break;
	}
	for(int j : v){
		for(int i : u){
			if(agraph.getrt(i) != agraph.getrt(j) && bgraph.getrt(i) != bgraph.getrt(j)){
				agraph.unite(i, j);
				bgraph.unite(i, j);
				ans.emplace_back(i, j);
			}
		}
		break;
	}
	*/
	for(int k = 0; k < min(v.size(), u.size()); k++){
		int i = v[k];
		int j = u[k];
		if(agraph.getrt(i) != agraph.getrt(j) && bgraph.getrt(i) != bgraph.getrt(j)){
			agraph.unite(i, j);
			bgraph.unite(i, j);
			ans.emplace_back(i, j);
		}
	}
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}