
// Problem : D. Graph and Queries
// Contest : Codeforces - Codeforces Round #673 (Div. 1)
// URL : https://codeforces.com/contest/1416/problem/D
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int arr[500005];
int u[500005];
int v[500005];
int qutyp[500005], quval[500005];
bool goingtodel[500005];
bool bad[500005];
int dsu[200005];
int sz[200005];
vector<pair<int, int>> st[200005];
vector<int> stk;

int getrt(int n){
	return (dsu[n] == n ? n : getrt(dsu[n]));
}

bool unite(int u, int v){
	u = getrt(u);
	v = getrt(v);
	if(u != v){
		if(sz[u] > sz[v]){
			dsu[v] = u;
			sz[u] += sz[v];
			stk.push_back(v);
		}
		else{
			dsu[u] = v;
			sz[v] += sz[u];
			stk.push_back(u);
		}
		return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		sz[i] = 1;
		dsu[i] = i;
	}
	for(int i =1 ; i<=M; i++){
		cin >> u[i] >> v[i];
	}
	for(int q = 1; q<=Q; q++){
		cin >> qutyp[q] >> quval[q];
		if(qutyp[q] == 2){
			goingtodel[quval[q]] = 1;
		}
	}
	for(int i = 1; i<=M; i++){
		if(!goingtodel[i]){
			unite(u[i], v[i]);
		}
	}
	for(int q = Q; q; q--){
		if(qutyp[q] == 2){
			bad[q] = unite(u[quval[q]], v[quval[q]]);
		}
	}
	for(int i = 1; i<=N; i++){
		int p = i;
		while(p != dsu[p]){
			st[p].emplace_back(arr[i], i);
			p = dsu[p];
		}
		st[p].emplace_back(arr[i], i);
	}
	for(int i =1; i<=N; i++){
		sort(st[i].begin(), st[i].end());
	}
	for(int q = 1; q<=Q; q++){
		if(qutyp[q] == 1){
			int p = getrt(quval[q]);
			bool out = 0;
			while(st[p].size()){
				auto k = st[p].back();
				if(arr[k.second] && getrt(k.second) == p){
					cout << arr[k.second] << "\n";
					arr[k.second] = 0;
					st[p].pop_back();
					out = 1;
					break;
				}
				st[p].pop_back();
			}
			if(!out){
				cout << 0 << "\n";
			}
		}
		else if(bad[q]){
			dsu[stk.back()] = stk.back();
			stk.pop_back();
		}
	}
}