#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
typedef long long ll; 
using namespace std;

vector <ll> adj[200005],ans[2];
ll n,m,u,v,t,vis[200005];
queue <pair<ll,ll>> q;

void bfs(){
	q.push({1,0});
	while(!q.empty()){
		ll x = q.front().first;
		ll key = q.front().second;
		q.pop();
		if(!vis[x]){
			vis[x] = 1;
			ans[key].push_back(x);
			for(auto it : adj[x]){
				q.push({it,key^1});
			}
		}
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0; i < m; i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bfs();
		ll key = 0;
		if(ans[0].size()>ans[1].size()) key = 1;
		cout<<ans[key].size()<<endl;
		for(auto it : ans[key]){
			cout<<it<<" ";
		}
		cout<<endl;
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		ans[0].clear(); ans[1].clear();
		fill_n(vis, n+1, 0);
	}
}