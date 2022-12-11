
// Problem : F. st-Spanning Tree
// Contest : Codeforces - Codeforces Round #375 (Div. 2)
// URL : https://codeforces.com/contest/723/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[200005];
int nd[2], deg[2];
int cnt[2][200005];
int dsu[200005];
int olddsu[200005];
int sz[4];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int getoldrt(int n){
	return olddsu[n] = (olddsu[n] == n ? n : getoldrt(olddsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> nd[0] >> nd[1] >> deg[0] >> deg[1];
	/*
	if(deg[0] > graph[nd[0]].size() || deg[1] > graph[nd[1]].size()){
		cout << "No\n";
		return 0;
	}
	*/
	for(int i = 1; i<=N; i++){
		dsu[i] = i;
	}
	vector<pair<int, int>> ans;
	for(int n =1 ; n<=N; n++){
		for(int e : graph[n]){
			if(n != nd[0] && n != nd[1] && e != nd[0] && e != nd[1]){
				if(getrt(n) != getrt(e)){
					dsu[getrt(n)] = getrt(e);
					//cout << n << " " << e << "\n";
					ans.emplace_back(n, e);
				}
			}
		}
	}
	bool spedge = 0;
	for(int k = 0; k<2; k++){
		for(int e : graph[nd[k]]){
			cnt[k][getrt(e)]++;
			if(e == nd[0] || e == nd[1]){
				spedge = 1;
			}
		}
		cnt[k][nd[0]] = cnt[k][nd[1]] = 0;
	}
	for(int i = 1; i<=N; i++){
		olddsu[i] = dsu[i];
	}
	for(int k = 0; k<2; k++){
		for(int e : graph[nd[k]]){
			//cout << getrt(e) << " " << getrt(nd[k]) << " " << cnt[k][getrt(e)] << " " << cnt[k^1][getrt(e)] << "\n";
			if(getrt(e) != getrt(nd[k]) && cnt[k][getoldrt(e)] && !cnt[k^1][getoldrt(e)]){
				ans.emplace_back(e, nd[k]);
				dsu[getrt(e)] = getrt(nd[k]);
				deg[k]--;
			}
		}
	}
	for(int k = 0; k<2; k++){
		for(int e : graph[nd[k]]){
			if(cnt[k][getoldrt(e)] && cnt[k^1][getoldrt(e)] && getrt(e) != getrt(nd[k]) && deg[k] > 0){
				//cout << k << " " << e << "\n";
				ans.emplace_back(e, nd[k]);
				dsu[getrt(e)] = getrt(nd[k]);
				deg[k]--;
			}
		}
	}
	if(deg[0] > 0 && deg[1] > 0 && spedge && getrt(nd[0]) != getrt(nd[1])){
		deg[0]--, deg[1]--;
		ans.emplace_back(nd[0], nd[1]);
		dsu[getrt(nd[0])] = getrt(nd[1]);
	}
	/*
	cout << ans.size() << " " << deg[0] << " " << deg[1] << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
	*/
	if(ans.size() == N-1 && deg[0] >= 0 && deg[1] >= 0){
		cout << "Yes\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
	}
	else{
		cout << "No\n";
	}
}