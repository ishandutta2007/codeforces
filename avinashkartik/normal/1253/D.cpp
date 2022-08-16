#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld; 
using namespace std;
const ll   N  =  3e+5+5;

#define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);

vector <ll> adj[N];
ll n,m,u,v,vis[N],a[N],ct=1,ans=0,maxx=0;

void dfs(ll x){
	if(!vis[x]){
		vis[x] = 1;
		a[x] = ct;
		maxx = max(maxx,x);
		for(auto it : adj[x]) dfs(it);
	}
}

int main(){
	fastio;
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
        cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
    	if(!vis[i])dfs(i);
    	for(ll j = i;j < maxx; j++){
    		if(a[j] != ct) dfs(j),ans++;
    	}
    	i = maxx;
    	maxx = 0;
    	ct++;
    }
    cout<<ans<<endl;
}