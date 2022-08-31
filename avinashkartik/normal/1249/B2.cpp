#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;

ll a[200005];
vector <ll> adj[200005];
ll vis[200005],ans[200005],vis1[200005];
ll t,n,m,u,v,ct;
pair <ll,ll> p;


void dfs(ll i){
	if(!vis[i]){
		vis[i] = 1;
		ct++;
		dfs(adj[i][0]);
	}
}

void dfs1(ll i){
	if(!vis1[i]){
		vis1[i] = 1;
		ans[i] = ct;
		dfs1(adj[i][0]);
	}
}

int main(){
	cin>>t;
	while(t--){
	    cin>>n;
	    for(int i = 1;i<=n;i++){cin>>a[i];}
	    for(int i = 1;i<=n;i++){
	    	adj[i].push_back(a[i]);
	    }

		for(int i = 1;i<=n;i++){
			if(!vis[i]){
				ct = 0;
				dfs(i);
				dfs1(i);
			}
		}

		for(int i = 1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		for(int i = 1;i<=n;i++){
			ans[i] = vis[i] = vis1[i] = 0;
			adj[i].clear();
		}
	}

}