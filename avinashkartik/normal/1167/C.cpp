#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 5e+5 + 5;

ll cnt[N],vis[N],visup[N];
ll n,m,k,x,u,v,ans,ct;
vector <ll> adj[N];
string s;
queue <pair<ll,ll>> q;

void dfs(ll i){
    if(!vis[i]){
        vis[i] = 1;
        ct += 1;
        for(auto it: adj[i]){
            dfs(it);
        }
    }
}

void dfsup(ll i){
    if(!visup[i]){
        visup[i] = 1;
        cnt[i] = ct;
        for(auto it: adj[i]){
            dfsup(it);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
    	cin>>x;
    	v = 0;
	    for(int j = 0; j < x; j++){
	        cin>>u;
	        if(v == 0){
	        	v = u;
	        	continue;
	        }
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	        v = u;
	    }
	}
    for(int i = 1; i <= n; i++){
        ct = 0;
        if(!vis[i]){
            dfs(i);
            dfsup(i);
        }
    }
    for(int i = 1; i <= n; i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
}