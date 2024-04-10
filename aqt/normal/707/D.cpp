
// Problem : D. Persistent Bookcase
// Contest : Codeforces - Codeforces Round #368 (Div. 2)
// URL : https://codeforces.com/contest/707/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int e, t, x, y;
};

int N, M, Q;
vector<Edge> graph[100005];
int S = 0;
int ans[100005];
bitset<1005> bs[1005];
bitset<1005> full;

void dfs(int n){
	ans[n] = S;
	for(auto e : graph[n]){
		if(e.t == 1){
			bool done = 0;
			if(!bs[e.x][e.y]){
				S++;
				bs[e.x][e.y] = 1;
				done = 1;
			}
			dfs(e.e);
			if(done){
				bs[e.x][e.y] = 0;
				S--;
			}
		}
		else if(e.t == 2){
			//cout << " " << bs[e.x][e.y] << "\n";
			//cout << " " << S << "\n";
			bool done = 0;
			if(bs[e.x][e.y]){
				S--;
				bs[e.x][e.y] = 0;
				done = 1;
			}
			//cout << " " << S << "\n";
			dfs(e.e);
			if(done){
				bs[e.x][e.y] = 1;
				S++;
			}
		}
		else if(e.t == 3){
			S -= bs[e.x].count();
			bs[e.x] ^= full;
			S += bs[e.x].count();
			dfs(e.e);
			S -= bs[e.x].count();
			bs[e.x] ^= full;
			S += bs[e.x].count();
		}
		else{
			dfs(e.e);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1; i<=M; i++){
		full[i] = 1;
	}
	for(int q = 1; q<=Q; q++){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			graph[q-1].push_back({q, t, x, y});
		}
		else if(t == 2){
			int x, y;
			cin >> x >> y;
			graph[q-1].push_back({q, t, x, y});
		}
		else if(t == 3){
			int x;
			cin >> x;
			graph[q-1].push_back({q, t, x, 0});
		}
		else{
			int p;
			cin >> p;
			graph[p].push_back({q, t, 0, 0});
		}
	}
	dfs(0);
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << "\n";
	}
}