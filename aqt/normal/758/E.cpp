
// Problem : E. Broken Tree
// Contest : Codeforces - Codeforces Round #392 (Div. 2)
// URL : https://codeforces.com/contest/758/problem/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long u[200005], v[200005], w[200005], p[200005];
vector<pair<int, int>> graph[200005];
int par[200005];
int ord[200005], t; 
int lst[200005];
long long dp[200005];
long long tot[200005];
long long c[200005];

void dfs1(int n){
	for(auto e : graph[n]){
		if(e.second != par[n]){
			par[e.first] = e.second;
			dfs1(e.first);
			dp[n] += dp[e.first];
		}
	}
	if(par[n] && dp[n] > p[par[n]]){
		cout << -1;
		exit(0);
	}
	else if(par[n]){
		c[n] = min((long long) (w[par[n]]-1), p[par[n]]-dp[n]);
		dp[n] += w[par[n]] - c[n];
	}
	ord[n] = ++t;
	lst[t] = n;
}

priority_queue<int, vector<int>, greater<int>> dfs2(int n){
	priority_queue<int, vector<int>, greater<int>> pq;
	for(auto e : graph[n]){
		if(e.second != par[n]){
			auto q = dfs2(e.first);
			tot[n] += tot[e.first];
			if(q.size() > pq.size()){
				swap(q, pq);
			}
			while(q.size()){
				pq.push(q.top());
				q.pop();
			}
		}
	}
	//cout << n << " " << tot[n] << endl;
	while(par[n] && tot[n] > p[par[n]]){
		assert(pq.size());
		int x = pq.top();
		x = lst[x];
		pq.pop();
		//cout << tot[n] << " " << tot[n] - p[par[n]] << " " << c[x] << " " << x << "\n";		
		if(tot[n] - c[x] >= p[par[n]]){
			tot[n] -= c[x];
			w[par[x]] -= c[x];
			p[par[x]] -= c[x];
		}
		else{
			long long k = tot[n] - p[par[n]];
			tot[n] -= k;
			w[par[x]] -= k;
			p[par[x]] -= k;
			c[x] -= k;
			pq.push(ord[x]);
		}
	}
	pq.push(ord[n]);
	tot[n] += w[par[n]];
	//cout << n << " " << tot[n] << "\n";
	return pq;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		cin >> u[i] >> v[i] >> w[i] >> p[i];
		graph[u[i]].push_back({v[i], i});
		graph[v[i]].push_back({u[i], i});
	}
	dfs1(1);
	dfs2(1);
	cout << N << "\n";
	for(int i = 1; i<N; i++){
		cout << u[i] << " " << v[i] << " " << w[i] << " " << p[i] << "\n";
	}
}