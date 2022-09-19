#include<bits/stdc++.h>

#define pb push_back

using namespace std;

const int N = 2e5 + 10;

int dis[N], p[N]; //farz konid darim
vector<int> H[N], G[N];

queue<int> q;

int main(){
	int n, m, k;
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		H[v].pb(u);
		G[u].pb(v);
	}
	cin >> k;
	for(int i = 0; i < k; i++) cin >> p[i];

	fill(dis, dis + N, 300000);
	dis[p[k - 1]] = 0;
	q.push(p[k - 1]);
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		for(auto adj : H[fr]){
			if(dis[adj] > dis[fr] + 1){
				dis[adj] = dis[fr] + 1;
				q.push(adj);
			}
		}
	}
	int mn = 0, mx = 0;

	for(int i = 0; i + 1 < k; i++){
		if(dis[p[i]] <= dis[p[i + 1]]) mn ++;
		int fl = 0;
		for(auto adj : G[p[i]]){
			if(adj == p[i + 1]) continue;
			if(dis[adj] <= dis[p[i + 1]]) fl = 1;
		}
		if(fl == 1) mx ++;
	}
	cout << mn << ' ' << mx << '\n';
	return 0;
}