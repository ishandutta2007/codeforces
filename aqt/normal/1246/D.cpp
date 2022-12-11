// Problem : D. Tree Factory
// Contest : Codeforces Round #596 (Div. 1, based on Technocup 2020 Elimination Round 2)
// URL : https://codeforces.com/contest/1246/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
#include <bits/stdc++.h>
 
using namespace std;
 
int N;
vector<int> graph[100005];
int par[100005];
int dep[100005];
int mx[100005];
 
void dfs1(int n){
	for(int e : graph[n]){
		dep[e] = dep[n] + 1;
		dfs1(e);
	}
}
 
vector<int> dfs2(int n){
	vector<int> v = {n};
	mx[n] = dep[n];
	for(int e : graph[n]){
		auto t = dfs2(e);
		if(mx[e] > mx[n]){
			mx[n] = mx[e];
			v.insert(v.end(), t.begin(), t.end());
		}
		else{
			v.insert(v.begin()+1, t.begin(), t.end());
		}
	}
	return v;
}
 
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		cin >> par[i];
		graph[par[i]].emplace_back(i);
	}
	dep[0] = 1;
	dfs1(0);
	auto out = dfs2(0);
	vector<int> v;
	for(int i = 1; i<N; i++){
		int d = dep[out[i-1]] - dep[par[out[i]]];
		while(d--){
			v.emplace_back(out[i]);
		}
	}
	for(int n : out){
		cout << n << " ";
	}
	cout << "\n" << v.size() << "\n";
	for(int n : v){
		cout << n << " ";
	}
}