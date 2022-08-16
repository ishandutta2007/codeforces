#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;

ll adj[403][403];
ll vis[403];
ll t,n,m,u,v;
pair <ll,ll> p;

queue <pair<ll,ll>> q;

void bfs(){
	ll v;
	p = make_pair(1,0);
	q.push(p);
	while(q.size()){
		p = q.front();
		q.pop();
		if(vis[p.first] != 1){
			vis[p.first] = 1;
			adj[1][p.first] = min(adj[1][p.second] + 1,adj[1][p.first]);
			v = p.first;
			for (int i = 1; i<=n; i++){
				if(adj[v][i] == 1){
					p = make_pair(i,v);
					q.push(p);
				}
			}
		}
	}
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
    	cin>>u>>v;
    	adj[u][v] = 1;
    	adj[v][u] = 1;
    }

	for(int i = 1;i<=n;i++){
    		for(int j = 1;j<=n;j++){
    			if(i==j) continue;
    			adj[i][j] = (adj[i][j]==1)?1:INF; 
    		}
    	}

    if(adj[1][n] == 1){
    	for(int i = 1;i<=n;i++){
    		for(int j = 1;j<=n;j++){
    			if(i==j) continue;
    			adj[i][j] = (adj[i][j]==1)?INF:1; 
    		}
    	}
    }

    bfs();
    /*
    for(int i = 1;i<=n;i++){
    	for(int j = 1;j<=n;j++){
    		cout<<adj[i][j]<<" ";
    	}
    	cout<<endl;
    }
    */
    if(adj[1][n] == INF) cout<<-1<<endl;
    else cout<<adj[1][n]<<endl;
	
}