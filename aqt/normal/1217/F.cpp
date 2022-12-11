// Problem : F. Forced Online Queries Problem
// Contest : Codeforces - Educational Codeforces Round 72 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1217/F
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
const int B = 600;
int x = 0;
int par[200005], sz[200005];
vector<pair<int, pair<int, int>>> qu;
vector<pair<int, int>> temp;
set<pair<int, int>> edg[200005];
set<pair<int, int>> tempe;
int vec[200005], idx = 0;

int getrt(int n, bool b = 0){
	if(par[n] == n){
		return n;
	}
	return getrt(par[n]);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int q = 0; q<Q; q++){
		if(q%B == 0){
			for(int i = 1; i<=N; i++){
				par[i] = i;
				sz[i] = 1;
			}
			tempe.clear();
			temp.clear();
			const int lim = min(Q, q+B);
			for(int i = q; i<lim; i++){
				int c, u, v;
				cin >> c >> u >> v;
				qu.emplace_back(make_pair(c, make_pair(u, v)));
				if(c == 1){
					pair<int, int> p = {u%N+1, v%N+1};
					if(p.first > p.second){
						swap(p.first, p.second);
					}
					temp.emplace_back(p);
					tempe.insert(p);
					p.first = (u + N - 1)%N + 1;
					p.second = (v + N - 1)%N + 1;
					if(p.first > p.second){
						swap(p.first, p.second);
					}
					temp.emplace_back(p);
					tempe.insert(p);
				}
			}
			for(int n = 1; n<=N; n++){
				for(auto e : edg[n]){
					int y = getrt(e.first), z = getrt(e.second);
					if(!tempe.count(e) && z != y){
						if(sz[z] > sz[y]){
							par[y] = z;
							sz[z] += sz[y];
						}
						else{
							par[z] = y;
							sz[y] += sz[z];
						}
					}
				}
			}
		}
		if(qu[q].first == 1){
			pair<int, int> e = qu[q].second;
			e.first = (e.first + x + N - 1)%N + 1;
			e.second = (e.second + x + N - 1)%N + 1;
			if(e.first > e.second){
				swap(e.first, e.second);
			}
			if(edg[e.first].count(e)){
				edg[e.first].erase(e);
			}
			else{
				edg[e.first].insert(e);
			}
		}	
		else{
			for(auto e : temp){
				if(edg[e.first].count(e)){
					int u = getrt(e.first, 1), v = getrt(e.second, 1);
					if(u != v){
						if(sz[u] > sz[v]){
							sz[u] += sz[v];
							par[v] = u;
							vec[idx++] = v;
						}
						else{
							sz[v] += sz[u];
							par[u] = v;
							vec[idx++] = u;
						}
					}		
				}
			}
			cout << (x = (getrt((qu[q].second.first+x-1+N)%N+1) == getrt((qu[q].second.second+x-1+N)%N+1)));
			while(idx-- >= 0){
				par[vec[idx]] = vec[idx];
			}
			idx = 0;
		}	
	}
}