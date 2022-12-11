
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
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(agraph.getrt(i) != agraph.getrt(j) && bgraph.getrt(i) != bgraph.getrt(j)){
				agraph.unite(i, j);
				bgraph.unite(i, j);
				ans.emplace_back(i, j);
			}
		}
	}
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}