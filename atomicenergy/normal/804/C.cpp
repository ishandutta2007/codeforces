#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


vvi I;
vvi G;
vi C;

void dfs(int v, int f){
	set<int> s;
	for(auto u : I[v]){
		if(C[u] != -1){
			s.insert(C[u]);
		}
	}
	int ind = 0;
	for(auto u : I[v]){
		if(C[u] == -1){
			while(s.count(ind)!=0){
				ind++;
			}
			C[u] = ind;
			s.insert(ind);
		}
	}
	
	for(auto u: G[v]){
		if(u == f) continue;
		dfs(u, v);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	I = vvi(n,vi());
	G = vvi(n,vi());
	C = vi(m);
	int mx = 0;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		mx = max(mx, x);
		for(int j=0; j<x; j++){
			int y;
			cin >> y;
			I[i].push_back(y-1);
		}
	}
	for(int i=0; i<n-1; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0; i<m; i++){
		C[i] = -1;
	}
	dfs(0, -1);
	cout << max(mx,1) << endl;
	for(int i=0; i<m; i++){
		cout << max(C[i]+1,1) << " ";
	}
	cout << endl;
}