
// Problem : D. Labelling Cities
// Contest : Tinkoff Challenge - Final Round (Codeforces Round #414, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/794/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> graph[300005];
long long sd[2] = {487471, 687311};
long long MOD = 1e9+7;
//map<pair<long long, long long>, int> mp;
pair<long long, long long> comp[300005];
map<pair<long long, long long>, vector<pair<long long, long long>>> cgraph;
map<pair<long long, long long>, bool> vis;
map<pair<long long, long long>, int> ans;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	for(int n = 1; n<=N; n++){
		graph[n].emplace_back(n);
		sort(graph[n].begin(), graph[n].end());
		pair<long long, long long> hsh = {0, 0};
		for(int k : graph[n]){
			hsh.first *= sd[0];
			hsh.first += k;
			hsh.first %= MOD;
			hsh.second *= sd[1];
			hsh.second += k;
			hsh.second %= MOD;
		}
		//mp[hsh] = n;		
		comp[n] = hsh;
	}
	for(int n = 1; n<=N; n++){
		if(cgraph[comp[n]].empty()){
			vector<pair<long long, long long>> v;
			for(int k : graph[n]){
				if(comp[k] != comp[n]){
					v.emplace_back(comp[k]);
				}
			}
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			cgraph[comp[n]] = v;
			if(v.size() > 2){
				cout << "NO\n";
				return 0;
			}
		}
	}
	int cnt = 0;
	for(int n = 1; n<=N; n++){
		if(!vis[comp[n]] && cgraph[comp[n]].size() <= 1){
			cnt++;
			cnt++;
			auto crnt = comp[n];
			while(true){
				vis[crnt] = 1;
				ans[crnt] = cnt++;
				bool b = 0;
				for(auto e : cgraph[crnt]){
					if(!vis[e]){
						b = 1;
						crnt = e;
						break;
					}
				}
				if(!b){
					break;
				}
			}
		}
	}
	cout << "YES\n";
	for(int n= 1; n<=N; n++){
		cout << ans[comp[n]] << " ";
	}
}