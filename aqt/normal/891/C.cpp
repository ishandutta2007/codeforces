
// Problem : C. Envy
// Contest : Codeforces Round #446 (Div. 1)
// URL : https://codeforces.com/contest/891/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
const int W = 500000;
vector<int> edg[500005];
int u[500005], v[500005], w[500005];
int par[500005];
bool ans[500005];
vector<pair<int, vector<int>>> qu[500005];
vector<pair<int, int>> graph[500005];
bool vis[500005], instk[500005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

bool dfs(int n, int p){
	//cout << " " << n << "\n";
	vis[n] = instk[n] = 1;
	for(auto e : graph[n]){
		if(e.second != p && instk[e.first]){
			//cout << e.second << "\n";
			return 1;
		}
		else if(e.second != p && !vis[e.first] && dfs(e.first, e.second)){
			return 1;
		}
	}
	instk[n] = 0;
	return 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i =1 ; i<=M; i++){
		cin >> u[i] >> v[i] >> w[i];
		edg[w[i]].push_back(i);
	}
	cin >> Q;
	for(int q = 1; q<=Q; q++){
		vector<pair<int, int>> t;
		int K;
		cin >> K;
		while(K--){
			int n;
			cin >> n;
			t.emplace_back(make_pair(w[n], n));
		}
		sort(t.begin(), t.end());
		int lst = 0;
		vector<int> st;
		for(auto p : t){
			//cout << q << " " << p.first << "\n";
			if(lst != p.first && lst){
				qu[lst].push_back(make_pair(q, st));
				st.clear();
				//cout << q << " " << lst << "\n";
			}
			lst = p.first;
			st.push_back(p.second);
		}
		//cout << lst << "\n";
		qu[lst].push_back({q, st});
	}
	for(int i = 1; i<=N; i++){
		par[i] = i;
	}
	for(int w = 1; w<=W; w++){
		for(auto p : qu[w]){
			for(int e : p.second){
				graph[getrt(u[e])].push_back({getrt(v[e]), e});
				graph[getrt(v[e])].push_back({getrt(u[e]), e});
			}
			for(int e : p.second){
				if(!vis[getrt(u[e])]){
					ans[p.first] |= dfs(getrt(u[e]), 0);
					//cout << p.first << " " << w << " " << ans[p.first] << "\n";
				}
			}
			for(int e : p.second){
				vis[getrt(u[e])] = vis[getrt(v[e])] = 0;
				instk[getrt(u[e])] = instk[getrt(v[e])] = 0;
				graph[getrt(u[e])].pop_back();
				graph[getrt(v[e])].pop_back();
			}
		}
		for(int e : edg[w]){
			par[getrt(u[e])] = getrt(v[e]);
		}
	}
	for(int q = 1; q<=Q; q++){
		if(ans[q]){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}